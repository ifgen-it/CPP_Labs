#include "pair.h"

ostream& operator<<(ostream& os, const Pair& pair)
{
	os << pair.key << " " << pair.data;		// ���� �������� ��� ������� ������ ������ MyData, �� ������ ���������� � �������� ������, ������ ?
	return os;
}

bool Pair::operator==(const char* k) const
{
	if (strcmp(this->key.GetString(), k) == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}



