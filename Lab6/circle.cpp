#include "circle.h"

bool Circle::operator==(const Shape& other) const
{
	if (!dynamic_cast<const Circle*>(&other)) { return false; }

	const Circle* pOther = static_cast<const Circle*>(&other);
	bool EqualBase = Shape::operator==(other);

	return EqualBase && (m_point == pOther->m_point) && (m_rad == pOther->m_rad);
}

bool Circle::operator==(const Circle& other) const
{
	return (m_point == other.m_point) && (m_rad == other.m_rad) && (m_color == other.m_color);
}

ostream& operator<<(ostream& os, const Circle& C)
{
	const char* ColorName[] = { "RED", "GREEN", "BLUE", "YELLOW", "BLACK", "WHITE", "PINK", "GREY" };
	os << "Circle " << C.m_point << " rad= " << C.m_rad << " col= " << ColorName[C.m_color] << endl;
	return os;
}

istream& operator>>(istream& is, Circle& C)
{
	const char* ColorName[] = { "RED", "GREEN", "BLUE", "YELLOW", "BLACK", "WHITE", "PINK", "GREY" };
	char Temp[8] = { 0 };
	char col[8];
	is >> C.m_point >> Temp >> C.m_rad >> Temp >> col;


	for (size_t i = 0; i < sizeof(ColorName)/sizeof(ColorName[0]); i++)
	{
		if (strcmp(col, ColorName[i]) == 0)
		{
			C.m_color = static_cast<Shape::Color>(i);
			break;
		}
		else
		{
			C.m_color = Shape::WHITE;
		}
	}
	
	return is;
}

double Circle::Square()
{
	return PI * m_rad * m_rad;
}


// dont need
/*
void Circle::SetCircle(int x, int y, int rad)
{
m_point = Point(x, y);
m_rad = rad;
}

void Circle::GetCircle(int& x, int& y, int& rad)
{
m_point.GetPoint(x, y);
rad = m_rad;
}

void Circle::Inflate(int d)
{
m_rad += d;
}
*/