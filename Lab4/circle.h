#pragma once
#include "point.h"
#define PI 3.141592

class Circle
{
	Point m_point;
	int m_rad;

public:


	Circle();	//1
	Circle(int x, int y, int rad);	//2
	Circle(const Circle& other);	//3
	Circle(Circle&& temp);	//4
	Circle& operator=(const Circle& other);	//5
	Circle& operator=(Circle&& temp);		//6
	bool operator==(const Circle& other);	//7

	void SetCircle(int x, int y, int rad);
	void GetCircle(int& x, int& y, int& rad);
	double GetSquare();
	
	friend ostream& operator<<(ostream& os, Circle& C);
	friend istream& operator>>(istream& is, Circle& C);
	
	virtual void Inflate(int d);
	virtual ~Circle() = default;



};