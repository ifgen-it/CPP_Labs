#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include "myString.h"
using namespace std;

// Определение конструктора.

MyString::MyString(const char* str)
{
	if (str) {
		size_t n = strlen(str) + 1;
		m_pStr = new char[n];
		strcpy(m_pStr, str);
	}
	else
	{
		m_pStr = nullptr;
	}
}

MyString::MyString()
{
	m_pStr = nullptr;
}

MyString::MyString(const MyString& other)
{
	if (other.m_pStr) {
		size_t n = strlen(other.m_pStr) + 1;
		m_pStr = new char[n];
		strcpy(m_pStr, other.m_pStr);
	}
	else
	{
		m_pStr = nullptr;
	}
}

MyString::MyString(MyString&& temp)
{
	if (temp.m_pStr) {
		m_pStr = temp.m_pStr;
		temp.m_pStr = nullptr;
	}
	else
	{
		m_pStr = nullptr;
	}
}

void MyString::SetNewString(const char* str)
{
	delete m_pStr;
	size_t n = strlen(str) + 1;
	m_pStr = new char[n];
	strcpy(m_pStr, str);
}

MyString ConcatString(const char* str1,...) {
	
	const char** ArgPtr = &str1;	// 1st arg
	
	int StrLength = 0;	// length of concatenated string

	// traversing string for length
	while (*ArgPtr) {	// arg is not nullptr
		char* Str = const_cast<char*>(*ArgPtr);	// string from argument
		StrLength += strlen(Str);
		ArgPtr++;
	}
	StrLength++;	// for '\0'

	// here will be concatenated strings
	char* SumStr = new char[StrLength];
	
	// copying of strings
	ArgPtr = &str1;
	char* Temp = SumStr;

	while (*ArgPtr) {	// arg is not nullptr
		char* Str = const_cast<char*>(*ArgPtr);	// string from argument
		int n = strlen(Str);
		
		//copy of particular string
		for (int i = 0; i < n; i++) {
			*Temp = *Str;
			Temp++;
			Str++;
		}
		// move to the next arg
		ArgPtr++;
	} // end of copying

	*Temp = '\0';
		
	MyString Result(SumStr);
	delete SumStr;
	return Result;
}

// Определение деструктора.

MyString::~MyString()
{
	delete[] m_pStr;
}

const char* MyString::GetString() const
{
	if (this) {
		if (m_pStr) {
			return m_pStr;
		}
		else
		{
			return "string is empty";
		}
	}
	else
	{
		return "object was not created";
	}
}

MyString& MyString::operator=(const MyString& other)
{
	if (other.m_pStr){
		if (this != &other)
		{
		delete m_pStr;
		m_pStr = new char[strlen(other.m_pStr) + 1];
		strcpy(m_pStr, other.m_pStr);
		}
	}
	else
	{
		m_pStr = nullptr;
	}

	return *this;
}

MyString& MyString::operator=(MyString&& temp)
{
	if (this != &temp)
	{
		delete m_pStr;
		m_pStr = temp.m_pStr;
		temp.m_pStr = nullptr;
	}
		
	return *this;
}

MyString& MyString::operator=(const char* str)
{
	if (str) {
		delete m_pStr;
		m_pStr = new char[strlen(str) + 1];
		strcpy(m_pStr, str);
	}
	else
	{
		m_pStr = nullptr;
	}

	return *this;
}

ostream& operator<<(ostream& os, const MyString& other)
{
	if (other.m_pStr)
	{
		os << other.m_pStr;
	}
	
	return os;
}

istream& operator>>(istream& is, MyString& other)
{
	char Temp[256];
	is >> Temp;
	other = Temp;

	return is;
}

MyString& MyString::operator+=(const MyString& other)
{
	if (other.m_pStr == nullptr && m_pStr)
	{

	}
	if (m_pStr == nullptr && other.m_pStr)
	{
		*this = other;
	}
	else if (other.m_pStr && m_pStr)
	{
		size_t n = strlen(m_pStr) + strlen(other.m_pStr) + 1;
		char* Temp = new char[n];
		strcpy(Temp, m_pStr);
		strcat(Temp, other.m_pStr);

		delete m_pStr;
		m_pStr = Temp;
		Temp = nullptr;
	}
	
	return *this;
}

MyString MyString::operator+(const MyString& other) const
{
	char* Temp = nullptr;
	MyString ret;

	if (m_pStr && other.m_pStr)
	{
		size_t n = strlen(m_pStr) + strlen(other.m_pStr) + 1;
		Temp = new char[n];
		strcpy(Temp, m_pStr);
		strcat(Temp, other.m_pStr);
		ret = Temp;
		delete[] Temp;
		
	}
	if (m_pStr && other.m_pStr == nullptr)
	{
		ret = *this;
	}
	if (m_pStr == nullptr && other.m_pStr)
	{
		ret = other;
	}
	
	return ret;
}

MyString& MyString::operator+=(const char* str)
{

	if (str && m_pStr)
	{
		size_t n = strlen(m_pStr) + strlen(str) + 1;
		char* Temp = new char[n];
		strcpy(Temp, m_pStr);
		strcat(Temp, str);

		delete m_pStr;
		m_pStr = Temp;
		Temp = nullptr;
	}

	if (str && m_pStr == nullptr)
	{
		*this = str;
	}
	return *this;
}

MyString operator+=(const char* str, const MyString& other)
{
	// other.m_pStr   str
	if (other.m_pStr)
	{
		size_t n = strlen(other.m_pStr) + strlen(str) + 1;
		char* Temp = new char[n];
		strcpy(Temp, str);
		strcat(Temp, other.m_pStr);
		return MyString(Temp);
	}
	else
	{
		return MyString(str);
	}
}
