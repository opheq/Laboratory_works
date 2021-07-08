#pragma once
#include <list>
#include <string>
using namespace std;

class Person //Абстрактный класс
{
protected:
	string name;
public:
	Person();
	Person(string x);
	~Person();
	string GetName();
	void SetName();
	static void show_all();
	virtual void Show()=0;
	static std::list<Person*> lst;
	virtual void add() = 0;
};

class Soldier : public Person
{
protected:
	int Medals_count;
	int Howlong;
public:
	Soldier();
	Soldier(int, int);
	~Soldier();
	int GetMedals_count();
	int GetHowlong();
	void Show();
	void SetMedals_count();
	void SetHowlong();
	void add();
};

class Worker : public Person
{
protected:
	int Salary;
	string Product;
public:
	Worker();
	~Worker();
	Worker(int, string);
	int GetSalary();
	string GetProduct();
	void Show();
	void SetSalary();
	void SetProduct();
	void add();
};

class Engineer : public Person
{
protected:
	string Engineer_type;
	int HowmuchInnovations;
public:
	Engineer();
	Engineer(string, int);
	~Engineer();
	string GetEngineer_type();
	int GetHowmuchInnovations();
	void Show();
	void SetEngineer_type();
	void SetHowmuchInnovations();
	void add();
};
