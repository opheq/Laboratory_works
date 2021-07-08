#include "Header.h"
#include <iostream>

using namespace std;

int main()
{
	Arr<int> Intarray;
	cout << "Now you have " << elements << " elements" << endl;
	Intarray.print();
	Intarray.input();
	Intarray.print();
	cout << Intarray.Summ() << endl;
	cout << Intarray.Proizvedenie();
	cout << endl;
	Arr<double> Doubarray;
	cout << "Now you have " << elements << " elements" << endl;
	Doubarray.print();
	Doubarray.input();
	Doubarray.print();
	cout << Doubarray.Summ() << endl;
	cout << Doubarray.Proizvedenie();
	cout << endl;
	
	return 0;
}