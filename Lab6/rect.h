#pragma once
#include "point.h"
#include "shape.h"

class Rect : public Shape
{
	int m_left;
	int m_right;
	int m_top;
	int m_bottom;

public:

	Rect() :Shape(), m_left(), m_right(), m_top(), m_bottom() {}
	Rect(int l, int r, int t, int b, Color col) :Shape(col), m_left(l), m_right(r), m_top(t), m_bottom(b) {}
	Rect(const Rect& other) = default;
	Rect(Rect&& temp) = default;

	Rect& operator=(const Rect& other) = default;
	
	virtual Shape& operator=(const Shape& other) override
	{
		if (this != &other)
		{
			if (const Rect* Source = dynamic_cast<const Rect*>(&other))
			{
				*this = static_cast<const Rect&>(other);	// будет использоваться default operator=
				/*Shape::operator=(other);
				m_left = Source->m_left;
				m_right = Source->m_right;
				m_top = Source->m_top;
				m_bottom = Source->m_bottom;*/
			}
		}
		return *this;
	}


	Rect& operator=(Rect&& temp) = default;

	bool operator==(const Rect& other) const;

	friend ostream& operator<<(ostream& os, const Rect& R);
	friend istream& operator>>(istream& is, Rect& R);

	virtual double Square() override;
	virtual Color GetColor() override { return this->m_color; }

	virtual ~Rect() = default;

	virtual bool operator==(const Shape& other) const override;

	virtual Shape* Clone() const { return new Rect(*this); }

	virtual ostream& Print(ostream& os) const { return os << *this; }
};

