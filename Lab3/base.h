#pragma once
#include "pair.h"

class Base
{
	Pair** pBase;
	size_t count;
	size_t capacity;

public:
	Base();		//1
	~Base();	//2
	Base(const Base& bd);	//3
	Base(Base&& bd);		//4
	Base& operator=(Base& bd);	//5
	Base& operator=(Base&& bd);	//6
	
	MyData& operator[](const char* k);

	friend ostream& operator<<(ostream& os, Base& bd);

	int deletePair(const char* k);
};


