#include "rect.h"

Rect::Rect():Shape(GREEN)
{
	m_left = 0;
	m_top = 0;
	m_right = 0;
	m_bottom = 0;
}

Rect::Rect(int l, int t, int r, int b, COLOR col):Shape(col)
{
	m_left = l;
	m_top = t;
	m_right = r;
	m_bottom = b;
}

Rect::Rect(const Rect& other)
{
	m_color = other.m_color;
	m_left = other.m_left;
	m_top = other.m_top;
	m_right = other.m_right;
	m_bottom = other.m_bottom;
}

void Rect::SetRect(int l, int t, int r, int b)
{
	m_left = l;
	m_top = t;
	m_right = r;
	m_bottom = b;
}

void Rect::GetRect(int& l, int& t, int& r, int& b) const
{
	l = m_left;
	t = m_top;
	r = m_right;
	b = m_bottom;
}

void Rect::Print()
{
	//printf("m_color = %d\n", m_color);
	Shape::Print();
	printf("m_left = %d\n", m_left);
	printf("m_top = %d\n", m_top);
	printf("m_right = %d\n", m_right);
	printf("m_bottom = %d\n", m_bottom);
}

void Rect::WhereAmI()
{
	cout << "I am in the class 'Rect' now\n";
}

void Rect::Inflate(int d)
{
	m_left -= d;
	m_top -= d;
	m_right += d;
	m_bottom += d;
}


Rect::~Rect()
{
	cout << "Now I am in Rect's destructor!" << endl;
}