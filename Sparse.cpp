#include "Sparse.hpp"

// Solicitamos memoria para el almacenamiento de la matriz
void Sparse :: reserveMemory()
{
	// Solicitamos espacio para data
	data = new double*[gRow()];
	// Verificamos que la asignacion fue un exito
	if (data == nullptr)
	{
		std::cout<<"ERROR: ASIGNACION DE MEMORIA NO VALIDA: DATA: Sparse" << std::endl;
		gName();
		exit(-1);
	}
	// Si es valida entonces asignamos a cada renglon pband columnas
	for (int i = 0; i < gRow(); ++i)
	{
		data[i] = new double[gBand()];
	}
	// Solicitamos espacio para ind
	ind = new int*[gRow()];
	// Verificamos que la asigancion fue un exito
	if (ind == nullptr)
	{
		std::cout<<"ERROR: ASIGNACION DE MEMORIA NO VALIDA: IND: Sparse" <<std::endl;
		gName();
		exit(-1);
	}
	// Si es validad entonces a cada renglon asignamos pband columnas
	for (int i = 0; i < gRow(); ++i)
	{
		ind[i] = new int[gBand()];
	}
}
// Insertamos en memoria un elemento 
void Sparse :: insert(int i, int j, double val)
{
	// Variables Necesarias
	int k = 0;
	// Insertamos en la posicion solicitada
	if ( val == 0.0)
	{
		k = 0;
		// Buscamos
		while(k < gBand()) 
		{
			if (ind[i][k] == -1) break; 
			// En otro caso
			if (ind[i][k] == j)
			{
				// Reacomodando
				for (int l = k+1; l < gBand(); ++l)
				{
				 	data[i][l-1] = data[i][l];
				 	ind[i][l-1] = ind[i][l];
				} 
				data[i][gBand()-1]=0.0;
				ind[i][gBand()-1]=-1;
				return;	
			} 
			k++;
		}
		return;	
	}
	else
	{
		k = 0;
		// Buscamos un espacio disponible en la banda
		while(ind[i][k] != -1 && k < gBand())	 
		{
		    if (ind[i][k] == j)
		    {
		    	// Asigamos un valor
		    	data[i][k] = val;
		    	// Terminamos
		    	return;
		    }
		    k++;
		}
		// Insertamos el primer elemento no-cero
		data[i][k] = val;
		ind[i][k] = j;
	}
}
// Inicializamos los arreglos con ceros
void Sparse :: zeros()
{
	for (int i = 0; i < gRow(); ++i)
	{
		for (int j = 0; j < gBand(); ++j)
		{
			data[i][j]=0.0;
			ind[i][j]= -1;
		}
	}
}
// Devuelve un valor de la matriz
double Sparse :: operator ()(int i, int j)
{
	// Variables necesarias
	double val = 0.0;
	for (int l = 0; l < gBand(); ++l)
	{
		if (ind[i][l] == j)
		{
			val = data[i][l];
			break;
		}
	}
	// Devolvemos el valor
	return val;
}
// Devuelve un valor de la matriz
double Sparse :: busca(int i, int j)
{
	// Variables necesarias
	double val = 0.0;
	for (int l = 0; l < gBand(); ++l)
	{
		if (ind[i][l] == j)
		{
			val = data[i][l];
			break;
		}
	}
	// Devolvemos el valor
	return val;	
}
int Sparse :: revDiag(int i)
{
	// Variables necesarias
	int k = 0;
	if (data[i] == nullptr) return k;
	// Devuelve el largo de la banda
	while(k < gBand()) {
	    if (ind[i][k] == -1) break;
	    k++;
	}
	return k;
}
// Prueba
int Sparse :: regresa(int i, int j)
{
	return ind[i][j];
}
// Iteracion de Jacobi
void Sparse :: iterJacobi(int i, Vector &x)
{
	// Variables utiles
	int j = 0;
	//double suma = 0.0;
	// Comenzamos con la solucion
	for (int l = 0; l < revDiag(i); ++l)
	{
		j=regresa(i,l);
		if (i != j)
		{
			x[i]=x[i]-busca(i,j)*x[j];
		}
	}
	x[i] = x[i]/busca(i,i);
}
// Iteracion de Gauss-Seidel
void Sparse :: iterGaussSeidel(int i, Vector &x, Vector const &b)
{
	// Variables utiles
	int j = 0;
	double suma = 0.0;
	// Comenzamos con la solucion
	for (int l = 0; l < revDiag(i); ++l)
	{
		j=regresa(i,l);
		if (i != j)
		{
			suma+=busca(i,j)*x[j];
		}
	}
	x[i] = (b[i]-suma)/busca(i,i);
}
// Operacion Matriz - Vector
Vector Sparse :: operator *(Vector const &v)
{
	// Vector temporal 
	Vector tmp(v.n);
	double s = 0.0;
	int k = 0;
	for (int i = 0; i < gRow(); ++i)
	{
		s = 0.0;
		k = 0;
		while(ind[i][k] != -1) 
		{
		    s += data[i][k]*v[ind[i][k]];
		    k++;
		    if(k >= gBand()) break;
		}
		tmp[i] = s;
	}
	// Devolvemos el resultado
	return tmp;
}
// Imprime en su esquema de almacenamiento
void Sparse :: print()
{
	std::cout<<" ELEMENTOS NO CERO " << std::endl;
	for (int i = 0; i < gRow(); ++i)
	{
		for (int j = 0; j < gBand(); ++j)
		{
			std::cout<<data[i][j]<<"\t";
		}
		std::cout<<std::endl;
	}
	std::cout<<" INDICES DE ELEMENTOS NO CERO"<<std::endl;
	for (int i = 0; i < gRow(); ++i)
	{
		for (int j = 0; j < gBand(); ++j)
		{
			std::cout<<ind[i][j]<<"\t";
		}
		std::cout<<std::endl;
	}

}
// Liberamos la memoria solicitada
void Sparse :: freeMemory()
{
	for (int i = 0; i < gRow(); ++i)
	{
		delete [] data[i];
		delete [] ind[i];
	}
	// Liberamos por completo los arreglos
	delete [] data;
	delete [] ind;
}