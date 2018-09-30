// Êîíòåéíåðû STL: 
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
	
	
	//Íàïèøèòå øàáëîí ôóíêöèè äëÿ âûâîäà çíà÷åíèé stack, queue, priority_queue
	//îáðàòèòå âíèìàíèå íà òî, ÷òî êîíòåéíåðû ïðåäîñòàâëÿþò ÐÀÇÍÛÅ ìåòîäû äëÿ 
	//ïîëó÷åíèÿ çíà÷åíèé
	
	
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

	//Ñîçäàéòå ñòåê òàêèì îáðàçîì, ÷òîáû
	//à) ýëåìåíòû ñòåêà ñòàëè êîïèÿìè ýëåìåíòîâ âåêòîðà
	// ñäåëàíî âûøå

	//á) ïðè âûâîäå çíà÷åíèé êàê âåêòîðà, òàê è ñòåêà ïîðÿäîê çíà÷åíèé áûë îäèíàêîâûì 

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

	//Ñîçäàéòå î÷åðåäü, êîòîðàÿ ñîäåðæèò óêàçàòåëè íà îáúåêòû òèïà Point,
	//ïðè ýòîì ÿâíî çàäàéòå áàçîâûé êîíòåéíåð.
	//Èçìåíèòå çíà÷åíèÿ ïåðâîãî è ïîñëåäíåãî ýëåìåíòîâ ïîñðåäñòâîì front() è back()
	//Ïîäóìàéòå, ÷òî òðåáóåòñÿ ñäåëàòü ïðè óíè÷òîæåíèè òàêîé î÷åðåäè?

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
	//à) ñîçäàéòå î÷åðåäü ñ ïðèîðèòåòàìè, êîòîðàÿ áóäåò õðàíèòü àäðåñà ñòðîêîâûõ ëèòåðàëîâ - const char*
	//á) ïðîèíèöèàëèçèðóéòå î÷åðåäü ïðè ñîçäàíèè ñ ïîìîùüþ âñïîìîãàòåëüíîãî ìàññèâà ñ ýëåìåíòàìè const char*
	//â) ïðîâåðüòå "óïîðÿäî÷åííîñòü" çíà÷åíèé (ñ ïîìîùüþ pop() ) - åñëè îíè îêàçûâàþòñÿ íå óïîðÿäî÷åííûìè, ïîäóìàéòå:
	//		÷òî ñðàâíèâàåòñÿ ïðè âñòàâêå?

	/*{
		const char* ar[] = {"DDDD", "CCCC", "aaaa", "BBBB"};

		priority_queue<const char*, vector<const char*>, Cond> P3(ar, ar + sizeof(ar)/sizeof(ar[0]));

		PrintAd(P3);
		P3.push("AAA");
		PrintAd(P3);

	}*/


	////////////////////////////////////////////////////////////////////////////////////
	//set
	//a) ñîçäàéòå ìíîæåñòâî ñ ýëåìåíòàìè òèïà Point - ïîäóìàéòå, ÷òî íåîáõîäèìî îïðåäåëèòü
	//		â êëàññå Point (è êàêèì îáðàçîì)
	//á) ðàñïå÷àòàéòå çíà÷åíèÿ ýëåìåíòîâ ñ ïîìîùüþ øàáëîíà, ðåàëèçîâàííîãî â ïðåäûäóùåé ëàá. ðàáîòå
	//â) ïîïðîáóéòå èçìåíèòü ëþáîå çíà÷åíèå...
	//ã) Ñîçäàéòå äâà ìíîæåñòâà, êîòîðûå áóäóò ñîäåðæàòü îäèíàêîâûå çíà÷åíèÿ
	//		òèïà int, íî çàíåñåííûå â ðàçíîì ïîðÿäêå
	//ä) Âñòàâüòå â ëþáîå ìíîæåñòâî äèàïàçîí ýëåìåíòîâ èç ëþáîãî äðóãîãî
	//	êîíòåéíåðà, íàïðèìåð, ýëåìåíòîâ ìàññèâà	(÷òî ïðîèñõîäèò, åñëè â ìàññèâå èìåþòñÿ äóáëè?)

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
		//*it1 = Point(0, 0);	íèêàê, òîëüêî äëÿ ÷òåíèÿ ýëåìåíòû ìíîæåñòâà, ÷òîáû äåðåâî íå ïåðåñòðàèâàëîñü

		int ar2[] = { 23, 0, 56, 1, 3, 99 , 23, 1};
		set<int> s2(ar2, ar2 + 8);
		Print(s2);

		int ar3[] = { 56, 1, 0, 3, 23, 1, 99 };
		set<int> s3(ar3, ar3 + 7);
		Print(s3);
		// îáà ìíîæåñòâà ïîëó÷àþòñÿ îäèíàêîâûå
		
		auto it_beg = s3.upper_bound(3);	// âûøå 3
		auto it_end = s3.lower_bound(60);	// íèæå 60

		set<int> s4(it_beg, it_end);
		Print(s4);
	}*/

	////////////////////////////////////////////////////////////////////////////////////
	//map, multiset
	//à) ñîçäàéòå map, êîòîðûé õðàíèò ïàðû "ôàìèëèÿ, çàðïëàòà" - pair<const char*, int>,
	//	ïðè ýòîì ñòðîêè çàäàþòñÿ ñòðîêîâûìè ëèòåðàëàìè
	//á) çàïîëíèòå êîíòåéíåð çíà÷åíèÿìè ïîñðåäñòâîì operator[] è insert()
	//â) ðàñïå÷àòàéòå ñîäåðæèìîå

	//ã) çàìåíèòå îäèí èç ÊËÞ×ÅÉ íà íîâûé (áûëà "Èâàíîâà", âûøëà çàìóæ => ñòàëà "Ïåòðîâà")



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



	//ä) Ñôîðìèðóéòå ëþáûì ñïîñîáîì âåêòîð ñ ýëåìåíòàìè òèïà string.
	//Ñîçäàéòå (è ðàñïå÷àòàéòå äëÿ ïðîâåðêè) map<string, int>, êîòîðûé áóäåò
	//ñîäåðæàòü óïîðÿäî÷åííûå ïî àëôàâèòó ñòðîêè è
	//êîëè÷åñòâî ïîâòîðåíèé êàæäîé ñòðîêè â âåêòîðå

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
	m[*itVb]++;	// èçìåíèëè òî, ÷òî âûøå


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


	//å) 
	//çàäàí ìàññèâ:
	//const char* words[] = {"Abba", "Alfa", "Beta", "Beauty" ,...};
	//ñîçäàéòå map, â êîòîðîì êàæäîé áóêâå áóäåò ñîîòâåòñòâîâàòü ñîâîêóïíîñòü 
	//ëåêñèãðàôè÷åñêè óïîðÿäî÷åííûõ ñëîâ, íà÷èíàþùèõñÿ ñ ýòîé áóêâû.
	//Ïîäñêàçêà: íå ñòîèò õðàíèòü äóáëè îäíîé è òîé æå ñòðîêè

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
	m1[Key].insert(Val); // èçìåíèëè
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


	//æ)
	//ñîçäàéòå ñòðóêòóðó äàííûõ, êîòîðàÿ áóäåò õðàíèòü èíôîðìàöèþ î ñòóäåí÷åñêèõ ãðóïïàõ.
	//Äëÿ êàæäîé ãðóïïû äîëæíû õðàíèòñÿ ôàìèëèè ñòóäåíòîâ (ïî àëôàâèòó). Ïðè ýòîì 
	//ôàìèëèè ìîãóò äóáëèðîâàòüñÿ
	//Ñàìè ãðóïïû òîæå äîëæíû áûòü óïîðÿäî÷åíû ïî íîìåðó
	//
	//íîìåðà 


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
	//à) ñîçäàéòå "àíãëî-ðóññêèé" ñëîâàðü, ãäå îäíîìó è òîìó æå êëþ÷ó áóäóò ñîîòâåòñòâîâàòü
	//		íåñêîëüêî ðóññêèõ çíà÷åíèé - pair<string,string>, íàïðèìåð: strange: ÷óæîé, ñòðàííûé...
	//á) Çàïîëíèòå ñëîâàðü ïàðàìè ñ ïîìîùüþ ìåòîäà insert èëè ïðîèíèöèàëèçèðóéòå ñ ïîìîùüþ 
	//		âñïîìîãàòåëüíîãî ìàññèâà ïàðà (ïàðû ìîæíî êîíñòðóèðîâàòü èëè ñîçäàâàòü ñ ïîìîùüþ øàáëîíà make_pair)
	//â) Âûâåäèòå âñå ñîäåðæèìîå ñëîâàðÿ íà ýêðàí
	//ã) Âûâåäèòå íà ýêðàí òîëüêî âàðèàíòû "ïåðåâîäîâ" äëÿ çàäàííîãî êëþ÷à. Ïîäñêàçêà: äëÿ íàõîæäåíèÿ äèàïàçîíà
	//		èòåðàòîðîâ ìîæíî èñïîëüçîâàòü ìåòîäû lower_bound() è upper_bound()

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

