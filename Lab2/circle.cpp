#include "circle.h"

Circle::Circle():Shape(RED)
{
	m_x = 0;
	m_y = 0;
	m_rad = 0;
}

Circle::Circle(int x, int y, int rad, COLOR col):Shape(col)
{
	m_x = x;
	m_y = y;
	m_rad = rad;
}

Circle::Circle(const Rect& R):Shape(R)
{
	int l,t,r,b;
	R.GetRect(l, t, r, b);
	
	m_x = (l+r)/2;
	m_y = (t+b)/2;
	m_rad = (r-l)<(b-t) ? (r-l)/2 : (b-t)/2;
	/*m_color = R.GetColor();*/
	
}

void Circle::SetCircle(int x, int y, int rad)
{
	m_x = x;
	m_y = y;
	m_rad = rad;
}

void Circle::GetCircle(int& x, int& y, int& rad)
{
	x = m_x;
	y = m_y;
	rad = m_rad;
}

void Circle::SetCircle(const Rect& R)
{
	int l,t,r,b;
	R.GetRect(l, t, r, b);
	
	m_x = (l+r)/2;
	m_y = (t+b)/2;
	m_rad = (r-l)<(b-t) ? (r-l)/2 : (b-t)/2;
	//m_color = R.GetColor();
	
}

void Circle::Print()
{
	//printf("m_color = %d\n", m_color);
	Shape::Print();
	printf("m_x = %d\n", m_x);
	printf("m_y = %d\n", m_y);
	printf("m_rad = %d\n", m_rad);
}

void Circle::WhereAmI()
{
	cout << "I am in the class 'Circle' now\n";
}

void Circle::Inflate(int d)
{
	m_rad += d;
}

Circle::~Circle()
{
	cout << "Now I am in Circle's destructor!" << endl;
}