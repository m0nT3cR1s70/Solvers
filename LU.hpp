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
	// Medimos el tiempo
	timer.tic();
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
	// Finalizamos con el tiempo de ejecuccion
	timer.toc();
	// Almacenamos el tiempo
	ctime(timer.etime());
}
// Obtiene la solucion de un sistema lineal
template <class T>
void LU<T> :: solve(Vector &x, Vector &b)
{
	// Variables Necesarias
	int i = 0;
	int j = 0;
	// Numero de renglones de la matriz
	int n = lu.gRow();
	double t = 0.0;
	double s = 0.0;

	// Vector temporal y
	Vector y(n);
	// Comenzamos con el la sustitucion hacia adelante
	t = b[0]/lu.busca(0,0); 
	// Insertamos el primer valor calculado
	y[0] = t;
	// Aplicamos para los demas
	for (int i = 0; i < n; ++i)
	{
		t = b[i];
		for (int ind = 0; ind < lu.revDiag(i); ++ind)
		{
			j = lu.regresa(i,ind);
			if ( j >= i) continue;
			t -= lu.valor(i,ind)*y[j];
		}
		y[i] = t;
	}
	// Aplicamos la sustitucion hacia atras
	t = y[n-1]/lu.busca(n-1,n-1);
	x[n-1] = t;
	for (int i = n-2; i >= 0; --i)
	{
		t = y[i];
		for (int ind = 0; ind < lu.revDiag(i); ++ind)
		{
			j = lu.regresa(i,ind);
			if (j<=i||j>(n-1)) continue;
			t -= lu.valor(i,ind)*x[j];
		}
		x[i] = t/lu.busca(i,i);
	}
}
#endif // LU_HPP
