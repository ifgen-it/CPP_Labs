#include "bin.h"

Bin::Bin()
{
	m_bin0 = 0;
	m_bin1 = 1;
	m_bin2 = 0;
	m_bin3 = 1;
	m_bin4 = 0;
	m_bin5 = 1;
	m_bin6 = 0;
	m_bin7 = 1;
}

Bin::~Bin()
{
}

void Bin::Show()
{
	cout << m_bin7;
	cout << m_bin6;
	cout << m_bin5;
	cout << m_bin4;
	cout << m_bin3;
	cout << m_bin2;
	cout << m_bin1;
	cout << m_bin0;
	cout << endl;
}

void Bin::ShowPos(int pos)
{
	bool tmp[] = { m_bin0, m_bin1, m_bin2, m_bin3, m_bin4, m_bin5, m_bin6, m_bin7 };
	
	cout << tmp[pos] << endl;
	/*
	switch (pos)
	{
	case 0:
		cout << static_cast<int>(m_bin0);
		break;
	case 1:
		cout << static_cast<int>(m_bin1);
		break;
	case 2:
		cout << static_cast<int>(m_bin2);
		break;
	case 3:
		cout << static_cast<int>(m_bin3);
		break;
	case 4:
		cout << static_cast<int>(m_bin4);
		break;
	case 5:
		cout << static_cast<int>(m_bin5);
		break;
	case 6:
		cout << static_cast<int>(m_bin6);
		break;
	case 7:
		cout << static_cast<int>(m_bin7);
		break;
	default:
		cout << "Input digit from 0 to 7";
		break;
	}
	
	cout << endl;*/
}

void Bin::Edit(int pos, int val)
{
	switch (pos)
	{
	case 0:
		m_bin0 = val;
		break;
	case 1:
		m_bin1 = val;
		break;
	case 2:
		m_bin2 = val;
		break;
	case 3:
		m_bin3 = val;
		break;
	case 4:
		m_bin4 = val;
		break;
	case 5:
		m_bin5 = val;
		break;
	case 6:
		m_bin6 = val;
		break;
	case 7:
		m_bin7 = val;
		break;
	default:
		cout << "Wrong value, input 0 or 1\n";
		break;
	}
}