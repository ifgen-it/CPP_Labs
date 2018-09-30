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

MyString::MyString(MyString& other)
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
/*
MyString ConcatString(const char* str1, ...) {

	const char** ArgPtr = &str1;
	char* SumStr = nullptr;

	while (*ArgPtr) {	// arg is not nullptr
		char* Str = const_cast<char*>(*ArgPtr);	// string from argument
		int n = strlen(Str);
		char* Temp = nullptr; // for traversing of the string

							  // need new pointer - for second and further args
		if (SumStr) {
			char* TempSumStr = new char[strlen(SumStr) + n + 1];
			Temp = TempSumStr + strlen(SumStr);
			strcpy(TempSumStr, SumStr);
			delete[] SumStr;
			SumStr = TempSumStr;
			TempSumStr = nullptr;
		}
		else {		// for first arg
			SumStr = new char[n + 1];
			Temp = SumStr;
		}
		// string copy
		for (int i = 0; i < n; i++) {
			*Temp = *Str;
			Temp++;
			Str++;
		}
		*Temp = '\0';
		// move to the next arg
		ArgPtr++;
	}


	MyString Result(SumStr);
	delete SumStr;
	return Result;
}
*/

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

