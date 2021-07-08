#include "Header.h"
#include <iostream>
#include <list>

using namespace std;


int main()
{
	Soldier one;
	Engineer two;
	one.SetName();
	two.SetName();
	Person::show_all();
	one.SetMedals_count();
	Person::show_all();
	system("pause");
	return 0;
}