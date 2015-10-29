template <class T>
void GaussSeidel :: solve(T &A, Vector &x, Vector const &b)
{
	// Variables necesarias
	int n = x.size();
	// Comenzamos con la medicion del tiempo
	timer.tic();
	for (int k = 0; k < iMax(); ++k)
	{
		for (int i = 0; i < n; ++i)
		{
			A.iterGaussSeidel(i,x,b);
		}
	}
	// Finaliza la medicion del tiempo
	timer.toc();
	// Almacenamos el tiempo
	ctime(timer.etime());
}