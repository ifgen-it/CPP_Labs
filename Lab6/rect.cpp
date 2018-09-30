#include "rect.h"


bool Rect::operator==(const Shape& other) const
{
	if (!dynamic_cast<const Rect*>(&other)) { return false; }
	const Rect* pOther = static_cast<const Rect*>(&other);
	bool EqualBase = Shape::operator==(other);

	return EqualBase && m_left == pOther->m_left &&
		m_right == pOther->m_right && m_top == pOther->m_top && m_bottom == pOther->m_bottom;
}

bool Rect::operator==(const Rect& other) const
{
	return m_color == other.m_color && m_left == other.m_left &&
		m_right == other.m_right && m_top == other.m_top && m_bottom == other.m_bottom;
}

double Rect::Square()
{
	return (m_right - m_left)*(m_bottom - m_top);
}

ostream& operator<<(ostream& os, const Rect& R)
{
	const char* ColorName[] = { "RED", "GREEN", "BLUE", "YELLOW", "BLACK", "WHITE", "PINK", "GREY" };
	os << "Rect " << "l= " << R.m_left << " r= " << R.m_right << " t= " << R.m_top <<
		" b= " << R.m_bottom << " col= " << ColorName[R.m_color] << endl;
	return os;
}

istream& operator>>(istream& is, Rect& R)
{
	const char* ColorName[] = { "RED", "GREEN", "BLUE", "YELLOW", "BLACK", "WHITE", "PINK", "GREY" };
	char Temp[8] = { 0 };
	char col[8];

	is >> Temp >> R.m_left >> Temp >> R.m_right >> Temp >> R.m_top >> Temp >> R.m_bottom >> Temp >> col;
	
	for (size_t i = 0; i < sizeof(ColorName) / sizeof(ColorName[0]); i++)
	{
		if (strcmp(col, ColorName[i]) == 0)
		{
			R.m_color = static_cast<Shape::Color>(i);
			break;
		}
		else
		{
			R.m_color = Shape::WHITE;
		}
	}

	return is;
}