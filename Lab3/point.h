#pragma once
#include <iostream>
using namespace std;

class Point
{
	int m_x;
	int m_y;

public:
	Point();
	Point(int x, int y);
	Point(Point& other) = default;
	Point(Point&& temp) = default;
	~Point() = default;
	void SetPoint(int x, int y);
	void GetPoint(int& x, int& y) const;
	void Print() const;

	Point& operator=(const Point& other) = default;
	Point& operator=(int d);
	Point& operator+=(const Point& other);
	Point& operator+=(int d);

	Point operator+(const Point& other) const;
	Point operator+(int d) const;


	friend Point& operator-=(Point& first, const Point& second);
	friend Point& operator-=(Point& first, int second);
	friend Point operator+(int second, const Point& first);
	friend Point operator-(const Point& first, const Point& second);
	friend Point operator-(const Point& first, int second);
	friend Point operator-(int second, const Point& first);
	friend Point operator-(const Point& first);
	friend const Point& operator+(const Point& first);

};


