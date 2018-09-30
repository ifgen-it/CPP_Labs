#include "shape.h"


Shape::Shape()
{
	m_color = BLUE;
}

Shape::Shape(COLOR col)
{
	m_color = col;
}

COLOR Shape::GetColor() const
{
	return m_color;
}

void Shape::SetColor(COLOR col)
{
	m_color = col;
}

void Shape::Print()
{
	printf("m_color = %d\n", m_color);
}

void Shape::WhereAmI()
{
	cout << "I am in the class 'Shape' now\n";
}





Shape::~Shape()
{
	cout << "Now I am in Shape's destructor!" << endl;
}