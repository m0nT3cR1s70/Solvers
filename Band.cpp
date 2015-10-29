#include "Band.hpp"

// Reservamos la memoria necesitada
void Band :: reserveMemory()
{
	// Solicitamos el espacio necesario 
	data = new double *[gRow()];
	// Verificamos que se asignaran los renglones necesarios
	if (data == nullptr)
	{
		std::cout<<"ERROR: ESPACIO NO ASIGNADO: data: Band"<<std::endl;
		exit(-1);
	}
	// Solicitamos espacio para las columas necesarias
	for (int i = 0; i < gRow(); ++i)
	{
		data[i] = new double[gBand()];
	}
	// Solicitamos espacio para el vector de indices
	ind = new int[gBand()];
	// Verificamos que el espacio fue asignado
	if (ind == nullptr)
	{
		std::cout<<"ERROR: ESPACIO NO ASIGNADO: ind: Band"<<std::endl;
	}
}
// Insertamos un elemento en la matriz
void Band :: insert(int i, int j, double val)
{
	// Obtenemos el indice del arreglo
	int k = j - i;
	bool here = false;
	// Si el dato es distinto de cero lo almacenamos
	if (val != 0)
	{
		// Recorremos el arreglo buscando la columna en donde pertenece
		for (int l = 0; l < gBand(); ++l)
		{
			if (ind[l] == k)
			{
				data[i][l] = val;
				here = true;
				break;
			}
		}
		// 	Si no esta en ninguna columa entonces se agrega una nueva
		if (!here)
		{
			for (int l = 0; l < gBand(); ++l)
			{
				if (ind[l] == -1000)
				{
					// Almacenamos la nueva banda
					ind[l] = k;
					// Almacenamos el nuevo dato
					data[i][l] = val;
					// Terminamos el ciclo
					break;
				}
			}
		}
	}
}
// Inicializamos la matriz con 0's y el arreglo con -1
void Band :: zeros()
{
	if (data == nullptr || ind == nullptr)
	{
		std::cout<<"ERROR: NO HAY MEMORIA ASIGNADA: zeros"<<std::endl;
		exit(-1);
	}
	// Si hay memoria entonces
	for (int i = 0; i < gRow(); ++i)
	{
		for (int j = 0; j < gBand(); ++j)
		{
			data[i][j] = 0.0;
			// Asignamos -1000 al vector
			if (i == 0)
			{
				ind[j] = -1000;
			}
		}
	}
}
// Sobrecarga del operador (), obtiene un elemento de data
double  Band :: operator ()(int i, int j)
{
	// Obtenemos el indice 
	int k = j - i;
	double val = 0.0;
	// Recorremos el arreglo de indices en busca del arreglo
	for (int l = 0; l < gBand(); ++l)
	{
		if (ind[l] == k)
		{
			val = data[i][l];
		}
	}

	// Regresamos el valor
	return val;
}
// Sobrecarga del operador (), obtiene un elemento de data
double  Band :: busca(int i, int j)
{
	// Obtenemos el indice 
	int k = j - i;
	double val = 0.0;
	// Recorremos el arreglo de indices en busca del arreglo
	for (int l = 0; l < gBand(); ++l)
	{
		if (ind[l] == k)
		{
			val = data[i][l];
		}
	}

	// Regresamos el valor
	return val;
}
// Multiplicacion de una matriz por un vector
Vector Band :: operator *(Vector const &v)
{
	int n = v.n;
	double suma = 0.0;
	int row = gRow();
	// Vector temporal para la asignacion de un elemento
	Vector tmp(n);
	// Verificamos que sean conformables
	if (n != row)
	{
		std::cout<<"ERROR: OPERACION NO CONFORMABLE VERIFICA LOS INDICES" << std::endl;
		exit(-1);
	}
	// Realizamos la multiplicacion Matriz Vector
	for (int i = 0; i < row; ++i)
	{
		suma = 0.0;
		for (int k = 0; k < gBand(); ++k)
		{
			if (((ind[k]+i) >= 0 )&& ((ind[k]+i) < row) )
			{
				suma += data[i][k]*v[ind[k]+i];
			}
		}
		tmp[i] = suma;
	}
	// Devolvemos el vector
	return tmp;
}
// Imprime en forma de CDS
void Band :: print()
{
	std::cout<<"El contenido de los arreglos es: " << std::endl;
	std::cout<<"Data: "<<std::endl;
	for (int i = 0; i < gRow(); ++i)
	{
		for (int j = 0; j < gBand(); ++j)
		{
			std::cout<<data[i][j]<<"\t";
		}
		std::cout<<std::endl;
	}
	std::cout<<"indices"<<std::endl;
	for (int i = 0; i < gBand(); ++i)
	{
		std::cout<<ind[i]<<", ";
	}
}
// Imprime en forma de Matriz
void Band :: printM(int n)
{
    for (int i = 0; i < n; ++i)
    {
    	for (int j = 0; j < n; ++j)
    	{
    		std::cout<<(i,j)<<"\t";
    	}
    	std::cout<<std::endl;
    }
}
// Inidica en el arreglo donde cambia el renglon
int Band :: revDiag(int prow)
{
	int k = 0;
	for (int i = 0; i < gBand(); ++i)
	{
		if((ind[i]+prow) >= 0 && (ind[i]+prow) < gCol()) k++;
	}
	return k;
}
// PRUEBAAAAAA
int Band :: regresa(int prow, int inf)
{
	int i,k = 0;
	for (i = 0; i < gBand(); ++i)
	{
		if ((ind[i]+prow) >= 0 && (ind[i]+prow) < gCol())
		{
			if (k == inf) return (ind[i]+prow);
			k++;
		}
	}
	return (ind[i]+prow);
}
// Iteracion de Jacobi
void Band :: iterJacobi(int i, Vector &x)
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
void Band :: iterGauss(int i, Vector &x, Vector const &b)
{
	
}
// Liberamos utilizada memoria
void Band :: freeMemory() 
{
	// Liberamos data
	for (int i = 0; i < gRow(); ++i)
	{
		delete [] data[i];
	}
	// Liberamos por completo data
	if (data != nullptr)
	{
		delete [] data;
	}
	// Liberamos el vector de indices
	if (ind != nullptr)
	{
		delete [] ind;
	}
}