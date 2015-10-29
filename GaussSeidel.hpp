#ifndef GAUSS_SEIDEL_HPP
#define GAUSS_SEIDEL_HPP

//-------------------------------
// Librerias Necesarias
#include "Iter.hpp"
//-------------------------------

class GaussSeidel : public Iter
{
	private:
		Timer timer;
	public:
		// Constructor de la clase
		GaussSeidel() : Iter(){cname("Gauss");cprecond(false);};
		// Funcion para desarrollar GaussSeidel
		template<class T>
		void solve(T &A, Vector &x, Vector const &b);
};
#include "Gauss_imp.hpp"


#endif // GAUSS_SEIDEL_HPP
