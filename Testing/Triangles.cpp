#include "Triangles.h"
#include <iostream>
using namespace std;

Triangle::Triangle(){
	A = 0; B = 0; C = 0;
}
void Triangle::CheckAngles(){
	int DegreesLeft = 180;
	std::cout << "Enter angle A(180 degrees left):  "; std::cin >> A;
	DegreesLeft -= A;
	if (DegreesLeft <= 1) {
		cout << "You can't make that triangle, dumbass" << endl;
		CheckAngles();
		return;
	}
	std::cout << "Enter angle B("<<DegreesLeft<<" left):  "; std::cin >> B;
	DegreesLeft -= B;
	if (DegreesLeft <= 0) {
		cout << "You can't make that triangle, dumbass" << endl;
		CheckAngles();
		return;
	}
	C = DegreesLeft; 
	return;
}

int Triangle::FindBiggestAngle() {
	int BiggestAngle = A;
	if (B > BiggestAngle) BiggestAngle = B;
	if (C > BiggestAngle) BiggestAngle = C;
	return BiggestAngle;

}

void Triangle::CheckTriangle() {
	int BiggestAngle = FindBiggestAngle();

	if (BiggestAngle < 90) { 

		if (A == B || A == C || B == C) {
			if (A == B && A == C) {
				cout << "Equilateral triangle" << endl;
				return;
			}
			cout << "isosceles acute-angled triangle" << endl;
			return;
		}
		else {
			cout << "acute-angled triangle" << endl;
			return;
		}
	}
	else if (BiggestAngle > 90) {
		if (A == B || A == C || B == C) {
			cout << "isosceles obtuse triangle" << endl;
			return;
		}
		else {
			cout << "obtuse triangle" << endl;
			return;
		}
	}
	else if (A == B || A == C || B == C) {
		
		cout << "isosceles rectangular triangle" << endl;
		return;
	}
	cout << "rectangular triangle" << endl;
	return;
}

