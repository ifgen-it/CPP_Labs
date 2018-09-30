#include "mystring.h"



MyString::MyString()
{
	m_pMyCounter = nullptr;
}

MyString::MyString(const char* Str)
{
	if (Str)
	{
		//checking for existence similar Str
		Counter* pTemp = Counter::pHead;
		while (pTemp)
		{
			if (strcmp(Str,pTemp->m_pStr) == 0)
			{
				m_pMyCounter = pTemp;
				m_pMyCounter->AddUser();
				return;
			}
			pTemp = pTemp->pNext;
		}

		//if not exist
		m_pMyCounter = new Counter(Str);
	}
	else
	{
		m_pMyCounter = nullptr;
	}
	
}

MyString::MyString(const MyString& other)
{
	if (other.m_pMyCounter)
	{
		m_pMyCounter = other.m_pMyCounter;
		m_pMyCounter->AddUser();
	}
	else
	{
		m_pMyCounter = nullptr;
	}

}

MyString::MyString(MyString&& temp)
{
	if (temp.m_pMyCounter)
	{
		m_pMyCounter = temp.m_pMyCounter;
		temp.m_pMyCounter = nullptr;
	}
	else
	{
		m_pMyCounter = nullptr;
	}
}

MyString& MyString::operator=(const MyString& other)
{
	if (m_pMyCounter != other.m_pMyCounter && other.m_pMyCounter)
	{
		if (m_pMyCounter) m_pMyCounter->RemoveUser();
		m_pMyCounter = other.m_pMyCounter;
		m_pMyCounter->AddUser();
	}
	else if (!other.m_pMyCounter)
	{
		m_pMyCounter = nullptr;
	}
	return *this;
}

MyString& MyString::operator=(MyString&& temp)
{
	m_pMyCounter = temp.m_pMyCounter;
	temp.m_pMyCounter = nullptr;
	return *this;
}

MyString::~MyString()
{
	if (m_pMyCounter) m_pMyCounter->RemoveUser();
}

const char* MyString::GetStr() const
{
	if (m_pMyCounter)
	{
		return m_pMyCounter->m_pStr;
	}
	else
	{
		return "null";
	}
}

ostream& operator<<(ostream& os, const MyString& Str)
{
	os << Str.GetStr();
	return os;
}

void MyString::PrintStrings()
{
	if (!Counter::pHead)
	{
		cout << "There is no strings in the program!" << endl;
	}
	else
	{
		Counter* pTemp = Counter::pHead;
		while (pTemp)
		{
			cout << *pTemp << endl;
			pTemp = pTemp->pNext;
		}
	}

}

void MyString::SortAscStrings()
{
	if (Counter::pHead)
	{
		Counter* PNewHead = nullptr;

		while (Counter::pHead)
		{
			Counter* pTemp = Counter::pHead;
			Counter* pMax = pTemp;
			char* Max = pMax->m_pStr;
			Counter* pPrevMax = nullptr;

			// searching Max
			while (pTemp->pNext)
			{
				if (strcmp(Max, pTemp->pNext->m_pStr) == -1)
				{
					Max = pTemp->pNext->m_pStr;
					pMax = pTemp->pNext;
					pPrevMax = pTemp;
					pTemp = pTemp->pNext;
				}
				else
				{
					pTemp = pTemp->pNext;
				}
			}

			// extract Max and Add to New List to Head
			if (pPrevMax)	// if more than 1 Nodes in source List
			{
				pPrevMax->pNext = pMax->pNext;
			}
			else // if exist last node
			{
				Counter::pHead = pMax->pNext;
			}

			pMax->pNext = PNewHead;
			PNewHead = pMax;
		} // end while

		// Swap lists
		Counter::pHead = PNewHead;
		PNewHead = nullptr;
	}
	

}

void MyString::LowerStrings()
{
	Counter* pTemp = Counter::pHead;
	while (pTemp)
	{
		pTemp->Lower();
		pTemp = pTemp->pNext;
	}
}

void MyString::UpperStrings()
{
	Counter* pTemp = Counter::pHead;
	while (pTemp)
	{
		pTemp->Upper();
		pTemp = pTemp->pNext;
	}
}