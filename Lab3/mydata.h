#pragma once
#include "myString.h"


class MyData
{
public:
	enum Sex {UNDEF, MALE, FMALE};
private:
	Sex m_sex;
	size_t m_age;
	MyString m_job;
	float m_salary;
	
public:
	MyData();	//1
	~MyData() = default;	//2
	MyData(Sex s, size_t age, const char* job, float sal);	//3
	MyData(const MyData& other);	//4
	MyData& operator=(const MyData& other) = default;	//5
	MyData(MyData&& other) = default;	//6
	MyData& operator=(MyData&& d) = default;	//7



	friend ostream& operator<<(ostream& os, const MyData& other);
	
	
};


