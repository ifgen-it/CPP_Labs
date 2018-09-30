#pragma once
#include <iostream>
using namespace std;

class Oct
{
	unsigned char m_oct0 : 3;
	unsigned char m_oct1 : 3;
	unsigned char m_oct2 : 2;


//public:
	Oct();
	~Oct();

	void Show();
	void ShowPos(int pos);
	void Edit(int pos, int val);

	friend union Bytes;

};

