#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>


using namespace std;

class Counter
{
	Counter* pNext;
	char* m_pStr;
	unsigned int m_nOwners;

	static Counter* pHead;
	static unsigned int m_curCounters;
	
	friend class MyString;
	//friend ostream& operator<<(ostream& os, const MyString& Str);
	friend ostream& operator<<(ostream& os, const Counter& C);

	//Counter();	//убрал за ненадобностью
	Counter(const char* Str);
	~Counter();

	void AddUser();
	void RemoveUser();
	void AddToHead();

	void Lower();
	void Upper();

public:
	const char* GetStr() const;
	

};

