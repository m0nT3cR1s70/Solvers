#include <iostream>
#include "Vector.hpp"
#include "Band.hpp"
#include "Sparse.hpp"
#include "Solvers.hpp"
#include "CG.hpp"
#include "Jacobi.hpp"
#include "GaussSeidel.hpp"
#include "BICGSTAB.hpp"
using namespace std;

int main(int argc, char const *argv[])
{
	int nx=9001;
  	int ny=nx;
  	double dx = 1./nx;
  	double dy = 1./ny;
  	int n = (nx - 1)*(ny - 1); // dimension del sistema a resolver
  	Vector x(n),b(n),r(n);         //vectores: solucion, lado derecho, residual  
  	Jacobi jac;
  	GaussSeidel gs; 
  	CG cg;

  	Timer timer;                   //mide tiempo de ejecucion

  	cout<< endl << "Tamanio de problema " << n << "x" <<n<<endl<<endl;
  	int l = 0;
    Band Acoo(n,5,"banda");                 //matriz temporal en formato de coordenadas
    timer.tic(); 
    for(int j=1;j<ny;++j)
    {
      for(int i=1;i<nx;++i)
      {
        // prototipo de funcion de insertar void insert(int i,int j,doble val);
        if(j>1)
          Acoo.insert(l, l-(nx-1),-1.);      
        if(i>1)
          Acoo.insert(l, l-1,-1.);
          Acoo.insert(l, l,4.);
        if(i<nx-1)
          Acoo.insert(l, l+1,-1.);
        if(j<ny-1)
          Acoo.insert(l, l+(ny-1),-1.);
          ++l;
      }
    }
    timer.toc();                 //termina de medir tiempo
    std::cout << "Tiempo de llenado de matriz   CDS: " << timer.etime() << " ms" << std::endl;
    
    /*for (int i = 0; i < n; ++i)
    {
    	for (int j = 0; j < n; ++j)
    	{
    		std::cout<<Acoo(i,j)<<"\t";
    	}
    	std::cout<<std::endl;
    }*/
    //Acoo.print();
    b = 1.*dx*dx;


	/*    JACOBI     */
  	cout<< endl << endl;
  	x=0;                           //aproximacion inicial de la solucion
  	jac.solve(Acoo,x,b);              //resuelve el sistema Ax=b, guarda el resultado en x
  	jac.report();                  //reporta numero de iteraciones y tiempo de ejecucion
 	x.saveData("jac.txt");
  	r = b-Acoo*x;                     //calcula el vector residual con la solucion x. 
                                  //Operacion vector = vector - Matroz*vector
  	cout << "#Error ||b-A*x||: " << r.norm() << endl;  //imprime la norma del vector residual

  	/*    Gauss Seidel     */
  	cout<< endl << endl;
  	x=0;
  	gs.solve(Acoo,x,b);
  	gs.report();
  	x.saveData("gauss.txt");
  	r = b-Acoo*x;
  	cout << "#Error ||b-A*x||: " << r.norm() << endl;
  
	//    Gradiente Conjugado   
  	cout<< endl << endl;
  	x=0;
  	cg.solve(Acoo,x,b);
  	cg.report();
  	r = b-Acoo*x;
  	x.saveData("cg.txt");
  	cout << "#Error ||b-A*x||: " << r.norm() << endl;
	/* code */
	return 0;
}
