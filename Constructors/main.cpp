#include "Izdelie.h"
#include <iostream>
using namespace std;
//Функция для вызова конструктора копирования
void ShowWork(Izdelie x)
{
	x.Show();
}
//Функция для вызова конструктора копирования
Izdelie Returnobject()
{
	Izdelie x;
	return x;
}
int main()
{
	//Объекты статической в статической памяти
	Izdelie detail1; 
	Izdelie detail2((char*)"detail2", (char*)"0GDJ3", 12);
	Izdelie detail3(detail2);
	Izdelie detail456[3] = { Izdelie(), Izdelie((char*)"detail5", (char*)"91924", 15), Izdelie()};
	detail456[2].Setname((char*)"detail6");
	detail456[2].Setcode((char*)"9D0A1");
	//Объект в динамической памяти
	Izdelie* detail7 = new Izdelie();
	detail7->Set((char*)"detail7", (char*)"G9Z94", 0);
	detail7->Show();
	for (int i = 0; i < 3; i++)
	{
		detail456[i].Show();
	}
	ShowWork(detail2);
	detail3.Setname((char*)"newdetail");
	detail2.Checkcount(detail3);
	detail2.IsNull();
	detail7->IsNull();
	Returnobject();
	delete(detail7);
	system("pause");
	return(0);
}