#pragma once
#include <iostream>
using namespace std;

class Shape
{
public:
	enum Color	{RED, GREEN, BLUE, YELLOW, BLACK, WHITE, PINK, GREY};

protected:
	Color m_color;

	Shape(Color col=WHITE) : m_color(col) {}

public:
	virtual ~Shape() = default;
	virtual double Square() = 0;
	virtual Color GetColor() = 0;
	virtual ostream& Print(ostream& os) const = 0;
	
	friend ostream& operator<<(ostream& os, const Shape& S) { return S.Print(os); }
	virtual Shape* Clone() const = 0;

	virtual Shape& operator=(const Shape& other) = 0
	{
		if (this != &other)
		{
			m_color = other.m_color;
		}
		return *this;
	}	
	
	virtual bool operator==(const Shape& other) const = 0 { return m_color == other.m_color; }
	//friend void SortArrShapes(Shape** Arr, size_t size, const char* mode);
	//friend void List::Sort(const char* mode);
};

