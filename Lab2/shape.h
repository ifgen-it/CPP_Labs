#pragma once
#include <iostream>
#include "header.h"

using namespace std;

class Shape
{
protected:
    COLOR m_color;


public:
    
	Shape();
	Shape(COLOR col);
	COLOR GetColor() const;
	void SetColor(COLOR col);
    virtual void Print();
	virtual void WhereAmI();
	//virtual void Inflate(int d)=0;
	//virtual void Inflate(int d);
	
	virtual ~Shape();


};