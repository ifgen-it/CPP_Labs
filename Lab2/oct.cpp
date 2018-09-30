#include "oct.h"

Oct::Oct()
{
	m_oct0 = 7;
	m_oct1 = 7;
	m_oct2 = 3;
}

Oct::~Oct()
{
}

void Oct::Show()
{
	cout << static_cast<int>(m_oct2);
	cout << static_cast<int>(m_oct1);
	cout << static_cast<int>(m_oct0);
	cout << endl;
}
void Oct::ShowPos(int pos)
{
	int tmp[] = { static_cast<int>(m_oct0), static_cast<int>(m_oct1), static_cast<int>(m_oct2) };

	cout << tmp[pos] << endl;
	/*
	switch (pos)
	{
	case 0:
		cout << static_cast<int>(m_oct0);
		break;
	case 1:
		cout << static_cast<int>(m_oct1);
		break;
	case 2:
		cout << static_cast<int>(m_oct2);
		break;
	default:
		cout << "Input digit from 0 to 7";
		break;
	}
	cout << endl;*/
}
void Oct::Edit(int pos, int val)
{
	switch (pos)
	{
	case 0:
		m_oct0 = val;
		break;
	case 1:
		m_oct1 = val;
		break;
	case 2:
		m_oct2 = val;
		break;
	default:
		cout << "Wrong value, input digit from 0 to 7\n";
		break;
	}
}