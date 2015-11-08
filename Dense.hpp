#ifndef DENSE_HPP
#define DENSE_HPP

//**********************
// Librerias Necesarias
#include "Matrix.hpp"
//**********************

class Dense : public Matrix
{
	private:
		// Arreglo para almacenar los datos
		double **Mtx;
		// Funciones para el manejo de memoria
		void reserveMemory();
		void freeMemory();
	public:	
		// Constructor vacio de la clase
		Dense(){};
		// Constructor de la clase
		Dense(int orden, std::string pname): Matrix(orden, orden, orden, pname){reserveMemory();zeros();};
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
		// Realiza una iteracion de Jacobi para este formato
		void iterJacobi(int i, Vector &x);
		// Realiza una iteracion de Gauss-Seidel para este formato
		void iterGaussSeidel(int i, Vector &x, Vector const &b);
		// Destructor de la clase
		~Dense(){freeMemory();};
	
};

#endif // DENSE_HPP
