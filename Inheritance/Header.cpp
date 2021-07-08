#include <iostream>
#include <algorithm>
#include "Header.h"
#include <string>

using namespace std;
std::list<Person*> Person::lst;
	Person::Person() {
		this->name = "Unnamed";
	};
	Person::Person(string x) {
		this->name = x;
	};
	Person::~Person(){
		(lst.remove(this));

	};
	string Person::GetName() {
		return this->name;
	};
	void Person::SetName() {
		cout << "Enter Person name: ";
		cin >> name;
		cout << endl;
	};
	void Person::show_all() {
		if (lst.empty()) {
			std::cout << "List is empty!" << std::endl;
		}
		else {
			for (auto x : lst) {
				x->Show();
			}

		}
	}

	Soldier::Soldier() {
		this->Medals_count = 0;
		this->Howlong = 0;
		add();
	};
	Soldier::Soldier(int x, int y) {
		this->Medals_count = x;
		this->Howlong = y;
		add();
	};
	Soldier::~Soldier() {
	};
	int Soldier::GetMedals_count() {
		return this->Medals_count;
	};
	int Soldier::GetHowlong() {
		return this->Howlong;
	};
	void Soldier::Show() {
		cout << "Soldier	" << this->name <<"	"<< this->Medals_count << "	" << this->Howlong << endl;
	}
	void Soldier::SetMedals_count() {
		cout << "Enter medals count: ";
		cin >> this->Medals_count;
		cout<<endl;
	};
	void Soldier::SetHowlong() {
		cout << "Enter how long: ";
		cin >> this->Howlong;
		cout << endl;
	};
	void Soldier::add() {
		lst.push_back(this);
	}



	Worker::Worker() {
		this->Salary = 0;
		this->Product = "No Product";
		add();
	};
	Worker::~Worker() {
	};
	Worker::Worker(int x, string y) {
		this->Product =y;
		this->Salary = x;
		add();
	};
	int Worker::GetSalary() {
		return this->Salary;
	};
	string Worker::GetProduct() {
		return this->Product;
	};
	void Worker::Show() {
		cout << "Worker	" << this->name << "	" << this->Salary << "	" << this->Product << endl;
	}
	void Worker::SetSalary() {
		cin >> this->Salary;
	};
	void Worker::SetProduct() {
		cin>>Product;
	};
	void Worker::add() {
		lst.push_back(this);
	}

	Engineer::Engineer() {
		this->Engineer_type = "No Engineer_type";
		this->HowmuchInnovations = 0;
		add();
	};
	Engineer::Engineer(string x, int y) {
		this->Engineer_type = x;
		this->HowmuchInnovations = y;
		add();
	};
	Engineer::~Engineer() {
	};
	string Engineer::GetEngineer_type() {
		return this->Engineer_type;
	};
	int Engineer::GetHowmuchInnovations() {
		return this->HowmuchInnovations;
	};
	void Engineer::Show() {
		cout << "Engineer	" << this->name << "	" << this->Engineer_type << "	" << this->HowmuchInnovations << endl;
	}
	void Engineer::SetEngineer_type() {
		cin>>Engineer_type;
		
	};
	void Engineer::SetHowmuchInnovations() {
		cin >> this->HowmuchInnovations;
	};
	void Engineer::add() {
		lst.push_back(this);
	}



