#ifndef BAND_HPP
#define BAND_HPP
//---------------------------------
// Librerias Necesarias
#include <iostream>
#include <string>
#include "Matrix.hpp"
//---------------------------------


class Band : public Matrix
{
	private:
		// Arreglos Necesarios
		double **data;
		int *ind;
		// Funciones Necesarias
		void reserveMemory();
		void freeMemory();
	public:
		// Constructor de la clase
		Band(int orden,int pband, std::string pname): Matrix(orden, orden, pband, pname){reserveMemory();zeros();};
		// Almacena un valor dentro de la clase
		void insert(int i, int j, double val);
		// Inicializamos en 0 y en -1000
		void zeros();
		// Obtiene un elemento de la matrix
		double busca(int i, int j);
		// Obtiene un elemento de la matrix
		double operator ()(int i, int j);
		// Obtiene la multiplicacion Matriz-Vector
		Vector operator *(Vector const &v);
		// Imprime en su forma de almacenamiento
		void print();
		// Imprime en forma de Matrix
		void printM(int n);
		// Revisa Diagonal
		int revDiag(int prow);
		//PRUEBA
		int regresa(int prow, int inf);
		// Realiza una iteracion de Jacobi para este formato
		void iterJacobi(int i, Vector &x);
		// Realiza una iteracion de Gauss-Seidel para este formato
		void iterGauss(int i, Vector &x, Vector const &b);
		// Almacena una matriz en otra con este formato
		//void operator =(Matrix const &Mtx);
		// Destructor de la clase
		~Band(){freeMemory();};
};

#endif // BAND_HPP
