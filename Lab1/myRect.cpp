#include "myRect.h"

Rect::Rect()
{
	m_left = 0;
	m_right = 0;
	m_top = 0;
	m_bottom = 0;

}

Rect::Rect(int left, int right, int top, int bottom)
{
	m_left = left;
	m_right = right;
	m_top = top;
	m_bottom = bottom;
	
	CheckSwapSides();
}

void Rect::SetAll(int left, int right, int top, int bottom)
{
	m_left = left;
	m_right = right;
	m_top = top;
	m_bottom = bottom;

	CheckSwapSides();
}

void Rect::GetAll(int& left, int& right, int& top, int& bottom) const
{
	left = m_left;
	right = m_right;
	top = m_top;
	bottom = m_bottom;
}

void Rect::CheckSwapSides()
{
	if (m_left > m_right)
	{
		int temp = m_left;
		m_left = m_right;
		m_right = temp;
	}

	if (m_top > m_bottom)
	{
		int temp = m_top;
		m_top = m_bottom;
		m_bottom = temp;
	}
}

void Rect::InflateRect(int dLeft, int dRight, int dTop, int dBottom)
{
	m_left = m_left - dLeft;
	m_right = m_right + dRight;
	m_top = m_top - dTop;
	m_bottom = m_bottom + dBottom;

	CheckSwapSides();
}

void Rect::InflateRect(int dLeftRight, int dTopBottom)
{
	m_left = m_left - dLeftRight;
	m_right = m_right + dLeftRight;
	m_top = m_top - dTopBottom;
	m_bottom = m_bottom + dTopBottom;

	CheckSwapSides();
}

Rect::Rect(const Rect& other)
{
	m_left = other.m_left;
	m_right = other.m_right;
	m_bottom = other.m_bottom;
	m_top = other.m_top;
}

Rect BoundingRect(Rect r1, Rect r2)
{
	int r1Left, r1Right, r1Top, r1Bottom;
	int r2Left, r2Right, r2Top, r2Bottom;
	r1.GetAll(r1Left, r1Right, r1Top, r1Bottom);
	r2.GetAll(r2Left, r2Right, r2Top, r2Bottom);

	int Left = r1Left < r2Left ? r1Left : r2Left;
	int Right = r1Right > r2Right ? r1Right : r2Right;
	int Top = r1Top < r2Top ? r1Top : r2Top;
	int Bottom = r1Bottom > r2Bottom ? r1Bottom : r2Bottom;

	Rect Rectan(Left, Right, Top, Bottom);
	return Rectan;

}

Rect BoundingRect2 (const Rect& r1, const Rect& r2)
{
	int r1Left, r1Right, r1Top, r1Bottom;
	int r2Left, r2Right, r2Top, r2Bottom;
	r1.GetAll(r1Left, r1Right, r1Top, r1Bottom);
	r2.GetAll(r2Left, r2Right, r2Top, r2Bottom);

	int Left = r1Left < r2Left ? r1Left : r2Left;
	int Right = r1Right > r2Right ? r1Right : r2Right;
	int Top = r1Top < r2Top ? r1Top : r2Top;
	int Bottom = r1Bottom > r2Bottom ? r1Bottom : r2Bottom;

	Rect Rectan(Left, Right, Top, Bottom);
	return Rectan;
}

Rect::~Rect()
{

}




