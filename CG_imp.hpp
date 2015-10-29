template<class T>
void CG :: solve(T &A, Vector &x, Vector &b)
{
   // Comenzamos midiendo el tiempo
   timer.tic();
   // Variables utiles en la ejecuccion
   double tol2 = gtol()*gtol();
   int n = x.size();
   // Vectores necesarios
   Vector r(n), p(n), Ap(n);
   // Variables
   double alpha;
   double beta;
   double merror;
   double rr0,rr;
   int k;
   // Comenzamos con el gradiente conjugado
   r = b-A*x;
   rr0 = r*r;
   p=r;
   for(k =0;k<iMax();++k)
   {
      Ap = A*p;
      alpha =  (rr0) / (Ap*p);
      x = x + alpha*p;
      r = r - alpha*Ap;
      rr = r*r;
      merror = rr;
      if(merror < tol2)
         break;
      beta = rr / rr0; 
      p = r + beta*p;
      rr0 = rr;
   }
   // Almacenamos el numero de iteraciones 
   ssiter(k+1);
   // Almacenamos el error obtenido
   serr(sqrt(merror));
   // Finalizamos con el tiempo de ejecuccion
   timer.toc();
   // Almacenamos el tiempo 
   ctime(timer.etime());
   cprecond(false);
}