#pragma once
#include "shape.h"
#include "rect.h"

class Circle : public Shape
{
	int m_x;
	int m_y;
	int m_rad;

public:

	Circle();
	Circle(int x, int y, int rad, COLOR col);
	Circle(const Rect& R);
	void SetCircle(int x, int y, int rad);
	void GetCircle(int& x, int& y, int& rad);
	void SetCircle(const Rect& R);
	void Print();
	virtual void WhereAmI();
	virtual void Inflate(int d) /*override*/;
	
	virtual ~Circle();


};