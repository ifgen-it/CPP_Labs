#pragma once
#include <iostream>
using namespace std;

class MyString
{
    char* m_pStr;	//строка-член класса
public:
	MyString(const char* str);
	MyString();
	MyString(const MyString& other);
	MyString(MyString&& temp);
	~MyString();

	const char* GetString() const;

	void SetNewString(const char* str);

	MyString& operator=(const MyString& other);
	MyString& operator=(MyString&& temp);
	MyString& operator=(const char* str);
	MyString& operator+=(const MyString& other);
	MyString operator+(const MyString& other) const;
	MyString& operator+=(const char* str);

	friend ostream& operator<<(ostream& os, const MyString& other);
	friend istream& operator>>(istream& is, MyString& other);
	friend MyString operator+=(const char* str, const MyString& other);

};

MyString ConcatString(const char* str1,...);

