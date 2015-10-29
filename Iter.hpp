#ifndef Iter_HPP
#define Iter_HPP

//********************************
// Librerias Necesarias
#include "Solvers.hpp"
//********************************

class Iter: public Solvers
{
	private:
		// Atributos compartidos por todos los Iter
		int iter;
		int iterMax;
		double tol;
		double err;
		double etimer;
		bool precond;
		std::string sname;
		std::string pname;
	public:
		// Por defecto todos los Iter tienen esta estructura
		Iter():iter(0),iterMax(2000),tol(1e-6),err(0),etimer(0),precond(false){};
		// Devuelve caracteristicas
		inline int giter(){return iter;};
		inline double gerr(){return err;};
		inline int iMax(){return iterMax;};
		inline double gtol(){return tol;};
		inline std::string snamep(){return sname;};
		// Modifica las caracteristicas
		inline void siter(int it){iterMax=it;};
		inline void ssiter(int it){iter=it;};
		inline void stol(double to){tol = to;};
		inline void serr(double er){err=er;};
		inline void cname(std::string name){sname = name;};
		inline void cpname(std::string name){pname = name;};
		inline void cprecond(bool pre){precond = pre;};
		inline void ctime(double tictoc){etimer = tictoc;};
		// Reporte de daños
		void report();
};
void Iter :: report()
{
	std::cout << sname;
	if(precond)
		std::cout << " precondicionado con "<< pname ;
	std::cout << "\n";
	std::cout << "  Iteraciones  "<< iter << std::endl;
	std::cout << "  Error "<< err << std::endl;
	std::cout << "  Tiempo de calculo "<< etimer << " [ms]" << std::endl;
}
#endif // Iter_HPP
