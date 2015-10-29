template <class T>
void Jacobi :: solve(T &A, Vector &x, Vector &b)
{
	// Variables necesarias
	int n = x.size();
	int k = 0;
	// Medimos el tiempo
	timer.tic();
	// Aplicamos el metodo de Jacobi
	for (k = 0; k < iMax(); ++k)
	{
		for (int i = 0; i < n; ++i)
		{
			x[i] = b[i];
			A.iterJacobi(i,x);
		}
	}
	// Terminamos de medir el tiempo
	timer.toc();
	// Almacenamos el tiempo 
	ctime(timer.etime());
	// Almacenamos el numero de iteraciones
	ssiter(k);
}