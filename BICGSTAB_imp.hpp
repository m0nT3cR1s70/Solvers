template<class T>
void  BICGSTAB :: solve(T &A, Vector &x, Vector &b)
{
   timer.tic();
   double tol2 = gtol()*gtol();
   int n = x.size();
   Vector r(n);
   Vector ra(n);
   Vector p(n);
   Vector v(n);
   Vector Ap(n);
   Vector s(n);
   Vector t(n);
   Vector ro(n);
   double alpha;
   double beta;
   double omega;
   double ro0;
   double merror;
   double ss;
   int k;
   
   // Inicializamos lo pedido
   r = b - A*x;   //Calculamos el residual
   ra = r;      // r arbitraria
   p = 0;        //p0
   v = 0;      //v0
   ro[0] = 1;     //ro
   alpha = 1;  //alpha
   omega = 1;  //omega
   for(k =1; k<iMax(); ++k)
   {
      ro[k] = ra*r;
      beta = (ro[k]/ro[k-1]) * (alpha/omega);
      p = r + beta*(p-omega*v);
      v = A*p;
      alpha = ro[k]/(ra*v);
      s = r - alpha*v;
      t = A*s;
      omega = (t*s)/(t*t);
      x = x + alpha*p + omega*s;
      ss = s*s;
      merror = ss;
      if(merror < tol2)
         break;
      r = s - omega*t;
   }
   // Almacenamos el numero de iteraciones 
   ssiter(k+1);
   // Almacenamos el error obtenido
   serr(sqrt(merror));
   // Finalizamos con el tiempo de ejecuccion
   timer.toc();
   // Almacenamos el tiempo 
   ctime(timer.etime());
   // Sin precondicionamiento
   cprecond(false);
}