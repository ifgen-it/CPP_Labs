// ���������� STL: 
//stack, queue, priority_queue
//set, multiset, map, multimap


//#include "stdafx.h"
#include <tchar.h>
#include <deque>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <list>
#include <vector>
#include <string>
#include <clocale>
#include <algorithm>
#include <functional>	// for greater

#include <iostream>

using namespace std;

#include "myTemplates.h"
#include "point.h"

#define stop __asm nop

int _tmain(int argc, _TCHAR* argv[])
{
	

	/*const int n = 8;
	int ar[n] = {1,5,6,2,8,9,3,99};

	PrintAr(ar, n);
	make_heap(ar, ar + n-1);
	PrintAr(ar, n);
	push_heap(ar, ar + n);
	PrintAr(ar, n);
	pop_heap(ar, ar + n);
	PrintAr(ar, n);*/
	
	
	//�������� ������ ������� ��� ������ �������� stack, queue, priority_queue
	//�������� �������� �� ��, ��� ���������� ������������� ������ ������ ��� 
	//��������� ��������
	
	
	/*{
		vector<int> v1;
		v1.push_back(5);
		v1.push_back(6);
		v1.push_back(7);
		v1.push_back(4);
		Print(v1);

		queue<int, list<int>> q1;
		for (size_t i = 0; i < v1.size(); i++)
		{
			q1.push(v1[i]);
		}
		cout << "Queue:" << endl;
		PrintAd(q1);


		stack<int, vector<int>> s1(v1);
		cout << "Stack:" << endl;
		PrintAd(s1);


		priority_queue<int, vector<int>, greater<int>> p1(v1.begin(), v1.end());
		cout << "Priority_queue:" << endl;
		PrintAd(p1);
	}*/


	////////////////////////////////////////////////////////////////////////////////////
	//stack

	//�������� ���� ����� �������, �����
	//�) �������� ����� ����� ������� ��������� �������
	// ������� ����

	//�) ��� ������ �������� ��� �������, ��� � ����� ������� �������� ��� ���������� 

	/*{
		vector<int> v1;
		v1.push_back(5);
		v1.push_back(6);
		v1.push_back(7);
		v1.push_back(4);
		Print(v1);

		auto itrb = v1.rbegin();
		auto itre = v1.rend();

		stack<int> s2(deque<int>(itrb,itre));
		//while (itrb != itre)
		//{
		//	s2.push(*itrb);
		//	++itrb;
		//}
		cout << "Stack printed like vector:" << endl;
		PrintAd(s2);

	}*/


	////////////////////////////////////////////////////////////////////////////////////
	//queue

	//�������� �������, ������� �������� ��������� �� ������� ���� Point,
	//��� ���� ���� ������� ������� ���������.
	//�������� �������� ������� � ���������� ��������� ����������� front() � back()
	//���������, ��� ��������� ������� ��� ����������� ����� �������?

	/*{
		queue<Point*, list<Point*> > q2;

		q2.push(new Point(1, 4));
		q2.push(new Point(3, 8));
		q2.push(new Point(9, 14));
		q2.push(new Point(23, 44));

		PrintAd(q2);

		cout << "front: " << *q2.front() << endl;
		cout << "back: " << *q2.back() << endl;

		*q2.front() = Point(100, 100);
		*q2.back() = Point(999, 999);

		cout << endl << "Changed front and back:" << endl;
		PrintAd(q2);
		
		while (q2.size())
		{
			delete 	q2.front();
			q2.pop();
		}

	}*/


	////////////////////////////////////////////////////////////////////////////////////
	//priority_queue
	//�) �������� ������� � ������������, ������� ����� ������� ������ ��������� ��������� - const char*
	//�) ������������������ ������� ��� �������� � ������� ���������������� ������� � ���������� const char*
	//�) ��������� "���������������" �������� (� ������� pop() ) - ���� ��� ����������� �� ��������������, ���������:
	//		��� ������������ ��� �������?

	/*{
		const char* ar[] = {"DDDD", "CCCC", "aaaa", "BBBB"};

		priority_queue<const char*, vector<const char*>, Cond> P3(ar, ar + sizeof(ar)/sizeof(ar[0]));

		PrintAd(P3);
		P3.push("AAA");
		PrintAd(P3);

	}*/


	////////////////////////////////////////////////////////////////////////////////////
	//set
	//a) �������� ��������� � ���������� ���� Point - ���������, ��� ���������� ����������
	//		� ������ Point (� ����� �������)
	//�) ������������ �������� ��������� � ������� �������, �������������� � ���������� ���. ������
	//�) ���������� �������� ����� ��������...
	//�) �������� ��� ���������, ������� ����� ��������� ���������� ��������
	//		���� int, �� ���������� � ������ �������
	//�) �������� � ����� ��������� �������� ��������� �� ������ �������
	//	����������, ��������, ��������� �������	(��� ����������, ���� � ������� ������� �����?)

	/*{

		set<int> s1;
		s1.insert(3);
		s1.insert(9);
		s1.insert(1);

		pair<set<int>::iterator, bool> res;
		res = s1.insert(2);
		cout << "This value " << *res.first << (res.second ? (" was inserted in the set") : (" have been in the set yet")) << endl << endl;
		Print(s1);

		int ar[] = {23, 0, 99};
		s1.insert(ar, ar + 3);
		Print(s1);

		s1.insert({-3, 555});
		Print(s1);

		set<int>::iterator it1 = s1.begin();
		set<int>::reverse_iterator itrb = s1.rbegin(), itre = s1.rend();
		while (itrb != itre)
		{
			cout << *itrb << " ";
			++itrb;
		} cout << endl;

	}*/

	
	/*{
		set<Point> sp1 = {Point(3,4), Point(0,1), Point(99,45), Point(-23, -67)};
		Print(sp1);
		
		set<Point>::iterator it1 = sp1.begin();
		//*it1 = Point(0, 0);	�����, ������ ��� ������ �������� ���������, ����� ������ �� ���������������

		int ar2[] = { 23, 0, 56, 1, 3, 99 , 23, 1};
		set<int> s2(ar2, ar2 + 8);
		Print(s2);

		int ar3[] = { 56, 1, 0, 3, 23, 1, 99 };
		set<int> s3(ar3, ar3 + 7);
		Print(s3);
		// ��� ��������� ���������� ����������
		
		auto it_beg = s3.upper_bound(3);	// ���� 3
		auto it_end = s3.lower_bound(60);	// ���� 60

		set<int> s4(it_beg, it_end);
		Print(s4);
	}*/

	////////////////////////////////////////////////////////////////////////////////////
	//map, multiset
	//�) �������� map, ������� ������ ���� "�������, ��������" - pair<const char*, int>,
	//	��� ���� ������ �������� ���������� ����������
	//�) ��������� ��������� ���������� ����������� operator[] � insert()
	//�) ������������ ����������

	//�) �������� ���� �� ������ �� ����� (���� "�������", ����� ����� => ����� "�������")



/*{
	typedef map<const char*, int, Cond
		//LessChar<const char*>
	> MAP;
	typedef map<const char*, int>::iterator IT;
	typedef pair<const char*, int> PAIR;

	MAP m1;

	m1["Smirnov"] = 800;
	m1.insert(pair<const char*, int>("Neratova", 1000));
	m1["Rovchakov"] = 1200;
	m1["Rovchakov"] = 3200;
	m1["Petrova"] = 700;

	//	PrintMap(m1);
	IT it1 = m1.begin(), it2 = m1.end();

	while (it1 != it2)
	{
	cout << it1->first << " "<< it1->second << endl;
	++it1;
	}

	//replaceable Key
	const char* KeyFind = "Petrova";
	const char* KeyUpdate = "Ivanova";

	IT it3 = m1.find(KeyFind);
	cout << endl << "Searched key value:" << endl;
	cout << it3->first << " " << it3->second << endl;
	int ValUpdate = it3->second;
	m1.erase(it3);

	//insert updated pair
	m1.insert(PAIR(KeyUpdate, ValUpdate));

	//print base
	cout << endl << "Updated base:" << endl;
	it1 = m1.begin(), it2 = m1.end();

	while (it1 != it2)
	{
	cout << it1->first << " "<< it1->second << endl;
	++it1;
	}

	}*/



	//�) ����������� ����� �������� ������ � ���������� ���� string.
	//�������� (� ������������ ��� ��������) map<string, int>, ������� �����
	//��������� ������������� �� �������� ������ �
	//���������� ���������� ������ ������ � �������

	/*{
	vector<string> v = { "One", "first", "end", "Begin", "One", "One", "end" };
	Print(v);

	map<string, int, greater<string> > m;

	typedef map<string, int>::iterator IT;
	typedef pair<string, int> PAIR;

	vector<string>::iterator itVb = v.begin(), itVe = v.end();

	//insertion in map
	while (itVb != itVe)
	{
	//pair<IT, bool> p1 = m.insert(
	//PAIR(*itVb , 1) );

	////cout << "Result of insert:"<< endl;
	////cout << p1.first->first << " " << p1.first->second <<" " << p1.second << endl;
	//if (p1.second == false )
	//{
	//p1.first->second++;
	//}
	m[*itVb]++;	// �������� ��, ��� ����


	++itVb;
	}

	//print map
	cout << endl << "Map:" << endl;
	IT it1 = m.begin(), it2 = m.end();
	while (it1 != it2)
	{
	cout << it1->first << " "<< it1->second << endl;
	++it1;
	}
	// end print map

	}*/


	//�) 
	//����� ������:
	//const char* words[] = {"Abba", "Alfa", "Beta", "Beauty" ,...};
	//�������� map, � ������� ������ ����� ����� ��������������� ������������ 
	//��������������� ������������� ����, ������������ � ���� �����.
	//���������: �� ����� ������� ����� ����� � ��� �� ������

	//'A' -  "Abba" "Alfa"
	//'B' -  "Beauty" "Beta"  ...
	//...


	/*{
	const char* words[] = {"Abba", "Castrol", "Abba","C+++", "Alfa", "Beta", "Beauty" , "data base", "Gamma", "delta", "C++", "Cpp", "CPP" , "connect", "access", "C++" , "CAS", "da"  };

	vector<const char*> v1(words, words + sizeof (words)/sizeof (words[0]));
	Print(v1);

	typedef set<const char*, Cond 
		//LessChar<const char*>
	> SET;
	typedef pair<map<char, SET>::iterator, bool> MapPair;
	typedef map<char, SET>::iterator MapIt;

	map<char, SET> m1;
	vector<const char*>::iterator itVb = v1.begin(), itVe = v1.end();
	while (itVb != itVe)
	{
	const char* Val = *itVb;
	char Key = *Val;

	//MapIt MP = m1.find(Key);
	//if ( MP == m1.end() )
	//{
	//SET s1;
	//s1.insert(Val);
	//m1.insert(pair<char, SET>(Key, s1));
	//}
	//else
	//{
	//MP->second.insert(Val);
	//}
	m1[Key].insert(Val); // ��������
	++itVb;
	}

	//print map
	cout << endl << "Map:" << endl<< endl;
	MapIt mit1 = m1.begin(), mit2 = m1.end();
	while (mit1 != mit2 )
	{
	cout << mit1->first << "-" << mit1->second.size() << ": " << endl;
	PrintSet(mit1->second);
	cout << endl;
	++mit1;
	}
	}*/


	//�)
	//�������� ��������� ������, ������� ����� ������� ���������� � ������������ �������.
	//��� ������ ������ ������ �������� ������� ��������� (�� ��������). ��� ���� 
	//������� ����� �������������
	//���� ������ ���� ������ ���� ����������� �� ������
	//
	//������ 


	/*{
	typedef multiset<const char*, LessChar<const char*>> MSET;

	typedef map<int, MSET> MAP;
	typedef MAP::iterator MIT;
	MAP m1;

	MSET s1 = { "Smirnov", "Gorskih", "Nazmiev", "Vakuluk", "Gorskih" };
	m1[1] = s1;

	MSET s2 = { "Ivasik", "Gribanov", "Marchuk", "Ivasik", "Ivasik" };
	m1[2] = s2;

	MSET s3 = { "Dolotova", "Raskin", "Kurie", "Raskin", "Svishev" };
	m1[3] = s3;

	MSET s4 = { "Fadeeva", "Murat", "Antoch", "Shavkunova" };
	m1[4] = s4;

	//print map
	cout << "map:" << endl<<endl;

	MIT it1 = m1.begin(), it2 = m1.end();
	while (it1 != it2)
	{
	cout << "PRG.IS.2." << it1->first << ":" << endl;
	PrintMSet(it1->second);
	cout << endl;
	++it1;
	} // end of print map

	}*/

	////////////////////////////////////////////////////////////////////////////////////
	//multimap
	//�) �������� "�����-�������" �������, ��� ������ � ���� �� ����� ����� ���������������
	//		��������� ������� �������� - pair<string,string>, ��������: strange: �����, ��������...
	//�) ��������� ������� ������ � ������� ������ insert ��� ������������������ � ������� 
	//		���������������� ������� ���� (���� ����� �������������� ��� ��������� � ������� ������� make_pair)
	//�) �������� ��� ���������� ������� �� �����
	//�) �������� �� ����� ������ �������� "���������" ��� ��������� �����. ���������: ��� ���������� ���������
	//		���������� ����� ������������ ������ lower_bound() � upper_bound()

  /*{
	  typedef multimap<string, string> MMAP;
	  typedef MMAP::iterator MIT;

	  const char* ar[][2] = { "item", "punkt",
		  "item", "vopros",
		  "item", "novost",
		  "catch", "lovit",
		  "template", "shablon",
		  "template", "lekalo" };

	  MMAP m1;
	  size_t n = sizeof(ar) / sizeof(ar[0]);
	  for (size_t i = 0; i < n; i++)
	  {
		  m1.insert(make_pair(ar[i][0], ar[i][1]));
	  }

	  m1.insert(pair<string, string>("strange", "chuzhoy"));
	  m1.insert(make_pair("strange", "stranniy"));
	  m1.insert(make_pair("heap", "kucha"));
	  m1.insert(make_pair("heap", "nagrujat"));
	  m1.insert(make_pair("map", "karta"));
	  m1.insert(make_pair("map", "tabliza"));
	  m1.insert(make_pair("map", "plan"));


	  //print multimap
	  cout << "multimap:" << endl << endl;

	  MIT it1 = m1.lower_bound("a");
	  MIT it2 = m1.end();
	  //lower_bound("t");

	  while (it1 != it2)
	  {
		  cout << it1->first << " - ";
		  cout << it1->second << endl;

		  ++it1;
	  } // end of print multimap

  }*/
	  
	  stop

	cout << endl << "end" << endl;
	system("pause");

	return 0;
}

