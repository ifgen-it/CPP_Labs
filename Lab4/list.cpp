#include "list.h"


List::List() : m_size(0)
{
	Head.pNext = &Tail;
	Tail.pPrev = &Head;
}

List::~List()
{
	while (Head.pNext != &Tail)
	{
		delete Head.pNext;
	}
}

void List::Truncate()
{
	while (Head.pNext != &Tail)
	{
		delete Head.pNext;
	}
	m_size = 0;
}

void List::AddToHead(const Circle* data)
{
	Node* pTemp = new Node(&Head, data);
	m_size++;
}

void List::AddToTail(const Circle* data)
{
	Node* pTemp = new Node(Tail.pPrev, data);
	m_size++;
}

bool List::RemoveFirstLike(const Circle* data)
{
	Node* pTemp = Head.pNext;
	while (pTemp != &Tail)
	{
		if (pTemp->m_data == *data)
		{
			delete pTemp;
			m_size--;
			return true;
		}
		pTemp = pTemp->pNext;
	}
	return false;
}

int List::RemoveAllLike(const Circle* data)
{
	int Counter = 0;
	Node* pTemp = Head.pNext;
	
	while (pTemp != &Tail)
	
	{
		Node* pTempNext = pTemp->pNext;
		if (pTemp->m_data == *data)
		{
	
			delete pTemp;
			m_size--;
			Counter++;
		}
			pTemp = pTempNext;
		
	}
	return Counter;
}

ostream& operator<<(ostream& os, List& L)
{
	// если добавить функцию в friend класса Node все равное не дает обратиться к pNext
	
	os << L.m_size << endl;
	Node* pTemp = L.Head.Next();
	while (pTemp != &L.Tail)
	{
		Circle C1;
		pTemp->GetData(C1);
		/*Circle C1=pTemp->m_data;*/	// в VS2017 это не работает
		os << C1;
		pTemp = pTemp->Next();
	}
	return os;
}

istream& operator>>(istream& is, List& L)
{
	L.Truncate();
	size_t Count = 0;
	is >> Count;
	
	for (size_t i = 0; i < Count; i++)
	{
		Circle C1;
		is >> C1;
		L.AddToTail(&C1);
	}
	return is;
}

void List::PrintList()
{
	Node* pTemp = Head.pNext;
	while (pTemp != &Tail)
	{
		cout << pTemp->m_data;
		pTemp = pTemp->pNext;
	}
}

void List::SortBySquare()
{
	List LTemp;
	
	while (Head.pNext != &Tail)
	{

		Node* pMin = Head.pNext;
		double Min = pMin->m_data.GetSquare();
		Node* pTemp = pMin;


		while (pTemp != &Tail)
		{
			if (pTemp->m_data.GetSquare() < Min)
			{
				Min = pTemp->m_data.GetSquare();
				pMin = pTemp;
			}
			pTemp = pTemp->pNext;
		}
		//extract pMin from List
		pMin->pPrev->pNext = pMin->pNext;
		pMin->pNext->pPrev = pMin->pPrev;

		//add it to new List to Tail
		pMin->pNext = &LTemp.Tail;
		pMin->pPrev = LTemp.Tail.pPrev;
		LTemp.Tail.pPrev->pNext = pMin;
		LTemp.Tail.pPrev = pMin;

		LTemp.m_size++;
	}

	*this = move(LTemp);
}

List& List::operator=(List&& temp)
{
	Truncate();
	Head.pNext = temp.Head.pNext;
	Tail.pPrev = temp.Tail.pPrev;
	temp.Head.pNext->pPrev = &Head;
	temp.Tail.pPrev->pNext = &Tail;
	m_size = temp.m_size;

	temp.Head.pNext = &temp.Tail;
	temp.Tail.pPrev = &temp.Head;
	temp.m_size = 0;

	return *this;
}

List::List(const List& other)
{
	m_size = 0;
	Head.pNext = &Tail;
	Tail.pPrev = &Head;

	Node* pTemp = other.Head.pNext;
	while (pTemp != &other.Tail)
	{
		AddToTail(&pTemp->m_data);
		pTemp = pTemp->pNext;
	}
}
List::List(List&& temp)
{
	Head.pNext = temp.Head.pNext;
	Tail.pPrev = temp.Tail.pPrev;
	temp.Head.pNext->pPrev = &Head;
	temp.Tail.pPrev->pNext = &Tail;
	m_size = temp.m_size;

	temp.Head.pNext = &temp.Tail;
	temp.Tail.pPrev = &temp.Head;
	temp.m_size = 0;

}

List& List::operator=(const List& other)
{
	// not optimized =
	/*Truncate();
	Node* pTemp = other.Head.pNext;
	while (pTemp != &other.Tail)
	{
		AddToTail(&pTemp->m_data);
		pTemp = pTemp->pNext;
	}*/

	// optimized =

	Node* pTempOther = other.Head.pNext;
	Node* pTempThis = Head.pNext;
	size_t MinCount = m_size < other.m_size ? m_size : other.m_size;

	//first action
	for (size_t i = 0; i < MinCount; i++)
	{
		pTempThis->m_data = pTempOther->m_data;
		pTempThis = pTempThis->pNext;
		pTempOther = pTempOther->pNext;
	}

	//second action

	// if OtherList is longer
	if (m_size < other.m_size)	//(pTempThis == &Tail)
	{
		while (pTempOther != &other.Tail)
		{
			AddToTail(&pTempOther->m_data);
			pTempOther = pTempOther->pNext;
		}
	}
	// if ThisList is Longer
	else if (m_size > other.m_size) // (pTempOther == &other.Tail)
	{
		Node* pTempThisPrev = pTempThis->pPrev;
		while (pTempThisPrev->pNext != &Tail)
		{
			delete pTempThisPrev->pNext;
			m_size--;
		}
	}
	
	return *this;
}
