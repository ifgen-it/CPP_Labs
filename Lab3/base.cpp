#include "base.h"

Base::Base()
{
	pBase = nullptr;
	count = 0;
	capacity = 0;
}

Base::~Base()
{
	for (size_t i = 0; i < count; i++)
	{
		delete pBase[i];
	}
	delete[] pBase;
}

Base::Base(const Base& bd)	// как оптимизировать?
{
	capacity = count = bd.count;
	pBase = nullptr;
	if (bd.pBase)
	{
		pBase = new Pair*[count];
		// copying all existing pairs using copy-constructor
		for (size_t i = 0; i < count; i++)
		{
			pBase[i] = new Pair(*bd.pBase[i]);
		}
	}
}


Base& Base::operator=(Base& bd)
{

	if (bd.count > capacity)
	{
		capacity = bd.count;
		Pair** pTemp = new Pair*[capacity];
		//copying pointers 
		for (size_t i = 0; i < count; i++)
		{
			pTemp[i] = pBase[i];
		}
		delete[] pBase;
		pBase = pTemp;
		pTemp = nullptr;
	}

	//copying new data to existing pairs
	size_t MinCount = count < bd.count ? count : bd.count;

	for (size_t i = 0; i < MinCount; i++)
	{
		*pBase[i] = *bd.pBase[i];
	}

	if (count < bd.count)
	{
		// adding new pairs
		for (size_t i = count; i < bd.count; i++)
		{
			pBase[i] = new Pair(*bd.pBase[i]);
		}
		count = bd.count;
	}
	else
	{
		// adding new pairs
		for (size_t i = bd.count; i < count; i++)
		{
			delete pBase[i];
		}
		count = bd.count;
	}
	
	
	return *this;
}

Base& Base::operator=(Base&& bd)
{
	for (size_t i = 0; i < capacity; i++)
	{
		delete pBase[i];
	}
	delete pBase;

	count = bd.count;
	capacity = bd.capacity;
	pBase = nullptr;
	if (bd.pBase)
	{
		pBase = bd.pBase;
		bd.pBase = nullptr;
		bd.capacity = bd.count = 0;
	}
	return *this;
}

Base::Base(Base&& bd)
{
	capacity = count = bd.count;
	pBase = nullptr;
	if (bd.pBase)
	{
		pBase = bd.pBase;
		bd.pBase = nullptr;
		bd.capacity = bd.count = 0;
	}
}

int Base::deletePair(const char* k)
{
	// if exist key
	for (size_t i = 0; i < count; i++) {
		if (*pBase[i] == k)
		{
			delete pBase[i];
			pBase[i] = nullptr;

			// shift towards head
			for (size_t j = i; j < count-1; j++)
			{
				pBase[j] = pBase[j + 1];
			}
			count--;
			return 1;
		}
	}
	return 0;
}

MyData& Base::operator[](const char* k)
{
	size_t Delta = 4;
	
		// if exist key
		for (size_t i = 0; i < count; i++) {
			if (*pBase[i] == k)
			{
				return pBase[i]->data;
			}
		}

		// if don't exist key need to insert data into base
		if (count >= capacity)
		{
			// need to increase capacity
			capacity += Delta;
			Pair** pTemp = new Pair*[capacity];
			//copying
			for (size_t i = 0; i < count; i++)
			{
				pTemp[i] = pBase[i];
			}
			delete[] pBase;
			pBase = pTemp;
			pTemp = nullptr;
		}

		pBase[count] = new Pair;
		pBase[count]->key = k;
		count++;
		return pBase[count-1]->data;
	
}

ostream& operator<<(ostream& os, Base& bd)
{
	if (bd.pBase)
	{
		os << "============== DATABASE ==============" << endl;
		os << "Capacity: " << bd.capacity << endl;
		os << "Count: " << bd.count << endl;
		os << "--------------------------------------" << endl;
	for (size_t i = 0; i < bd.count; i++)
		{
			os << *bd.pBase[i] << endl;
		}
	
	}
	else
	{
		os << "Empty" << endl;
	}
	return os;
}