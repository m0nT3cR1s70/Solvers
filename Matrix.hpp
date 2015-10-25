#ifndef MATRIX_HPP
#define MATRIX_HPP

//---------------------------------
// Librerias Necesarias
#include <iostream>
#include <string>
//---------------------------------

class Matrix
{
	private:
		// Caracteristicas de la matriz
		int row;
		int col;
		int band;
		std::string name;
	public:
		// Constructor de la clase
		Matrix():row(0),col(0),band(0){};
		Matrix(int prow, int pcol, int pband, std::string pname):row(prow),col(pcol),band(pband),name(pname){};
		// Funciones para devolver parametros de la matrix
		inline int gRow(){return row;};
		inline int gCol(){return col;};
		inline int gband(){return band;};
		// Indica el nombre de la matrix
		inline void gName(){std::cout<<name<<std::endl;};
		// -----------------------------------------------------------
		// Funciones puramente virtuales
		virtual void insert(int i, int j, double val)=0;
		// Funcion para obtener un elemento
		virtual double operator ()(int i, int j = 0;
		// Funcion para la multiplicacion matrix vector
		virtual Matrix operator *(Vector const &v) = 0;
		// Iteracion de Jacobi
		virtual void iterJacobi(int i, Vector &x) = 0;
		// Iteracion de Gauss-Seidel
		virtual void iterGauss(int i, Vector &x, Vector const &b) = 0;
		// Sobrecargamos el operador =
		virtual void operator =(Matrix const &Mtx)
		// -----------------------------------------------------------
};


#endif // MATRIX_HPP
