#pragma once
#include <iostream>
#include <time.h>
#include <algorithm>
#include <vector> 
using namespace std;
template <class T> class Arr {
	T* mass;
	T size_of_array;
public:
	const Arr& operator==(Arr& obj) {
		bool check = true;
		if (this->size_of_array < obj.size_of_array)
			for (int i = 0; i < this->size_of_array; i++)
			{
				if (check == false)
				{
					break;
				}
				if (this->mass[i] != obj.mass[i])
				{
					check = false;
				}
			}
		if (this->size_of_array > obj.size_of_array)
			for (int i = 0; i < obj.size_of_array; i++) {
					if (check == false)
					{
						break;
					}
					if (this->mass[i] != obj.mass[i])
					{
						check = false;
					}
				}
				if (this->size_of_array == obj.size_of_array)
					for (int i = 0; i < this->size_of_array; i++) {
						
							if (check == false)
							{
								break;
							}
							if (this->mass[i] != obj.mass[i])
							{
								check = false;
							}
						
					}
				if (check == true)
					cout << "Arrays are equal" << endl;
				return obj;
			}
	const Arr& operator+(Arr& obj) {
		if (this->size_of_array < obj.size_of_array)
			for (int i = 0; i < this->size_of_array; i++)
			{
				this->mass[i] = this->mass[i] + obj.mass[i];
			}
		if (this->size_of_array > obj.size_of_array)
			for (int i = 0; i < obj.size_of_array; i++)
			{
				this->mass[i] = this->mass[i] + obj.mass[i];
			}
		if (this->size_of_array == obj.size_of_array)
			for (int i = 0; i < this->size_of_array; i++)
			{
				this->mass[i] = this->mass[i] + obj.mass[i];
			}
		return obj;
	}
	Arr() {
		this->size_of_array = 10;
		this->mass = new T[this->size_of_array];
		for (int i = 0; i < this->size_of_array; i++)
		{
			this->mass[i] = 0;
		}
	}

	~Arr() {
		delete[] this->mass;
		this->mass = nullptr;
	}
	void input() {
		for (int i = 0; i < this->size_of_array; i++)
		{
			cin>>this->mass[i];
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
			if (i % 2 != 0)
			{
				summa += mass[i];
			}
		}
		cout << endl;
		return summa;
	}

	T Summ1() {
		T pos1 = -1;
		T pos2 = -1;
		T Summ1 = 0;
		for (int i = 0; i < this->size_of_array; i++)
		{
			if (this->mass[i] < 0)
			{
				pos1 = i;
				break;
			}
		}
		for (int i = this->size_of_array - 1; i > 0; i--)
		{
			if (this->mass[i] < 0 && i != pos1)
			{
				pos2 = i;
				break;
			}

		}
		if (pos1 != -1 && pos2 != -1) {
			for (int i = pos1 + 1; i <= pos2 - 1; i++)
				Summ1 += this->mass[i];
			return Summ1;
		}
		else cout << "Not enough minus elements " << endl;
	}
};