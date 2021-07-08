#include "Header.h"
#include <iostream>

using namespace std;

int main()
{
	Arr<int> Intarray;
	Intarray.input();
	Intarray.print();
	Arr<int> Intarray1;
	Intarray1.input();
	Intarray1.print();
	Intarray1==Intarray;
	Intarray1 + Intarray;
	Intarray1.print();
	return 0;
}