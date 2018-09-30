#pragma once
#include <iostream>
using namespace std;

class Hex
{
	unsigned char m_hex0 : 4;
	unsigned char m_hex1 : 4;


	//char DecToHex(unsigned char input);

//public:
	Hex();
	~Hex();

	void Show();
	void ShowPos(int pos);
	void Edit(int pos, int val);

	friend union Bytes;

};

