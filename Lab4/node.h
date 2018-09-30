#pragma once
#include "circle.h"


class Node
{
	friend class List;


	Node* pPrev;
	Node* pNext;
	Circle m_data;

	Node();		// used for initialization Head and Tail
	
	Node(Node* p, const Circle* data);
	~Node();

	friend ostream& operator<<(ostream& os, List& L);		// Node не хочет дружить
	
public:
	Node* Next();
	void GetData(Circle& C) const;

};

