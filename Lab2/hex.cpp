#include "hex.h"

Hex::Hex()
{
	m_hex0 = 13;
	m_hex1 = 10;
}

Hex::~Hex()
{
}

void Hex::Show()
{
	//static char Temp[16] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };
	static const char* Temp = "0123456789abcdef";
	cout << Temp[m_hex1];
	cout << Temp[m_hex0];
	cout << endl;
}
void Hex::ShowPos(int pos)
{
	char Temp[16] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };

	switch (pos)
	{
	case 0:
		cout << Temp[m_hex0];
		break;
	case 1:
		cout << Temp[m_hex1];
		break;
	default:
		cout << "Input digit from 0 to 1";
		break;
	}
	cout << endl;
}

void Hex::Edit(int pos, int val)
{
	switch (pos)
	{
	case 0:
		m_hex0 = val;
		break;
	case 1:
		m_hex1 = val;
		break;
	default:
		cout << "Wrong value, input digit from 0 to 15\n";
		break;
	}
}
/*
char Hex::DecToHex(unsigned char input)
{
	char Hex = '$';
	
		switch (input) {

		case 0:
			Hex = '0';
			break;
		case 1:
			Hex = '1';
			break;
		case 2:
			Hex = '2';
			break;
		case 3:
			Hex = '3';
			break;
		case 4:
			Hex = '4';
			break;
		case 5:
			Hex = '5';
			break;
		case 6:
			Hex = '6';
			break;
		case 7:
			Hex = '7';
			break;
		case 8:
			Hex = '8';
			break;
		case 9:
			Hex = '9';
			break;
		case 10:
			Hex = 'A';
			break;
		case 11:
			Hex = 'B';
			break;
		case 12:
			Hex = 'C';
			break;
		case 13:
			Hex = 'D';
			break;
		case 14:
			Hex = 'E';
			break;
		case 15:
			Hex = 'F';
			break;
		default:
			Hex = '*';
			break;
		}
	
	return Hex;
}*/