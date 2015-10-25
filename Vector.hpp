#ifndef VECTOR_HPP
#define VECTOR_HPP

//---------------------------------
// Librerias Necesarias
#include <iostream>
#include <Vector>
#include <fstream>
#include <cmath>
#include <string>
//---------------------------------

class Vector
{
	private:
		// Vector de datos
		std::vector<double> v;
	public:
		// Largo del vector
		int n;
	public:
		// Constructor vacio
		Vector():v(0){};
		Vector(int m):n(m),v(m,0){};
		// Orden del vector
		inline int size(){return n;};
		// Obtiene la norma de un vector
		double norm();
		// Almacena el contenido de un vector en un archivo
		void saveData(std::string name);
		// Muestra en pantalla el contenido de un vector
		void print(){for (int i = 0; i < n; ++i) std::cout<<v[i]<<std::endl;};
		// Inserta un elemento
		double &operator[](int i){return v[i];}
		// Devuelve un elemento
		double operator [](int i) const {return v[i];};
		// Operaciones Vectoriales Necesarias
		// Suma de dos vectores
		Vector operator +(Vector &o);
		// Resta de dos vectores
		Vector operator -(Vector &o);
		// Producto interno
		double operator *(Vector &o);
		// Escalar por vector
		friend Vector operator *(double escalar,Vector const &o);
		// Sobrecarga del operador igual
		void operator = (double escalar);
		// Copia un vector a otro
		void operator = (Vector const &o);
};


#endif // VECTOR_HPP

