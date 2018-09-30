#pragma once
#include "myString.h"
#include "mydata.h"

class Pair
{
private:

	MyString key;
	MyData data;
	
public:
	Pair() :key("???") {}	//1
	Pair(const char* k, const MyData& d) :key(k), data(d) {}	//2
	~Pair() = default;	//3
	Pair(const Pair& other) = default;	//4
	Pair(Pair&& temp) = default;	//5
	Pair& operator=(const Pair& other) = default;	//6
	Pair& operator=(Pair&& temp) = default;	//7

	bool operator==(const char* k) const;

	friend ostream& operator<<(ostream& os, const Pair& pair);
	friend class Base;



};


