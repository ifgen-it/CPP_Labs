// Iter_Alg.cpp : Defines the entry point for the console application.
//
//Итераторы. Стандартные алгоритмы. Предикаты.

#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <functional>
#include <iterator>
#include <string>




using namespace std;	

#define	  stop ;
//__asm nop

#include "myTemplates.h"
#include "point.h"
#include "shape.h"
#include "rect.h"


int main()
{
	
///////////////////////////////////////////////////////////////////

	//Задание 1. Итераторы

	//Реверсивные итераторы. Сформируйте set<Point>. Подумайте, что
	//нужно перегрузить в классе Point. Создайте вектор, элементы которого 
	//являются копиями элементов set, но упорядочены по убыванию

  /* {

   	set<Point> s1 = { Point(0,0), Point(1,4), Point(-6, -7) };
   	s1.insert(Point(12, 4));
   	
   	//PrintSet(s1);
   	
   	vector<Point> v1(s1.rbegin(), s1.rend());
   	//PrintVector(v1);
   		
	

	//Потоковые итераторы. С помощью ostream_iterator выведите содержимое
	//vector и set из предыдущего задания на экран.
       
       cout << "Set:"<< endl;
       ostream_iterator<Point> os(cout, ", ");
       copy(s1.begin(), s1.end(), os);
       cout << endl << endl;
       
       cout << "Vector:"<< endl;
       copy(v1.begin(), v1.end(), os);
       cout << endl;
       
      
   
	//Итераторы вставки. С помощью возвращаемых функциями:
	//back_inserter()
	//front_inserter()
	//inserter()
	//итераторов вставки добавьте элементы в любой из созданных контейнеров. Подумайте:
	//какие из итераторов вставки можно использовать с каждым контейнером.


	//PrintVector(v1);
	v1.push_back(Point(9, 9));

	back_insert_iterator<vector<Point>> bit = back_inserter(v1);
	*bit = Point(999, 999);
	bit = Point(119, 119);
	PrintVector(v1);

	set<Point>::iterator beg_sit = s1.begin();
	insert_iterator<set<Point>> sit = inserter(s1,beg_sit);

	//PrintSet(s1);
	sit = Point(-119, -119);
	*sit = Point(889, 889);
	PrintSet(s1);

   }*/


   ///////////////////////////////////////////////////////////////////

	   //Задание 2. Обобщенные алгоритмы (заголовочный файл <algorithm>). Предикаты.

	   // алгоритм for_each() - вызов заданной функции для каждого элемента любой последовательности
	   //(массив, vector, list...)
	   //С помощью алгоритма for_each в любой последовательности с элементами любого типа
	   //распечатайте значения элементов
	   //Подсказка : неплохо вызываемую функцию определить как шаблон

	   /*{
		   int ar[] = { 2, 4, 6, 7, 34, 67 };
		   for_each(ar, ar + sizeof(ar) / sizeof(ar[0]), PrintF<int>);
		   cout << endl;

		   vector<char> v1 = { 'A', 'b', 'C', 'x' };
		   for_each(v1.begin(), v1.end(), PrintF<char>);
		   cout << endl;

		   list<Point> l1 = { Point(1,1), Point(34,35), Point(10,11) };
		   for_each(l1.begin(), l1.end(), PrintF<Point>);
		   cout << endl;



		   stop

			   //С помощью алгоритма for_each в любой последовательности с элементами типа Point
			   //измените "координаты" на указанное значение (такой предикат тоже стоит реализовать
			   //как шаблон) и выведите результат с помощью предыдущего предиката

			   for_each(l1.begin(), l1.end(), AddDelta<Point>);
		   for_each(l1.begin(), l1.end(), PrintF<Point>);
		   cout << endl;

		   for_each(v1.begin(), v1.end(), AddDelta<char>);
		   for_each(v1.begin(), v1.end(), PrintF<char>);
		   cout << endl;

		   for_each(ar, ar + sizeof(ar) / sizeof(ar[0]), AddDelta<int>);
		   for_each(ar, ar + sizeof(ar) / sizeof(ar[0]), PrintF<int>);
		   cout << endl;
	   }*/

	   //С помощью алгоритма find() найдите в любой последовательности элементов Point
	   //все итераторы на элемент Point с указанным значением.

	   /*{
		   vector<Point> v1 = { Point(1,1), Point(2,2), Point(1,1), Point(1,1) };
		   PrintVector(v1);

		   vector<Point>::iterator it1 = v1.begin();
		   int Counter = 1;
		   while (it1 != v1.end())
		   {
			   it1 = find(it1, v1.end(), Point(1, 1));
			   if (it1 != v1.end())
			   {
				   cout << Counter++ << " " << *it1 << endl;
				   ++it1;
			   }
			   else
			   {
				   cout << "Not found!";
			   }
		   }
	   }*/

	   //С помощью алгоритма sort() отсортируйте любую последовательность элементов Point. 
	   ////По умолчанию алгоритм сортирует последовательность по возрастанию.
	   //Что должно быть определено в классе Point?
	   // Замечание: обобщенный алгоритм sort не работает со списком, так как
	   //это было бы не эффективно => для списка сортировка реализована методом класса!!!

	/*{
		vector<Point> v1 = { Point(1,1), Point(34,35), Point(10,11), Point(-4,-4), Point(-4,-10), Point(1,11) };
		sort(v1.begin(), v1.end());
		PrintVector(v1);

	}*/

	//С помощью алгоритма find_if() найдите в любой последовательности элементов Point
	//итератор на элемент Point, удовлетворяющий условию: координаты x и y лежат в промежутке
	//[-n, +m].

	/*{
		vector<Point> v1 = { Point(-4,1), Point(34,35), Point(-10,11), Point(-4,-4), Point(-3,-10), Point(1,11) };

		vector<Point>::iterator it1 = find_if(v1.begin(), v1.end(), Range(-3, 10));
		cout << *it1;
	}*/


	//С помощью алгоритма sort() отсортируйте любую последовательность элементов Rect,
	//располагая прямоугольники по удалению центра от начала координат.
	
	/*{
		
	Rect r1(1, 10, 10, 2, Shape::BLUE);
	Rect r2(20, 40, 30, 10, Shape::WHITE);
	Rect r3(-100, -20, -30, -110, Shape::GREEN);
	Rect r4(220, 440, 230, 110, Shape::RED);
	
	vector<Rect> v1 = { r1, r2, r3, r4 };
	PrintVector(v1);

	sort(v1.begin(), v1.end(), PredRect);
	cout << "After sorting:" << endl;
	PrintVector(v1);

	//vector<int> v2 = { 1 , 5 , 2, 6, -1, -7 };
	//sort(v2.begin(), v2.end(), Pred1);
	//cout << "After sorting:" << endl;
	//PrintVector(v2);
	
	}*/


	//transform
		//Напишите функцию, которая с помощью алгоритма transform переводит 
		//содержимое объекта string в нижний регистр.
		//Подсказка: класс string - это "почти" контейнер, поэтому для него
		// определены методы begin() и end()
	/*{
		string str1 = "ABcdEFFFrrr";
		string str2(str1);
		cout << str1 << endl;

		transform(str1.begin(), str1.end(), str2.begin(), Low);  // либо tolower - встроенный предикат
		cout << str2 << endl << endl;


		//Заполните list объектами string. С помощью алгоритма transform сформируте
		//значения "пустого" set, конвертируя строки в нижний регистр
	
		list<string> l1 = { string("Hello"), string("AGAIN"), string("Good") };
		
		PrintListDeque(l1);
		set<string> s1;

		transform(l1.begin(), l1.end(), inserter(s1, s1.begin()), BigLow);

		PrintSet(s1);


		stop
	}*/
		// map
		
		//Сформируйте любым способом вектор с элементами типа string.
		//Создайте (и распечатайте для проверки) map<string, int>, который будет
		//содержать упорядоченные по алфавиту строки и
		//количество повторений каждой строки в векторе
	{
		vector<string> v1 = { string("Oracle"), string("MathLogic"), string("Algorythm"), string("Oracle"), string("SQL") };
		v1.push_back(string("C++"));
		v1.push_back(string("C++"));
		v1.push_back(string("C++"));
		
		PrintVector(v1);
		cout << endl;

		map<string, int> m1;
		
		vector<string>::iterator it1 = v1.begin(), it2 = v1.end();
		while (it1 != it2)
		{
			m1[*it1]++;
			++it1;
		}
				
		//print map
		map<string, int>::iterator mit1 = m1.begin(), mit2 = m1.end();
		while (mit1 != mit2)
		{
			cout << mit1->first << " " << mit1->second << endl;
			++mit1;
		}

	}
	
	cout << endl << "end" << endl;
	system("pause");

	return 0;
}