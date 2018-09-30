#include "circle.h"

Circle::Circle() : m_point(0, 0), m_rad(0) {}

Circle::Circle(int x, int y, int rad) : m_point(x, y), m_rad(rad) {}

Circle::Circle(const Circle& other)	
{
	m_point = other.m_point;
	m_rad = other.m_rad;
}

Circle::Circle(Circle&& temp)
{
	m_point = temp.m_point;
	m_rad = temp.m_rad;
}

Circle& Circle::operator=(const Circle& other)
{
	m_point = other.m_point;
	m_rad = other.m_rad;
	return *this;
}

Circle& Circle::operator=(Circle&& temp)
{
	m_point = temp.m_point;
	m_rad = temp.m_rad;
	return *this;
}

bool Circle::operator==(const Circle& other)
{
	return (m_point == other.m_point) && (m_rad == other.m_rad);
}

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

ostream& operator<<(ostream& os, Circle& C)
{
	os << C.m_point << " rad= " << C.m_rad << endl;
	//os << C.m_point << " " << C.m_rad << endl;
	return os;
}

istream& operator>>(istream& is, Circle& C)
{
	char Temp[8] = { 0 };
	is >> C.m_point >> Temp >> C.m_rad;
	return is;
}

void Circle::Inflate(int d)
{
	m_rad += d;
}

double Circle::GetSquare()
{
	return PI * m_rad * m_rad;
}
