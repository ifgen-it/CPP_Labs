//Стандартная библиотека шаблонов - STL 
	//Контейнеры стандартной библиотеки - vector
	//Итераторы

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <string>
#include <stdexcept>

using namespace std;	

#include "mystring.h"
//#include "mystring.cpp"

#include "point.h"
//#include "point.cpp"

#pragma warning(disable: 4786)
#define	  stop __asm nop
//#define stop ;

#include "mytemplates.h"


int main()
{
	// Контейнер стандартной библиотеки vector 

//////////////////////////////////////////////////////////////////////
	//Создание векторов. 

	//Создайте следующие вектора:
	//---------------------------
	//пустой вектор целых чисел - vInt и проверьте с помощью функции size(),
	//что его размер нулевой. 
		
	//vector<int> vInt;
	//cout << vInt.size();
	
	//Раскомментируйте следующий фрагмент, подумайте - все ли корректно
	//Если есть некорректности, - исправьте

	//cout << vInt.size() << " " << vInt.front() << endl;
	/*
	vInt.reserve(1);
	vInt.front()= 4;
	cout << vInt.size() << " " << vInt.back() << endl;	
	vInt.push_back(1);
	cout << vInt.size() << " " << vInt.front() << endl;	
	*/

	//С помощью функции push_back() в цикле заполните вектор какими-либо значениями.
	//На каждой итерации цикла следите за размером вектора с помощью методов
	//size(), capacity(), max_size() и выводите значения элементов. 
	//
	//Подсказка: так как такая проверка понадобится Вам и в следующих заданиях,
	//напишите шаблон функции, которая для вектора, содержащего элементы любого типа
	//выводит его "реквизиты" и значения элементов на консоль.
	
	/*PrintVectProp(vInt);
		for (int i = 0; i < 6; i++)
		{
		vInt.push_back(i +1);
	cout  << endl << "was pushed: " << vInt.back() << endl << endl;
	PrintVectProp(vInt);
	}*/

	//вектор вещественных - vDouble1 с заданным Вами начальным размером  и
	//проверьте результат с помощью созданного Вами шаблона. Как будут
	//проинициализированы элементы вектора?
	
	/*vector<double> vDouble1(6,2.2);
	PrintVectProp(vDouble1);
	cout << vDouble1.front();*/

	//вектор объектов типа MyString с начальным размером - 5 элементов
	//и инициализацией каждого элемента строкой "A"
	//C помощью функции at() а также с помощью оператора
	//индексирования []  измените значения каких-либо элементов.
	//Попробуйте "выйти" за границы вектора с помощью at() и
	//с помощью []. 
	
		/*vector<MyString> vStr(5, MyString("A"));
	try{
	   vStr.at(6) = "BBbb";
	   PrintVector(vStr);
	}
	catch (out_of_range& err)
	{
		cerr << "Out of range error: " << err.what() << endl;
	}
	vStr[1] = " continue ";
	PrintVector(vStr);*/

	//вектор вещественных - vDouble3, который является копией элементов
	// [0,5) массива вещественных чисел dMas. Предворительно массив dMas 
	//нужно создать и проинициализировать!
	
	/*double dMas[] = { 1.2, 3.4, - 5.6, 9.7, 2, 8.7, 1.2, 4.5 };

	vector<double> vDouble3(dMas, dMas + 5);
	PrintVector(vDouble3);

	//вектор вещественных - vDouble4, который является копией элементов
	// [2,5) вектора vDouble3. 

	vector<double> vDouble4(vDouble3.begin() + 2, vDouble3.begin() + 5);
	PrintVector(vDouble4);*/


	//вектор элементов типа Point - vPoint1 а) с начальным размером 3. Какой конструктор
	//будет вызван для каждого элемента?
	//b) vPoint2 с начальным размером 5 и проинициализируйте каждый элемент координатами (1,1).

	/*
	vector<Point> vPoint1(3);
	PrintVector(vPoint1);

	vector<Point> vPoint2(5, Point(1,1));
	PrintVector(vPoint2);
	*/

	//вектор указателей на Point - vpPoint с начальным размером 5
	//Подумайте: как корректно заставить эти указатели "указывать" на объекты Point
	
		/*{
	vector<Point*> vpPoint(5);
	vpPoint[0] = new Point(2,4);
	vpPoint[3] = new Point(-5, -7);

	PrintVector(vpPoint);

	for (int i = 0; i < vpPoint.size(); i++)
	{
		delete vpPoint[i];
		vpPoint[i] = 0;
	}
	PrintVector(vpPoint);
		}*/
	//Подсказка: для вывода на печать значений скорее всего Вам понадобится
		//а) специализация Вашей шаблонной функции
		//б) или перегрузка operator<< для Point*

	//Какие дополнительные действия нужно предпринять для такого вектора?


	///////////////////////////////////////////////////////////////////////
	//Резервирование памяти.
	//Подумайте, всегда ли верны приведенные ниже проверки?
		
		/*
		{
		size_t n = 6;
		vector<int> v(n);
		PrintVectProp(v);
		
		v.resize(n/2);
		PrintVectProp(v);
		
		if(v.capacity() == n) //true
		{
			cout << "true";
		}
		}
		*/

		/*
		{
		int n=6;
		size_t m=100;
		vector<int> v(n);
		PrintVectProp(v);
		v.reserve(m);
		PrintVectProp(v);
		
		if(v.capacity() == m) //true?
		{
			cout << "true";
		}
		}*/
		

		
		/*{
		vector<int> v(3,5);
		v.resize(4,10); //значения?
		v.resize(5); //значения?
	
		PrintVector(v);
		}*/
		

	//Создайте два "пустых" вектора с элементами
	//любого (но одного и того же типа) типа. 
	//В первом векторе зарезервируйте память под 5 элементов, а потом заполните
	//его значениями с помощью push_back.
	//Второй вектор просто заполните значениями посредством push_back.
	//
	//Сравните размер, емкость векторов и значения элементов
	
		/*
	vector<int> v1;
	vector<int> v2;
	v1.reserve(5);
	PrintVectProp(v1);
	PrintVectProp(v2);

	for (int i =0; i< v1.capacity(); i++)
	{
		v1.push_back(i+1);
	}
	PrintVectProp(v1);
	PrintVector(v1);


	for (int i =0; i< v1.capacity(); i++)
	{
		v2.push_back(i+1);
	//	PrintVectProp(v2);
	}

	PrintVectProp(v2);
	PrintVector(v2);


	//!!! shrink_to_fit - Уменьшение емкости вектора.
	//Для любого вектора из предыдущего задания требуется уменьшить емкость
	//до size.
	v2.shrink_to_fit();
	PrintVectProp(v2);
	*/	

	//Создание "двухмерного вектора" - вектора векторов
	//Задан одномерный массив int ar[] = {11,2,4,3,5};
	//Создайте вектор векторов следующим образом:
	//вектор vv[0] - содержит 11 элементов со значением 11
	//vv[1] - содержит 2,2
	//vv[2] - содержит 4,4,4,4
	//...
	//Распечатайте содержимое такого двухмерного вектора по строкам
	
	
	 /*int ar[] = {11,2,4,3,5};
	 vector<vector<int>> vv(sizeof(ar)/sizeof(ar[0]));
	 
	 for (int j = 0; j < sizeof(ar)/sizeof (ar[0]); j++)
	 {
   		vv[ j ].reserve(ar[ j ]);
   		 for (int i =0; i < ar[ j ] ; i++)
       		 { vv[ j ].push_back(ar[ j ] ); }
	 }
	 	 
	 cout << vv;
	 */
	 
	 
	 stop

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	//Вставка элемента последовательности insert().
	//В вектор vChar2 вставьте в начало вектора символ только при
	//условии, что в векторе такого еще нет.
	/*
	char ar[] = "hello";
	
	vector<char> vChar2(ar, ar + sizeof (ar) - 1 );
	PrintVectProp(vChar2);

	  vChar2.push_back('f');
	  PrintVectProp(vChar2);
	PrintVector(vChar2);

	vector<char>::iterator itb = vChar2.begin();
	auto ite = vChar2.end();
	char Sym = 'N';

	bool NeedInput = true;
	while (itb != ite)
	{
		if (*itb == Sym)
		{
			NeedInput = false;
			break;
		}
		++itb;
	}
	if (NeedInput)
	{
		vector<char>::iterator itb = vChar2.begin();
		vChar2.insert(itb, Sym);
	}
	cout << "New:" << endl;
	PrintVector(vChar2);
	
		//Вставьте перед каждым элементом вектора vChar2 букву 'W'
	char Sym1 = 'W';
	itb = vChar2.begin();
	int N = vChar2.size();

	for (int i = 0; i < N; i++)
	{
		itb = vChar2.insert(itb, Sym1);
		++++itb;
	}
	cout << "New1:" << endl;
	PrintVector(vChar2);
	PrintVectProp(vChar2);
	*/

///////////////////////////////////////////////////////////////////
	//Напишите функцию, которая должна удалять только повторяющиеся последовательности.
	//Например: было - "qwerrrrty12222r3", стало - "qwety1r3"

	 /*{
	char ar[] = "qwerrrrty12222r3";
	
	vector<char> vChar2(ar, ar + sizeof(ar) - 1);
	PrintVector(vChar2);
	//PrintVectProp(vChar2);
	EraseDouble(vChar2);
		
	cout << endl;
	PrintVector(vChar2);
	//PrintVectProp(vChar2);
	 }*/
	stop

///////////////////////////////////////////////////////////////////

	//Удаление элемента последовательности erase()
	//Напишите функцию удаления из любого вектора всех дублей 

	/*
	char ar[] = "qqqw222errrrtyqqq12222r33qqq3";
	
	vector<char> vChar2(ar, ar + sizeof (ar) - 1 );
	PrintVector(vChar2);
	PrintVectProp(vChar2);

	auto itb = vChar2.begin();
	int N = vChar2.size();

	while (itb != vChar2.end() )
	{
	   auto itComp = itb + 1;
	   while (itComp != vChar2.end() )
	   {
		   if ( *itComp == *itb )
		   {
       		itComp = vChar2.erase( itComp );
		   }
		   else
		   {
       		++itComp;
		   }
		}
		++itb;
	}

	cout << endl;
	PrintVector(vChar2);
	PrintVectProp(vChar2);
	*/

///////////////////////////////////////////////////////////////////
	//Создайте новый вектор таким образом, чтобы его элементы стали
	//копиями элементов любого из созданных ранее векторов, но расположены
	//были бы в обратном порядке
	
	/*
		char ar[] = "qqqw222errrrtyqqq12222r33qqq3";
	
		vector<char> vChar2(ar, ar + sizeof (ar) - 1 );
		PrintVector(vChar2);
		//PrintVectProp(vChar2);

		cout << endl;

		vector<char>::reverse_iterator itrb = vChar2.rbegin();
		auto itre = vChar2.rend();

		vector<char> vrChar2(itrb, itre);
		PrintVector(vrChar2);
		//PrintVectProp(vrChar2);
	*/

///////////////////////////////////////////////////////////////////

	//Задание 1. Списки. Операции, характерные для списков.
	//Создайте пустой список из элементов Point - ptList1 и наполните
	//его значениями с помощью методов push_back(),
	//push_front, insert()
	
	
	/*list<Point> ptList1;
	ptList1.push_back(Point(1,4));
	ptList1.push_front(Point(5,8));
	ptList1.push_front(Point(7,9));
	ptList1.insert(++ptList1.begin(), Point(1,1));
	
	PrintListDeque(ptList1);
	cout << ptList1.size() << endl;

	//Напишите шаблон функции, которая будет выводить элементы
	//ЛЮБОГО КОНТЕЙНЕРА на печать. Проверьте работу шаблона на контейнерах
	//vector и list. Подсказка - хотелось бы увидеть тип контейнера.


	//Сделайте любой из списков "реверсивным" - reverse()

	ptList1.reverse();
	cout << "Reversed list:" << endl;
	PrintListDeque(ptList1);

	//Создайте список ptList2 из элементов Point таким образом, чтобы он стал 
	//копией вектора элементов типа Point, но значения элементов списка располагались
	//бы в обратном порядке 

	vector<Point> ptV1;
	ptV1.push_back(Point(2, 5));
	ptV1.push_back(Point(-4, 8));
	ptV1.push_back(Point(20, 7));
	ptV1.push_back(Point(5, -9));

	cout<< endl<<"Vector:"<<endl;
	PrintVector(ptV1);

	list<Point> ptList2(ptV1.rbegin(), ptV1.rend());
	cout << endl<<"Reversed list:"<<endl;
	PrintListDeque(ptList2);

	//Отсортируйте списки  ptList1 и ptList2 - методом класса list - sort()
	//по возрастанию.
	//Подумайте: что должно быть перегружено в классе Point для того, чтобы
	//работала сортировка

	cout << endl;
	ptList1.reverse();
	PrintListDeque(ptList1);
	ptList1.sort();
	cout << endl<< "Sorted List 1:"<< endl;
	PrintListDeque(ptList1);

	cout << endl ;
	ptList2.sort();
	cout << "Sorted List 2:"<< endl;
	PrintListDeque(ptList2);


	stop

	//Объедините отсортированные списки - merge(). Посмотрите: что
	//при этом происходит с каждым списком.

	ptList1.merge(ptList2);
	cout << endl <<"1 List:" << endl;
	PrintListDeque(ptList1);
	cout<< endl<< "2 List:"<<endl;
	PrintListDeque(ptList2);
	
	stop

	//Исключение элемента из списка - remove()
	//Исключите из списка элемент с определенным значением.
	//Подумайте: что должно быть перегружено в классе Point?
	
	ptList1.remove(Point(20, 7));
	cout << endl<<"Removed 20,7:"<< endl;
	PrintListDeque(ptList1);

	//Исключение элемента из списка, удовлетворяющего заданному условию:
	//любая из координат отрицательна - remove_if(). 


	ptList1.remove_if(Neg);
	cout << endl<<"Removed Neg:"<< endl;
	PrintListDeque(ptList1);*/
	
	
	//Исключение из списка подряд расположенных дублей - unique(). 

	
	/*char ar[] = "qqqw222errrrtyqqq12222r33qqq3";
	
	list<char> chL1(ar, ar + sizeof (ar) - 1 );
	PrintList(chL1);

	cout <<endl<< "Uniqued List:"<<endl;
	chL1.unique();
	PrintList(chL1);*/
	

	stop

///////////////////////////////////////////////////////////////////
	//Задание 2.Очередь с двумя концами - контейнер deque

	//Создайте пустой deque с элементами типа Point. С помощью
	//assign заполните deque копиями элементов вектора. С помощью
	//разработанного Вами в предыдущем задании универсального шаблона
	//выведите значения элементов на печать
	
		
	/*vector<Point> ptV1;
	ptV1.push_back(Point(2, 5));
	ptV1.push_back(Point(-4, 8));
	ptV1.push_back(Point(20, 7));
	ptV1.push_back(Point(5, -9));

	deque<Point> ptD1;
	ptD1.assign(ptV1.begin(), ptV1.end());

	ptD1.push_front(Point(0,0));
	//PrintDeque(ptD1);
	//Print(ptD1);
	PrintListDeque(ptD1);

	cout << ptD1[0];*/
	


	//Создайте deque с элементами типа MyString. Заполните его значениями
	//с помощью push_back(), push_front(), insert()
	//С помощью erase удалите из deque все элементы, в которых строчки
	//начинаются с 'A' или 'a'

	/*deque<MyString> strD1;
	strD1.push_back(MyString("hello"));
	strD1.push_back(MyString("ok good job"));
	strD1.push_front("A first string");
	strD1.insert(strD1.end(), "animal last string");

	PrintListDeque(strD1);
	auto itb = strD1.begin();

	int n = strD1.size();

	for (int i=0; i<n; i++)
	{
		const char* pStr=0;
		pStr = (*itb).GetString();
	
		if (*pStr == 'A' || *pStr == 'a')
		{
			itb = strD1.erase(itb);
		}
		else ++itb;
	}

	cout<<endl<<"Erased strings like ^(a|A)w+$ "<<endl;
	PrintListDeque(strD1);
	//Print(strD1);
	*/



cout << endl << "end" << endl;
system("pause");

	return 0;
}