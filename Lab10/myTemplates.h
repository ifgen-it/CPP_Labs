#pragma once
#include "point.h"
#include "rect.h"

char Low(char x)
{
	if (x >= 'A' && x <= 'Z') x += 32;
	
	return x;
}

string BigLow(string x)
{
	transform(x.begin(), x.end(), x.begin(), Low);
	return x;
}


bool Pred1(int l, int r)
{
	return abs(l) < abs(r);
}


bool PredRect(Rect l, Rect r)
{
	int left1, right1, top1, bottom1;
	l.GetRect(left1, right1, top1, bottom1);

	int left2, right2, top2, bottom2;
	r.GetRect(left2, right2, top2, bottom2);

	double x1 = (right1 + left1) / 2.0;
	double y1 = (top1 + bottom1) / 2.0;
	double x2 = (right2 + left2) / 2.0;
	double y2 = (top2 + bottom2) / 2.0;

	double rad1 = pow((x1*x1 + y1 * y1), 0.5);
	double rad2 = pow((x2*x2 + y2 * y2), 0.5);

	return rad1 < rad2;

}


class Range
{
	int m_x1;
	int m_x2;
public:
	Range(int x1, int x2): m_x1(x1), m_x2(x2) {}

	bool operator()(const Point& p) const
	{
		int x, y;
		p.GetPoint(x, y);
		return (x >= m_x1) && (x <= m_x2);
	}

};


template<typename T> void PrintF(T x)
{
	cout << x << " ";
}

template<typename T> void AddDelta(T& pt)
{
	pt = pt + 5;
}

/*
template<typename Key, typename Val>
void PrintMap(map<Key, Val> m)
{
    	//typedef map<Key, Val>::iterator IT;
    	
    	map<Key, Val>::iterator it1 = m.begin(), it2 = m.end();
    	while (it1 != it2)
    	{
    		cout << it1->first << " "<< it1->second << endl;
    		++it1;	
    	}
}
*/
template<typename T> struct LessChar {
	
	bool operator()(T x, T y) const
	{
		return strcmp(x, y) < 0;
	}
	
};

struct Cond {

	bool operator()(const char* x, const char* y) const
	{
		return strcmp(x, y) == -1;
	}
};

template<typename A> void PrintAd(A ad)
{
 	cout << "-----------------------------------" << endl;
	cout << "Adaptor : " << typeid(ad).name() << endl;
	cout << "Type of elements: " << typeid(ad.top()).name() << endl << endl;

	while (ad.size())
	{
		cout << ad.top() << " ";
		ad.pop();
	}
	cout << endl << "-----------------------------------" << endl;
}

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



template<typename T, typename C> void PrintSet(set<T, C>& s)
{
    auto itb = s.begin();
    auto ite = s.end();
	while (itb != ite)
	{
		cout << *itb << ", ";
		++itb;
	}
	cout<< endl;
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
	cout<< endl;
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
