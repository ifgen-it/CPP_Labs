#pragma once
#include "counter.h"
#include <iostream>

using namespace std;

class MyString
{
	Counter* m_pMyCounter;
	
public:
	MyString();
	MyString(const char* Str);
	MyString(const MyString& other);
	MyString(MyString&& temp);
	MyString& operator=(const MyString& other);
	MyString& operator=(MyString&& temp);

	friend ostream& operator<<(ostream& os, const MyString& Str);

	static void PrintStrings();
	static void LowerStrings();
	static void UpperStrings();
	static void SortAscStrings();

	~MyString();

	const char* GetStr() const;	// пришлось делать изза того, что Counter не дает дружбу оператору<<
};

