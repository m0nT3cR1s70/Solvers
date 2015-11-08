#ifndef CHOLESKY_HPP
#define CHOLESKY_HPP

//****************************
// Librerias Necesarias
#include "Direct.hpp"
#include <cmath>
//****************************

template <class T>
class Cholesky: public Direct
{
	private:
		// Almacena la matriz Factorizada
		T ll;
		// Tiempo usado en la factorizacion
		Timer timer;
	public:
		// Constructor de la clase
		Cholesky():Direct(){cname("Factorizacion de Cholesky");};
		// Factoriza la matriz y almacena en ll
		void factorization(T &A);
		// Utiliza sustitucion hacia atras y hacia adelante
		void solve(Vector &x, Vector &b);
};
// Factorzacion de una matriz usando cholesky
template <class T>
void Cholesky<T> :: factorization(T &A)
{
	// Variables necesarias
	double m = 0.0;
	double n = 0.0;
	double t = 0.0;
	double k = 0.0;
	int j = 0;
	// Almacenamos la matriz A en ll
	ll = A;
	int nr = ll.gRow()-1;
	// Obtenemos el primer elemento factorizado
	m = sqrt(ll.busca(0,0));
	// Almacenamos dicho elemento
	ll.insert(0,0,m);
	// Obtenemos la primera columna del algoritmo
	for (int j = 1; j <= nr; ++j) ll.insert(j,0,ll.busca(j,0)/m); 
	// Comenzamos las iteraciones
	for (int i = 1; i < nr; ++i)
	{
		m = 0.0;
		for (int ind1 = 0; ind1 < ll.revDiag(i); ++ind1)
		{
			j = ll.regresa(i,ind1);
			if (j>i-1) continue;
			t = ll.valor(i,ind1);
			m += t*t;
		}
		n = sqrt(ll.busca(i,i)-m);
		ll.insert(i,i,n);
		for (int j = i+1; j <= nr; ++j)
		{
			m = 0.0;
			for (int ind1 = 0; ind1 < ll.revDiag(j); ++ind1)
			{
				k = ll.regresa(j,ind1);
				if (k>i-1) continue;
				m += ll.valor(j,ind1)*ll.busca(i,k);
			}
			n = (ll.busca(j,i)-m)/ll.busca(i,i);
			ll.insert(j,i,n);
		}
	}
	m = 0.0;
	for (int k = 0; k < nr; ++k)
	{
		t = ll.busca(nr,k);
		m += t*t;
	}
	n = sqrt(ll.busca(nr,nr)-m);
	ll.insert(nr,nr,n);
	
	// Verificamos el resultado
	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			std::cout<<ll.busca(i,j)<<"\t";
		}
		std::cout<<std::endl;
	}
}
// Obtiene la solucion al sistema Lineal
template <class T>
void Cholesky<T> :: solve(Vector &x, Vector &b)
{

}

#endif // CHOLESKY_HPP
