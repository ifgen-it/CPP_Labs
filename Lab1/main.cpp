#define _CRT_SECURE_NO_WARNINGS
#include "myRect.h"
#include "myString.h"
#include "barrel.h"
#include <iostream>

#define stop __asm nop

int main()
{
	using namespace std;

	goto label;

label:

	//Задание 1.Объявление класса. Создание экземпляра класса.
	//Вызов методов класса. 
	//Откройте закладку Class View - (здесь Вы увидите имена методов и
	//данных - классов Rect и MyString)
	//Обратите внимание на пиктограммы слева от имен членов класса - они
	//обозначают спецификатор доступа к каждому члену класса.

	//Какой конструктор вызывается при создании экземпляра класса?
	{
		Rect rect;
		Rect Rect1;	// вызывается конструктор по умолчанию
		stop
	}

	//1a. Объявите и определите конструктор с параметрами для
	//инициализации переменных класса. Создайте экземляры класса Rect
	//с помощью конструктора с параметрами. Если компилятор выдает
	//ошибку в предыдущем фрагменте, подумайте - чего ему не
	//хватает? Добейтесь отсутствия ошибок.
	//Выполняя задание с самого начала по шагам, определите:
	//в какой момент происходит вызов конструктора(какого?)?
	{
		Rect Rect2(5, 15, 2, 10);	// constructor with parameters



		stop
			//1б. При конструировании объекта посредством конструктора без параметров
			//предусмотрите инициализацию переменных класса, например, нулем

			Rect Rect3;			// by default constructor

		//1в. Подумайте, как следует поступать в случае, когда пользователь задал
		//координаты следующим образом:

		Rect rrr(4, 3, 2, 1);		// swap left <-> right AND top <-> bottom

		stop
			//1г. Объявите, определите и вызовите метод класса InflateRect(), 
			//который увеличивает размеры прямоугольника на заданные приращения
			//(раздвигая стороны от центра - каждую сторону на свое значение).
			//Подсказка: объявить и определить методы можно не только "вручную",
			//но и с помощью Wizard-a Class View. Для этого: откройте закладку
			//ClassView окна проекта, сделайте активным класс Rect и нажмите
			//правую кнопку мыши - в появившемся контекстном меню выберите
			//Add/Add Member Function... С помощью появившейся диалоговой панели
			//"дайте указания" Wizard-у как объявить и определить метод.

			Rect Rect4(2, 6, 2, 4);
		Rect4.InflateRect(-3, -3, -3, -3);		// test for wrong parameters


		stop


			//Задание 2.Перегрузка конструкторов и методов класса.
			//Конструктор копирования.

			//2а.Объявите и определите конструктор копирования в классе Rect.
			//Выполняя задание по шагам, определите, какой
			//конструктор вызывается при создании r1,r2,r3 и r4?
			//Чему равны переменные созданных объектов?
			Rect r1;			// default consrtuctor
		Rect r2(1, 2, 3, 4);	// constructor with parameters
		Rect r3 = r1;		// copy constructor implicitly
		Rect r4(r2);		// copy constructor explicitly
		stop


			//2б. Объявите и определите в классе Rect метод InflateRect(),
			  //который принимает два аргумента, по умолчанию равных 1, и 
			  //раздвигает стороны прямоугольника на на заданные приращения.
			  //Для каких объектов вызывается функция InflateRect()?

			r1.InflateRect(1, 1);
		r2.InflateRect(2, 2);
		//Какая из функций InflateRect() вызывается в каждом из трех случаев?
			//  функция с 2 параметрами

		r3.InflateRect(2, 2, 2, 2);
		r3.InflateRect(3, 3);
		r3.InflateRect(5);
		r3.InflateRect();

		stop

	}

	//Задание 3.Спецификаторы доступа. Инкапсуляция. 
	{
		Rect r;
		//Раскомментируйте следующую строку. Объясните ошибку
		//компилятора

		//int tmp = r.m_left;		// member variable is private



		//Введите в класс Rect метод void SetAll(...),
		//который присваивают переменным класса передаваемые
		//значения. Вызовите созданный метод, проверьте корректность. 

		r.SetAll(2, 1, 5, 4);

		//Введите в класс Rect парный метод GetAll(...),
		//который "достает" значения private-переменных класса.
		//Вызовите созданный метод, проверьте корректность. 
		int left;
		int right;
		int top;
		int bottom;

		r.GetAll(left, right, top, bottom);

		stop
	}


	//Задание 4.Передача экземпляра класса в качестве параметра
	//функции. Возвращение объекта класса по значению. Поставив
	//остановы в конструкторе копирования или выполняя фрагмент
	//по шагам, определите: в какой момент происходит обращение
	//к конструктору копирования. 
	//Создайте глобальную функцию 
	// Rect BoundingRect(Rect, Rect);
	//которая принимает два объекта класса Rect по значению и
	//возвращает объект класса Rect, который является прямоугольником,
	//в который вписаны заданные прямоугольники. Как происходит
	//передача параметров и возвращение объекта класса?

	//Замечание*: хорошо было бы учесть тот факт, что прямоугольник
	//может оказаться "ненормализованным", то есть m_left>m_right или/и
	//m_top>m_bottom

	{

		Rect r1(1, 2, 3, 4), r2(5, 6, 7, 8), r3;
		r3 = BoundingRect(r1, r2);

		stop
	}
	//Задание 4а. Передача объектов по ссылке.
	//Создайте глобальную функцию BoundingRect2, которая выполняет ту же
	//задачу, принимая параметры по ссылке
	//Вызываются ли конструкторы при передаче параметров?

	{

		Rect r1(1, 2, 3, 4), r2(5, 6, 7, 8), r3;
		r3 = BoundingRect2(r1, r2);
		stop

	}


	//Задание 5. Указатель на класс. Объявите и определите
	//явный деструктор класса. Поставьте остановы в 
	//конструкторе (конструкторах) и деструкторе. Определите: когда для
	//каждого из объектов вызывается конструктор, а когда - деструктор?
	{
		Rect r1;
		Rect*	pR = new Rect(1, 2, 1, 2);
		{
			Rect r2(r1);
			Rect arRect[2];
			for (int i = 0; i < 3; i++)
			{
				static Rect r3(i, i, i, i);
				Rect r4(*pR);
				Rect r5(i, i, i, i);
			}
		}
		delete pR;
		stop
	}


	//Задание 6.Конструктор + деструктор = функциональное
	// замыкание. Класс MyString
	// Посредством конструктора (конструкторов) и деструктора обеспечьте
	//корректные инициализацию и деактивацию объекта
	//C помощью остановов определите когда происходит
	//захват и освобождение памяти для строки-члена класса
	{
		const char* s1 = "Hello";
		char s2[] = "Second string";

		MyString str("It's my string!");
		MyString str1(s1);
		MyString str2(s2);

		//Создайте метод GetString(), который обеспечит доступ к хранящейся строке.
		//С помощью cout и метода GetString() распечатайте строку объекта str
		//Замечание: подумайте, как следует корректно реализовать метод GetString().

		//...


		cout << str.GetString() << endl;
		// system("pause");

		const char* s4 = str2.GetString();
		size_t n = strlen(s4) + 1;
		char* pStr = new char[n];
		strcpy(pStr, s4);

		cout << pStr << endl;
		system("pause");

	}
	stop


		//6a. Раскомментируйте следующий фрагмент. Подумайте - какие
		//неприятности Вас ожидают. Попробуйте исправить положение (как?)

	{
		MyString str1("The first string!");		// вызывается конструктор
		MyString str2 = str1;					// вызывается конструктор и адрес строки будет тот же
												// при вызове деструктора для 2 объекта указателя уже не будет
						// нужно реализовать конструктор копирования
		

//6б. Реализуйте метод SetNewString, который будет заменять строку
// на новую
		cout << str1.GetString() << endl;

		str1.SetNewString("New string");
		cout << str1.GetString() << endl;

		system("pause");
		stop
	}

		//6г. Создайте глобальную функцию, которая будет принимать любое
		//количество указателей на строки, а возвращать объект MyString,
		//в котором строка будет конкатенацией параметров

		// label:
	{

	MyString SumStr(ConcatString("first", "second", nullptr));

	cout << SumStr.GetString() << endl;

	system("pause");
	}

	//Задание 7.Массив объектов класса.

	// label:
	{
		MyString s(nullptr);
		MyString s1(s);

	}
		{
			//Объявите и проинициализируйте массив ar из объектов
			// типа MyString. Например:
			//Как задать размерность? N=3

			const int N = 5;

			MyString arstr[N] = { "first","second","third" };
			MyString* pAr = new MyString[N]{ "first","second","third" };

			//Проверка - печать строк-членов класса
			for (int i = 0; i < N; i++) {
				cout << "pAr[" << i << "] = " << pAr[i].GetString() << endl;
			}

			//Увеличьте размер массива, не изменяя список инициализаторов:
			//N=5???

			int M = 5;
			MyString* pAr1 = new MyString[M]{ "", "", "", "", ""};
			for (int i = 0; i < N; i++) {
				pAr1[i].SetNewString(pAr[i].GetString());
			}
			pAr1[3].SetNewString("fourth");

			delete[] pAr;
			pAr = pAr1;
			pAr1 = nullptr;

			cout << "\nUpgraded pAr:\n" << endl;
			for (int i = 0; i < M; i++) {
				cout << "pAr[" << i << "] = " << pAr[i].GetString() << endl;
			}

			

	//Объявите и проинициализируйте массив объектов	типа Rect.

			Rect ArRect[3] = {Rect(1,2,3,4), Rect(2,5,6,8)};



	system("pause");
	}
	stop


	//Задание 8.Массив указателей на объекты класса.

	// label:
	{
	//Объявите и проинициализируйте массив arPtr из трех 
	//указателей на объекты типа MyString.
	
		const int size = 3;
		MyString* arPtr[size] = { nullptr, new MyString("One of strings") , new MyString() };
	
		MyString Str1("it is string for array");

		//arPtr[0] = &Str1;

	//Печать строк-членов класса

		for (int i = 0; i < size; i++) {
			// if (arPtr[i]) {
				printf("arPtr[%d] = %s\n",i, arPtr[i]->GetString());
				//cout << arPtr[i]->GetString();
			/*}
			else {
				printf("arPtr[%d] = 'nullptr'\n", i);
			}*/
		}
  

		system("pause");
		stop
	}
	

	//Задание 9.  Решите с помощью классов следующую задачу:
	//даны две бочки известного объема. В одной бочке в начальный момент
	//времени содержится спирт (96%), в другой – вода.
	//Кружкой емкостью 1л переливаем итеративно содержимое из одной бочки
	//в другую следующим способом: на каждой итерации
	//зачерпнули из первой бочки -> вылили во вторую
	//зачерпнули из второй бочки -> вылили в первую.
	//Требуется определить номер итерации, на которой концентрация спирта в
	//первой бочке станет меньше 50%.

	

	//Bochka spirt(...);
	//Bochka water(...);
	//...
	//	while(концентрация спирта в бочке spirt > 50%)
	//	{
	//		spirt.Pereliv(water); //или spirt.Pereliv(water, объем_кружки);
	//		water.Pereliv(spirt); // аналогично
	//		...

	//	}

	//	label:

	int VolPint = 1;
	double PctLimit = 0.5;
	int CounterIter = 0;

	int VolBarrel = 100;
	double PctSpirt = 0.96;
	double PctWater = 0;

	Barrel Spirt(VolBarrel, PctSpirt);
	Barrel Water(VolBarrel, PctWater);
	//Barrel Pint(0, 0);

	printf("CounterIter | Spirt_Barrel | Water_Barrel\n");
	printf("-----------------------------------------\n");
	printf("     %-7d|    %-6.3f    |    %-6.3f\n", 0, Spirt.GetPct(), Water.GetPct());
	printf("-----------------------------------------\n");

	while (Spirt.GetPct() > PctLimit) {
		
		/*
		//========= FORWARD =========
		// Reduce from Spirt barrel
		Spirt.Reduce();

		// Pint info
		//Pint.SetVolume(1);
		Pint.SetPct(Spirt.GetPct());

		// Add to Water barrel
		Water.Add(Pint.GetPct());

		//======= BACKWARD==========
		// Reduce from Water barrel
		Water.Reduce();

		// Pint info
		Pint.SetPct(Water.GetPct());

		// Add to Spirt barrel
		Spirt.Add(Pint.GetPct());
		*/

		Water.Transfuse(Spirt);	// from Spirt_Barrel to Water_Barrel
		Spirt.Transfuse(Water); // backward
		// counter
		CounterIter++;

		printf("     %-7d|    %-6.4f    |    %-6.4f\n", CounterIter, Spirt.GetPct(), Water.GetPct());
	}



	cout << "\nAnswer: Number of iteration is " << CounterIter << endl << endl;


	system("pause");
return 0;
}//end_main

