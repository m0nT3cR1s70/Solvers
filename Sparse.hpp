#ifndef SPARSE_HPP
#define SPARSE_HPP

//-----------------------
// Librerias Necesarias
#include <iostream>
#include <string>
#include "Matrix.hpp"
//-----------------------

class Sparse : public Matrix
{
	private:
		// Arreglos para almacenar los datos
		double **data;
		int **ind;
		// Funciones privadas
		void reserveMemory();
		void freeMemory();
	public:
		// Constructor de la clase
		Sparse(int orden,int pband, std::string pname): Matrix(orden, orden, pband, pname){reserveMemory();zeros();};
		// Inserta un valor no cero en el arreglo
		void insert(int i, int j, double val);
		// Inicializa los arreglos a zeros
		void zeros();
		// Obtiene un elemento de la matriz
		double operator()(int i, int j);
		// Multiplicaccion Matriz-Vector
		Vector operator*(Vector const &v);
		// Imprime en su esquema de almacenamiento
		void print();
		// Iteracion de Jacobi
		void iterJacobi(int i, Vector &x);
		// Iteracion de Gauss-Seidel
		void iterGaussSeidel(int i, Vector &x, Vector const &b);
		// Destructor de la clase
		~Sparse(){freeMemory();};
};

#endif // SPARSE_HPP
