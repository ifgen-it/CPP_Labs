#pragma once
#include "shape.h"
#include <iostream>

using namespace std;
class Rect : public Shape
{
	int m_left;
	int m_top;
	int m_right;
    int m_bottom;


public:

	Rect();
	Rect( int l, int t, int r, int b, COLOR col);
	Rect(const Rect& other);
	void SetRect( int l, int t, int r, int b);
	void GetRect( int& l, int& t, int& r, int& b) const;
	void Print();
	virtual void WhereAmI();
	virtual void Inflate(int d) /*override*/;
	
	virtual ~Rect();


};