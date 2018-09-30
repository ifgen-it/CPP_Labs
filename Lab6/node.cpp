#include "node.h"


Node::Node() 
{
	pPrev = nullptr;
	pNext = nullptr;
	pShape = nullptr;
}

Node::Node(Node* p, const Shape* pOther)	// c const не хочет
{
	/*if (typeid(*pOther) == typeid(Rect))
	{
		const Rect* Source = dynamic_cast<const Rect*>(pOther);
		pShape = new Rect(*Source);
	}
	else
	{
		const Circle* Source = dynamic_cast<const Circle*>(pOther);
		pShape = new Circle(*Source);
	}*/

	pShape = pOther->Clone(); //->Clone();
	pPrev = p;
	pNext = p->pNext;

	p->pNext = this;
	pNext->pPrev = this;
}

Node::~Node()
{
	if (pPrev != 0) pPrev->pNext = pNext;
	if (pNext != 0) pNext->pPrev = pPrev;
	delete pShape;	// деструктор Shape убрал из private - может и не надо, и надо Destroy создать ?
}

Node* Node::Next()
{
	return pNext;
}

void Node::GetData(Shape*& pData) const
{
	pData = pShape;
}


