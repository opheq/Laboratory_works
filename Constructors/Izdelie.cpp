#include "Izdelie.h"
#include <iostream>
#include <string>
using namespace std;
	//DEFAULT CONSTRUCT
	Izdelie::Izdelie(){
		this->name = (char*)"noname"; //������ �������� �� ���������
		this->code = (char*)"nocode";
		this->count = 0;
		cout << "You called DEFAULT CONSTRUCT for object " << this << endl;
	}
	//CONSTRUCT WITH PARAMETERS
	Izdelie::Izdelie(char* x, char* y, int z) {
		this->name = x; //������ �������� �� ����������
		this->code = y;
		this->count = z;
		cout << "You called CONSTRUCT WITH PARAMETERS for object " << this << endl;
	}
	//COPY CONSTRUCT
	Izdelie::Izdelie(const Izdelie&x) {
		this->name = x.name; //�������� �������� ��������
		this->code = x.code; //�������
		this->count = x.count;
		cout << "You called COPY CONSTRUCT for object " << this << endl;
	}
	//DESTRUCT
	Izdelie::~Izdelie(){
		//����� �����������
		cout << "You called DESTRUCT for object " << this << endl;
	}
	//GETTING name
	char* Izdelie::Getname() {
		return(this->name);
	}
	//GETTING code
	char* Izdelie::Getcode() {
		return(this->code);
	}
	//GETTING count
	int Izdelie::Getcount() {
		return(this->count);
	}
	//SET UP name
	void Izdelie::Setname(char* x) {
		this->name = x;
	}
	//SET UP code
	void Izdelie::Setcode(char* x) {
		this->code = x;
	}
	//SET UP count
	void Izdelie::Setcount(int x) {
		this->count = x;
	}
	//SET UP EVERYTHING
	void Izdelie::Set(char* x, char* y, int z) {
		this->name = x;
		this->code = y;
		this->count = z;
	}
	//SHOW EVERYTHING
	void Izdelie::Show() {
		cout << this->name << " " << this->code << "  " << this->count << endl;
	}
	//�������� ���������� ������� � �����
	void Izdelie::Checkcount( Izdelie y){
		if (this->Getcount() > y.Getcount())
			cout << this->Getname() << " is bigger than " << y.Getname() << endl;
		if (this->Getcount() < y.Getcount())
			cout << y.Getname() << " is bigger than " << this->Getname() << endl;
		if (this->Getcount() == y.Getcount())
			cout <<"count of this details is equal"<< endl;
	}
	//�������� ������� �������� �����
	void Izdelie::IsNull() {
		if (this->Getcount() != 0)
			cout << this->Getname() <<" Is'nt NULL" << endl;
		else cout << this->Getname() <<" Is Null" << endl;
	}