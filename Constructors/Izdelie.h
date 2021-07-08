#pragma once
using namespace std;
class Izdelie
{
private:
	char* name;
	char* code;
	int count;
public:
	Izdelie();
	Izdelie(char*, char*, int);
	Izdelie(const Izdelie&);
	~Izdelie();
	char* Getname();
	char* Getcode();
	int Getcount();
	void Setname(char*);
	void Setcode(char*);
	void Setcount(int);
	void Set(char*, char*, int);
	void Show();
	void Checkcount(Izdelie y);
	void IsNull();
};
