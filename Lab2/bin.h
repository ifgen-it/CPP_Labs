#pragma once
#include <iostream>
using namespace std;

class Bin
{
	bool m_bin0 : 1;
	bool m_bin1 : 1;
	bool m_bin2 : 1;
	bool m_bin3 : 1;
	bool m_bin4 : 1;
	bool m_bin5 : 1;
	bool m_bin6 : 1;
	bool m_bin7 : 1;
//public:
	Bin();
	~Bin();

	void Show();
	void ShowPos(int pos);
	void Edit(int pos, int val);

	friend union Bytes;

};

