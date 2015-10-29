#ifndef JACOBI_HPP
#define JACOBI_HPP

//*********************************
// Librerias Necesarias
#include "Iter.hpp"
//*********************************

class Jacobi : public Iter
{
	private:
		Timer timer;
	public:
	// Constructor de la clase
	Jacobi() : Iter(){cname("Jacobi");cprecond(false);};
	template <class T>
	void solve(T &A, Vector &x, Vector &b);
};
#include "Jacobi_imp.hpp"

#endif // JACOBI_HPP
