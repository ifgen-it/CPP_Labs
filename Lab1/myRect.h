#pragma once
class Rect{
	int m_left, m_right, m_top, m_bottom;
public:
	Rect(int left, int right, int top, int bottom);		// констр. с параметрами
	Rect();		// конструктор по умолчанию
	void InflateRect(int dLeft, int dRight, int dTop, int dBottom);		// make delta coord. - inflate rect
	void InflateRect(int dLeftRight = 1, int dTopBottom = 1);

	Rect(const Rect& other);	// constructor for copy

	void SetAll(int left, int right, int top, int bottom);
	void GetAll(int& left, int& right, int& top, int& bottom) const;

	~Rect();
	

private:
	void CheckSwapSides();	// swap left <-> right AND top <-> bottom

};

Rect BoundingRect(Rect r1, Rect r2);

Rect BoundingRect2 (const Rect& r1, const Rect& r2);
