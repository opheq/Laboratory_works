#pragma once


class Triangle {
	int A, B, C;

public:
	Triangle();
	void CheckAngles();
	void CheckTriangle();
	int FindBiggestAngle();
};