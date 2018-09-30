#pragma once
#include "node.h"
#include "shape.h"

class List
{
	Node Head;
	Node Tail;
	unsigned int m_size;

public:
	List();
	~List();
	List(const List& other);
	List(List&& temp);
	List& operator=(const List& other);
	List& operator=(List&& temp);

	void AddToHead(const Shape* pOther);
	void AddToTail(const Shape* pOther);
	bool RemoveFirstLike(const Shape* pOther);
	int RemoveAllLike(const Shape* pOther);
	void Truncate();

	void PrintList();

	void Sort(const char* mode);
	
	friend ostream& operator<<(ostream& os, List& L);
	friend istream& operator>>(istream& is, List& L);  


};


