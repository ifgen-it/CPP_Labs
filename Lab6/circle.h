#pragma once
#include "point.h"
#include "shape.h"
#define PI 3.141592

class Circle : public Shape
{
	Point m_point;
	int m_rad;

public:


	Circle() : Shape(), m_point(0, 0), m_rad(0) {}
	Circle(int x, int y, int rad, Color col) : Shape(col), m_point(x, y), m_rad(rad) {}
	Circle(const Circle& other) : Shape(other.m_color), m_point(other.m_point), m_rad(other.m_rad) {}
	Circle(Circle&& temp) = default;	

	Circle& operator=(const Circle& other) = default;	

	virtual Shape& operator=(const Shape& other) override
	{
		if (this != &other)
		{
			if (const Circle* Source = dynamic_cast<const Circle*>(&other))
			{
				*this = static_cast<const Circle&>(other);
				//Shape::operator=(other);
				//m_point = Source->m_point;
				//m_rad = Source->m_rad;
			}
		}
		return *this;
	}

	Circle& operator=(Circle&& temp) = default;	

	virtual bool operator==(const Shape& other) const override;	
	bool operator==(const Circle& other) const;
	
	virtual double Square() override;
	virtual Color GetColor() override { return this->m_color; }
	
	friend ostream& operator<<(ostream& os, const Circle& C);
	friend istream& operator>>(istream& is, Circle& C);

	virtual ~Circle() = default;

	virtual Shape* Clone() const { return new Circle(*this); }

	//void SetCircle(int x, int y, int rad);
	//void GetCircle(int& x, int& y, int& rad);
	//virtual void Inflate(int d);

	virtual ostream& Print(ostream& os) const { return os << *this; }
};