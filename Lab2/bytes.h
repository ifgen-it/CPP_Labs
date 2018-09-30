#pragma once
#include <iostream>
using namespace std;

union Bytes
{
private:
	Bin m_bin;
	Oct m_oct;
	Hex m_hex;
	unsigned char m_dec;

public:	
	Bytes(unsigned char byte) { m_dec = byte; }

	void ShowBin() { m_bin.Show(); }
	void ShowOct() { m_oct.Show(); }
	void ShowHex() { m_hex.Show(); }
	void ShowDec() { cout << static_cast<int>(m_dec) << endl; }

	void ShowBinPos(int pos) { m_bin.ShowPos(pos); }
	void ShowOctPos(int pos) { m_oct.ShowPos(pos); }
	void ShowHexPos(int pos) { m_hex.ShowPos(pos); }
	void ShowDecPos(int pos){ 
		int num = -2;
		switch (pos)
		{
		case 0:
			num = m_dec % 10;
			break;
		case 1:
			num = (m_dec / 10) % 10;
			break;
		case 2:
			num = m_dec / 100;
			break;
		default:
			num = -1;
			break;
		}
		cout << num << endl;
	}

	void EditBin(int pos, int val) { m_bin.Edit(pos, val); }
	void EditOct(int pos, int val) { m_oct.Edit(pos, val); }
	void EditHex(int pos, int val) { m_hex.Edit(pos, val); }
	void EditDec(int pos, int val) {
		int num;
		switch (pos)
		{
		case 0:
			num = m_dec % 10;
			m_dec -= num;
			m_dec += val;
			break;
		case 1:
			num = ((m_dec / 10) % 10)*10;
			m_dec -= num;
			m_dec += 10 * val;
			break;
		case 2:
			num = (m_dec / 100)*100;
			m_dec -= num;
			m_dec += 100 * val;
			break;
		default:
			m_dec = m_dec;
			break;
		}
		

	}

	~Bytes()
	{

	}

};