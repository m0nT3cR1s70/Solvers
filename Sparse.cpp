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
// Inicializamos los arreglos con ceros
void Sparse :: zeros()
{
	for (int i = 0; i < gRow(); ++i)
	{
		for (int j = 0; j < gBand(); ++j)
		{
			data[i][j]=0.0;
			ind[i][j]=0;
		}
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