#include "Vector.hpp"

// Obtiene la norma de un vector
double Vector :: norm()
{
	double euclidiana;
	// Recorremos el vector y sumamos sus cuadrados
	for (int i = 0; i < n; ++i)
	{
		euclidiana += v[i]*v[i];
	}
	// Enviamos la raiz cuadrada
	return sqrt(euclidiana);
}
// Almacenamos el contenido de un vector en un archivo
void Vector :: saveData(std::string name)
{
	// Almacenar en un archivo
	std::ofstream file;
	// Nombre del archivo
	file.open(name.c_str());
	// Recorremos el vector
	for (int i = 0; i < n; ++i)
	{
		file.width(9);
		file.fill(' ');
		file.setf( std::ios::fixed, std:: ios::floatfield );
		file.precision(12);
		file << v[i] << std::endl;
	}
}
// Suma de dos vectores
Vector Vector :: operator +(Vector &o)
{
	// Temporal para almacenar la suma
	Vector tmp(v.size());
	// Verificamos que la suma sea posible
	if (o.size() != v.size())
	{
		std::cout<<"ERROR: SUMA DE VECTORES NO VALIDA: LARGOS DISTINTOS" << std::endl;
		exit(-1);
	}
	// Suma de dos vectores
	for (int i = 0; i < v.size(); ++i)
	{
		tmp[i] = v[i] + o[i];
	}
	// Devuelve el elmento
	return tmp; //(INEFICIENTE COPIA)
}
// Resta de dos vectores
Vector Vector :: operator -(Vector &o)
{
	// Temporal para almacenar la suma
	Vector tmp(v.size());
	// Verificamos que la suma sea posible
	if (o.size() != v.size())
	{
		std::cout<<"ERROR: SUBSTRACCION DE VECTORES NO VALIDA: LARGOS DISTINTOS" << std::endl;
		exit(-1);
	}
	// Suma de dos vectores
	for (int i = 0; i < v.size(); ++i)
	{
		tmp[i] = v[i] - o[i];
	}
	// Devuelve el elmento
	return tmp; // (INEFICIENTE COPIA)
}
// Producto Interno
double Vector :: operator *(Vector &o)
{
	// Temporal para almacenar la suma
	double tmp;
	// Verificamos que la suma sea posible
	if (o.size() != v.size())
	{
		std::cout<<"ERROR: SUMA DE VECTORES NO VALIDA: LARGOS DISTINTOS" << std::endl;
		exit(-1);
	}
	// Suma de dos vectores
	for (int i = 0; i < v.size(); ++i)
	{
		tmp += v[i]*o[i];
	}
	// Devuelve el elmento
	return tmp; //(INEFICIENTE COPIA)
}
// Producto de un escalar por un vector
Vector operator *(double escalar, Vector const &o)
{
	// Largo del vector
	int n = o.n;
	// Vector temporal para almacenar el vector
	Vector tmp(n);
	// Realizamos la multiplicacion
	for (int i = 0; i < n; ++i)
	{
		tmp[i] = escalar * o[i];
	}
	// Devolvemos el vector multiplicado
	return tmp;
}
// Inicializamos un vector con un escalar
void Vector :: operator =(double escalar)
{
	// Inicializamos con un valor
	for (int i = 0; i < v.size(); ++i)
	{
		v[i] = escalar;
	}
}
// Asignamos el contenido de un vector a otro vector
void Vector :: operator =(Vector const &o)
{
	if (v.size() != o.n)
	{
		std::cout<<"ERROR: COPIA DE VECTORES NO VALIDA: LARGOS DISTINTOS" << std::endl;
	}
	// Copiamos el contenido de o a v
	for (int i = 0; i < v.size(); ++i)
	{
		v[i] = o[i];
	}
}