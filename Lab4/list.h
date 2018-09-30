#pragma once
#include "node.h"

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

	void AddToHead(const Circle* data);
	void AddToTail(const Circle* data);
	bool RemoveFirstLike(const Circle* data);
	int RemoveAllLike(const Circle* data);
	void Truncate();

	void PrintList();

	void SortBySquare();
	
	friend ostream& operator<<(ostream& os, List& L);
	friend istream& operator>>(istream& is, List& L);


};


