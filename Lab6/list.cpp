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

void List::AddToHead(const Shape* pOther)		
{
	Node* pTemp = new Node(&Head, pOther);
	m_size++;
}

void List::AddToTail(const Shape* pOther)	
{
	Node* pTemp = new Node(Tail.pPrev, pOther);
	m_size++;
}


bool List::RemoveFirstLike(const Shape* pOther)
{
	Node* pTemp = Head.pNext;
	while (pTemp != &Tail)
	{
		const Shape* pSource = pTemp->pShape;
		if (*pSource == *pOther)
		{
			delete pTemp;
			m_size--;
			return true;
		}
		pTemp = pTemp->pNext;
	}
	return false;
}

int List::RemoveAllLike(const Shape* pOther)
{
	int Counter = 0;
	Node* pTemp = Head.pNext;
	
	while (pTemp != &Tail)
	{
		Node* pTempNext = pTemp->pNext;
		const Shape* pSource = pTemp->pShape;
		if (*pSource == *pOther)
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
		Shape* pData;
		pTemp->GetData(pData);
		
		os << *pData;
		//os << *pData << "Square: " << pData->Square() << endl;
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
		char WhatShape[9];
		is >> WhatShape;
		if (strcmp(WhatShape, "Rect") == 0)	//Rect
		{
			Rect R1;
			is >> R1;
			L.AddToTail(&R1);
		}
		else if (strcmp(WhatShape, "Circle") == 0) //Circle
		{
			Circle C1;
			is >> C1;
			L.AddToTail(&C1);
		}

	}
	return is;
}


void List::PrintList()
{
	Node* pTemp = Head.pNext;
	while (pTemp != &Tail)
	{
		cout << *(pTemp->pShape);
		pTemp = pTemp->pNext;
	}
}


void List::Sort(const char* mode)
{
	
	int CaseMode = 0;
	if (strcmp(mode, "square") == 0)
	{
		CaseMode = 1;
	}
	else if (strcmp(mode, "color") == 0)
	{
		CaseMode = 2;
	}
	if (CaseMode == 0) { return; }

	Node* pSorted = Head.pNext;
	double Min1;
	Shape::Color Min2;

		while (pSorted->pNext != &Tail)
		{
			Node* pMin = pSorted;
			switch (CaseMode)
			{
			case 1:
				Min1 = pMin->pShape->Square();				// square
				break;
			case 2:
				Min2 = pMin->pShape->GetColor();		// color 
				break;
			}
			Node* pTemp = pMin->pNext;
			while (pTemp != &Tail)
			{
				switch (CaseMode)
				{
				case 1:
					if (pTemp->pShape->Square() < Min1)			// Square 
					{
						Min1 = pTemp->pShape->Square();
						pMin = pTemp;
					}
					break;

				case 2:
					if (pTemp->pShape->GetColor() < Min2)		// Color 
					{
						Min2 = pTemp->pShape->GetColor();			
						pMin = pTemp;
					}
					break;
				}
				pTemp = pTemp->pNext;
			}
			//swap 
			if (pSorted != pMin)
			{
				Shape* pTemp = pSorted->pShape;
				pSorted->pShape = pMin->pShape;
				pMin->pShape = pTemp;
			}
			pSorted = pSorted->pNext;
		}
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
		AddToTail(pTemp->pShape);
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

	Node* pTempOther = other.Head.pNext;
	Node* pTempThis = Head.pNext;
	size_t MinCount = m_size < other.m_size ? m_size : other.m_size;

	//first action
	for (size_t i = 0; i < MinCount; i++)
	{
		/*if (typeid(*pTempOther->pShape) == typeid(Rect))
		{
			Rect* Source = dynamic_cast<Rect*>(pTempOther->pShape);
			pTempThis->pShape = new Rect(*Source);
		}
		else
		{
			Circle* Source = dynamic_cast<Circle*>(pTempOther->pShape);
			pTempThis->pShape = new Circle(*Source);
		}*/

		if (typeid(pTempOther->pShape) == typeid(pTempOther->pShape))
		{
			*pTempThis->pShape = *pTempOther->pShape;
		}
		else
		{
			delete pTempThis->pShape;
			pTempThis->pShape = pTempOther->pShape->Clone();
		}


		pTempThis = pTempThis->pNext;
		pTempOther = pTempOther->pNext;
	}

	//second action

	// if OtherList is longer
	if (m_size < other.m_size)	//(pTempThis == &Tail)
	{
		while (pTempOther != &other.Tail)
		{
			AddToTail(pTempOther->pShape);
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
