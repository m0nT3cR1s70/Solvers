#ifndef LU_HPP
#define LU_HPP

//***************************
// Librerias Necesarias
#include "Direct.hpp"
//***************************

template <class T>
class LU : public Direct
{
	private:
		// Almacena la matriz factorizada
		T lu;
		// Almacena el tiempo usado en total
		Timer timer;
	public:
		// Constructor de la clase
		LU():Direct(){cname("Factorizacion LU");};
		// Factoriza la matriz y la guarda en el mismo lugar
		void factorization(T &A);
		// Utiliza sustitucion hacia atras y hacia adelante
		void solve(Vector &x, Vector &b);
};
// Obtiene la factorizacion de una matriz
template <class T>
void LU<T> :: factorization(T &A)
{
	// Comenzamos copiando la matriz a trabajar
	lu = A;
	int j = 0;
	double m;
	double k;
	// Comenzamos con la factorizacion
	for (int i = 0; i < lu.gRow(); ++i)
	{
		for (int ind1 = 0; ind1 < lu.revDiag(i); ++ind1)
		{
			// Obtenemos el multiplicador
			j = lu.regresa(i,ind1);
			if (j < i+1) continue;
			m = lu.valor(i,ind1)/lu.busca(i,i);
			lu.insert(j,i,m);
			// Obtenemos la resta
			for (int ind = 0; ind < lu.revDiag(i); ++ind)
			{
				k = lu.regresa(i,ind);
				if(k<i+1) continue;
				lu.insert(j,k,lu.busca(j,k)-m*lu.valor(i,ind));
			}
		}
	}
}
// Obtiene la solucion de un sistema lineal
template <class T>
void LU<T> :: solve(Vector &x, Vector &b)
{
	
}
#endif // LU_HPP
