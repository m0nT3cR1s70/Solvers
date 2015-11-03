#include "Dense.hpp"
// Solicitamos memoria para almacenar los datos
void Dense :: reserveMemory()
{
	// Solicitamos espacio para los renglones
	Mtx = new double*[gRow()];
	// Verificamos que el espacio fue asignado
	if (Mtx == nullptr)
	{
		std::cout<<"ERROR: ESPACIO NO ASIGNADO:Dense: "<<std::endl;
		exit(-1);
	}
	// Si fue asignado el espacio entonces asignamos espacio para las columnas
	for (int i = 0; i < gRow(); ++i)
	{
		Mtx[i] = new double[gCol()];
	}
}
// Insertamos un elemento en la posicion solicitada
void Dense :: insert(int i, int j, double val)
{
	// Verificamos que el dato se encuentre en el rango
	if ((i < 0 || i >= gRow()) || (j < 0 || j>=gCol()))
	{
		std::cout<<"ERROR: NO SE PUEDE INSERTAR FUERA DE RANGO"<<std::endl;
		exit(-1);
	}
	// Si esta dentro de los limites entonces
	Mtx[i][j] = val;
}
// Inicializamos en 0 todos los elementos de la matriz
void Dense :: zeros()
{
	for (int i = 0; i < gRow(); ++i)
	{
		for (int j = 0; j < gCol(); ++j)
		{
			Mtx[i][j] = 0.0;
		}
	}
}
// Devuelve un elemento en la posicion solicitada
double Dense :: busca(int i, int j)
{
	// Verificamos que el dato se encuentre en el rango
	if ((i < 0 || i >= gRow()) || (j < 0 || j>=gCol()))
	{
		std::cout<<"ERROR: NO SE PUEDE INSERTAR FUERA DE RANGO"<<std::endl;
		exit(-1);
	}
	// Si esta dentro de los limites entonces
	return Mtx[i][j];
}
// Devuelve un elemento en la posicion solicitada
double Dense :: operator ()(int i, int j)
{
	// Verificamos que el dato se encuentre en el rango
	if ((i < 0 || i >= gRow()) || (j < 0 || j>=gCol()))
	{
		std::cout<<"ERROR: NO SE PUEDE INSERTAR FUERA DE RANGO"<<std::endl;
		exit(-1);
	}
	// Si esta dentro de los limites entonces
	return Mtx[i][j];
}
// Imprime en pantalla su forma de almacenamiento
void Dense :: print()
{
	for (int i = 0; i < gRow(); ++i)
	{
		for (int j = 0; j < gCol(); ++j)
		{
			std::cout<<Mtx[i][j]<<"\t";
		}
		std::cout<<std::endl;
	}
}
// Obtiene la multiplicacion Matriz-Vector
Vector Dense :: operator *(Vector const &v)
{
	// Variables Necesarias
	int n = v.n;
	Vector tmp(n);
	// Revisamos que la operacion sea conformable
	if (n != gCol())
	{
		std::cout<<"ERROR: ORDENES DIFERENTES: MULTIPLICACION MATRIZ-VECTOR NO CONFORMABLE"<<std::endl;
		exit(-1);
	}
	// Si la operacion es conformable entonces
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			tmp[i] = tmp[i] + Mtx[i][j]*v[j];
		}
	}
	// Devolvemos el vector resultante
	return tmp;
}
// Iteracion de Jacobi
void Dense :: iterJacobi(int i, Vector &x)
{

}
// Iteracion de Gauss-Seidel
void Dense :: iterGaussSeidel(int i, Vector &x, Vector const &b)
{

}
// Libera memoria solicitada 
void Dense :: freeMemory()
{
	for (int i = 0; i < gRow(); ++i)
	{
		delete [] Mtx[i];
	}
		// Liberamos por completo Mtx
	if (Mtx != nullptr)
	{
		delete [] Mtx;
	}
}