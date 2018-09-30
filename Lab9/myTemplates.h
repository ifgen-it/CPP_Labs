#pragma once
#include "point.h"

template<typename T> struct LessChar {

	bool operator()(T x, T y) const
	{
		return strcmp(x, y) < 0;
	}

};

struct Cond {

	bool operator()(const char* x, const char* y) const
	{
		return strcmp(x, y) < 0;
	}
};

template<typename A> void PrintAd(A ad)
{
 	cout << "-----------------------------------" << endl;
	cout << "Adaptor : " << typeid(ad).name() << endl;
	cout << "Type of elements: " << typeid(ad.top()).name() << endl << endl;

	while (ad.size())
	{
	//	надо так: cout << Mytop(ad) << " ";
		cout << ad.top() << " ";
		ad.pop();
	}
	cout << endl << "-----------------------------------" << endl;
}


// надо убрать
template<typename T, typename C> void PrintAd(queue<T*, C> ad)
{
	cout << "-----------------------------------" << endl;
	cout << "Adaptor : " << typeid(ad).name() << endl;
	cout << "Type of elements: " << typeid(ad.front()).name() << endl << endl;

	while (ad.size())
	{
		cout << *(ad.front()) << " | ";
		ad.pop();
	}
	cout << endl << "-----------------------------------" << endl;
}

// надо убрать
template<typename T, typename C> void PrintAd(queue<T, C> ad)
{
	cout << "-----------------------------------" << endl;
	cout << "Adaptor : " << typeid(ad).name() << endl;
	cout << "Type of elements: " << typeid(ad.front()).name() << endl << endl;

	while (ad.size())
	{
		cout << ad.front() << " ";
		ad.pop();
	}
	cout << endl << "-----------------------------------" << endl;
}



template<typename T> void PrintAr(const T* Ar, int n)
{
	for (size_t i = 0; i < n; i++)
	{
		cout << Ar[i] << " ";
	}
	cout << endl;
}

template<typename C> void Print(const C& cont)
{

	/*C::const_iterator itb = cont.begin();
	C::const_iterator ite = cont.end();*/

	auto itb = cont.begin();
	auto ite = cont.end();

	cout << "-----------------------------------" << endl;
	cout << "Container : " << typeid(cont).name() << endl;
	cout << "type of elements: " << typeid(*itb).name() << endl << endl;
	while (itb != ite)
	{
		cout << *itb << ", ";
		++itb;
	}
	cout << endl << "-----------------------------------" << endl;
}


bool Neg(const Point& t)
{
	int x = 1;
	int y = 1;
	t.GetPoint(x, y);
	return x < 0 || y < 0;
}


template<typename T> void PrintVectProp(vector<T>& v)
{
	cout << "Vector's properties:"<<endl;
	cout << "size: "<< v.size()<<endl;
	cout <<"capacity: "<< v.capacity()<< endl;
	cout << "max size: "<< v.max_size() << endl;
}




void PrintList(list<char>& l)
{
//	list<T>::iterator 
    auto itb = l.begin();
//	list<T>::iterator
    auto ite = l.end();
	while (itb != ite)
	{
		cout << *itb ;
		++itb;
	}
	cout<< endl;
}

template<typename T, typename C> void PrintSet(set<T, C>& s)
{
	auto itb = s.begin();
	auto ite = s.end();
	while (itb != ite)
	{
		cout << *itb << ", ";
		++itb;
	}
	cout << endl;
}

template<typename T, typename C> void PrintMSet(multiset<T, C>& s)
{
	auto itb = s.begin();
	auto ite = s.end();
	while (itb != ite)
	{
		cout << *itb << ", ";
		++itb;
	}
	cout << endl;
}

template<typename T> void PrintVector(vector<T>& v)
{
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << ", ";
	}
	cout<< endl;
}

template<typename T> void PrintVector(vector<T*>& v)
{
	for (int i = 0; i < v.size(); i++)
	{
		if ( v[i] ) { cout << *(v[i]) << " "; }
		else { cout << "Empty "; }
	}
	cout<< endl;
}

/*void PrintVector(vector<char>& v)
{
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] ;
	}
	cout<< endl;
}*/

template<typename C> void PrintListDeque(C& con)
{
	//	list<T>::iterator 
	auto itb = con.begin();
	//	list<T>::iterator
	auto ite = con.end();
	while (itb != ite)
	{
		cout << *itb << ", ";
		++itb;
	}
	cout << endl;
}

/*
template<typename T> void PrintList(list<T>& l)
{
	//	list<T>::iterator 
	auto itb = l.begin();
	//	list<T>::iterator
	auto ite = l.end();
	while (itb != ite)
	{
		cout << *itb << ", ";
		++itb;
	}
	cout << endl;
}

// объединить с PrintList
template<typename T> void PrintDeque(deque<T>& d)
{
//	list<T>::iterator 
    auto itb = d.begin();
//	list<T>::iterator
    auto ite = d.end();
	while (itb != ite)
	{
		cout << *itb << ", ";
		++itb;
	}
	cout<< endl;
}
*/