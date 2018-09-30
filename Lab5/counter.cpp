#include "counter.h"


//static members variables
Counter* Counter::pHead = nullptr;
unsigned int Counter::m_curCounters;

//Counter::Counter()	//убрал за ненадобностью
/*{
	m_nOwners = 1;
	m_pStr = nullptr;
	AddToHead();
}*/

Counter::Counter(const char* Str)
{
	m_nOwners = 1;

	size_t n = strlen(Str) + 1;
	m_pStr = new char[n];
	strcpy(m_pStr, Str);
	AddToHead();
}

void Counter::AddToHead()
{
	//if (pHead)
	//{
	//	pNext = pHead;
	//	pHead = this;
	//}
	//else
	//{
	//	pHead = this;
	//	pNext = nullptr;
	//}
	pNext = pHead;
	pHead = this;
	m_curCounters++;
}

Counter::~Counter()
{
	delete[] m_pStr;
}

void Counter::AddUser() { m_nOwners++; }

void Counter::RemoveUser()
{
	m_nOwners--;
	if (m_nOwners == 0)
	{
		if (pHead == this)
		{
			pHead = this->pNext;
		}
		else
		{
			Counter* pTemp = pHead;
			while (pTemp)
			{
				if (pTemp->pNext == this)
				{
					pTemp->pNext = this->pNext;
					break;
				}
				pTemp = pTemp->pNext;
			}
		}
		delete this;
	}
}

const char* Counter::GetStr() const
{
	if (m_pStr)
	{
		return m_pStr;
	}
	else
	{
		return "null";
	}
}

ostream& operator<<(ostream& os, const Counter& C)
{
	os << C.m_nOwners << " " << C.GetStr();
	return os;
}

void Counter::Lower()
{
	char* p = m_pStr;
	while (*p)
	{
		if (*p >= 'A' && *p <= 'Z')
		{
			*p = *p + 32;
		}
		p++;
	}
}

void Counter::Upper()
{
	char* p = m_pStr;
	while (*p)
	{
		if (*p >= 'a' && *p <= 'z')
		{
			*p = *p - 32;
		}
		p++;
	}
}