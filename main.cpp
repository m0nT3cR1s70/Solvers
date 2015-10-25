#include <iostream>
#include "Vector.hpp"
using namespace std;

int main(int argc, char const *argv[])
{
	int n = 5;
	Vector a(n),b(n),c(n);
	a[0]=1.243;
	b = a;
	b[1] = 32.3;
	c = a-b;
	double g = a*b;
	cout << g << endl;
	cout << "----" << endl;
	c.print();
	c = 0.1*a;
	c.print();
	c.saveData("save.dat");
	/* code */
	return 0;
}
