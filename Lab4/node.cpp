#include "node.h"


Node::Node() 
{
	pPrev = nullptr;
	pNext = nullptr;
}

Node::Node(Node* p, const Circle* data) : m_data(*data)
{
	pPrev = p;
	pNext = p->pNext;

	p->pNext = this;
	pNext->pPrev = this;
}

Node::~Node()
{
	if (pPrev != 0) pPrev->pNext = pNext;
	if (pNext != 0) pNext->pPrev = pPrev;
}

Node* Node::Next()
{
	return pNext;
}

void Node::GetData(Circle& C) const
{
	C = m_data;
}