

template<typename C> void Print(const C& cont)
{

	/*C::const_iterator itb = cont.begin();
	C::const_iterator ite = cont.end();*/

	auto itb = cont.begin();
	auto ite = cont.end();

	cout << "-----------------------------------" << endl;
	cout << "Container : " << typeid(cont).name() << endl << endl;
	cout << "type of elements: " << typeid(*itb).name() << endl << endl;
	while (itb != ite)
	{
		cout << *itb << " ";
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

template<typename T> void PrintVector(const vector<T>& v)
{
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << ", ";
	}
	cout<< endl;
}

template<typename T> void PrintVector(const vector<T*>& v)
{
	for (int i = 0; i < v.size(); i++)
	{
		if ( v[i] ) { cout << *(v[i]) << " "; }
		else { cout << "Empty "; }
	}
	cout<< endl;
}

void PrintVector(vector<char>& v)
{
	for (size_t i = 0; i < v.size(); i++)
	{
		cout << v[i] ;
	}
	cout<< endl;
}


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

/*template<typename T> void PrintList(list<T>& l)
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



/*
template<typename T> ostream& operator<<(ostream& os, const vector<vector<T>>& vv)
{
	for (int j = 0; j < vv.size(); j++)
	{
		PrintVector(vv[j]);
	}

	return os;
}*/

template<typename T> ostream& operator<<(ostream& os, const vector<T>& vv)
{
	for (int j = 0; j < vv.size(); j++)
	{
		os << vv[j];
	}
	os << endl;

	return os;
}



template <typename T> void EraseDouble(vector<T>& v)
{
	auto it1 = v.begin();
	
	while (it1 != v.end())
	{
		auto it2 = it1 + 1;
		if (it2 == v.end()) break;
		while (it2 != v.end() && *it2 == *it1)
		{
			++it2;
		}
		if (it2 - it1 > 1) it1 = v.erase(it1, it2);
		else ++it1;
	}
}