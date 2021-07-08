#pragma once
#include <iostream>
using namespace std;
static int elements = 0;

template <class T> class Arr {
	T* mass;
	T size_of_array;
public:
	Arr() {
		this->size_of_array = 10;
		this->mass = new T[this->size_of_array];
		for (int i = 0; i < this->size_of_array; i++)
		{
			this->mass[i] = 0;
		}
		elements++;
	}

	~Arr() {
		cout << "Destructor has been called" << endl;
		delete(this->mass);
		elements--;
		cout << "Now you have " << elements << " elements" << endl;
	}
	void input() {
		int x;
		for (int i = 0; i < this->size_of_array; i++)
		{
			cin >> x;
			this->mass[i] = x;
		}
	}

	void print() {
		for (int i = 0; i < this->size_of_array; i++)
		{
			cout << this->mass[i] << "     ";
		}
		cout << endl;
	}

	T Summ() {
		T summa = 0;
		for (int i = 0; i < this->size_of_array; i++)
		{
			if (this->mass[i]>0)
			{
				summa += mass[i];
			}
		}
		cout << endl;
		return summa;
	}

	T Proizvedenie() {
		int pos1 = 0;
		int pos2 = 0;
		int number = 0;
		int temp;
		T Proizvedenie = 1;
		for (int i = 0; i < this->size_of_array; i++)
		{
			if (abs(this->mass[i])>abs(this->mass[pos1]))
			{
				pos1 = i;
				number = 1;
			}
		}
		for (int i =0;i< this->size_of_array; i++)
		{
			if (abs(this->mass[i]) < abs(this->mass[pos2]))
			{
				pos2 = i;
				number = 2;
			}
		}
		if (number != 0&&abs(pos1-pos2)>1) {
			if (pos1 > pos2) {
				temp=pos1;
				pos1=pos2;
				pos2 = temp;
			}
			for (int i = pos1+1; i < pos2; i++)
				Proizvedenie = Proizvedenie*this->mass[i];
			return Proizvedenie;
		}
		else cout << "Not enough minus elements " << endl;
	}
};