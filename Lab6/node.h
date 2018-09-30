#pragma once
#include "shape.h"
#include "circle.h"
#include "rect.h"


class Node
{
	friend class List;


	Node* pPrev;
	Node* pNext;
	Shape* pShape;

	Node();		// used for initialization Head and Tail
	
	Node(Node* p, const Shape* pOther);
	~Node();

	friend ostream& operator<<(ostream& os, List& L);		// Node не хочет дружить
	
public:
	Node* Next();
	void GetData(Shape*& pData) const;


};

