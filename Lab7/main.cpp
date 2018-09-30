//Lab 7. Исключения

//Шаблоны: 
	//		шаблоны функций,
	//		шаблоны классов,


#include <tchar.h>
#include <stdexcept>
#include <new>
#include <iostream>

#include "myTemplates.h"
#include "myString.h"
#include <cstdio>

#define stop __asm nop

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	// test heap
	/*struct MyStruct
	{
		
		double Data2[1048576];		// 8* 1024*1024 B = 8 MB	1048576 - 1024*1024
	};
	{
		MyStruct* p;
		try
		{
			
			p = new MyStruct[130];	//80 MB
		}
		catch (std::bad_alloc& a)
		{
			cout << a.what() << endl;
			p = 0;
		}

		//delete p;
	}*/

	

////////////////////////////////////////////////////////////////////////////
	//Тема. Шаблоны функций.
	//Создайте шаблон функции перестановки местами двух
	//значений - Swap(). Проверьте работоспособность созданного
	//шаблона с помощью приведенного ниже фрагмента кода.
	//Подсказка 1: объявление шаблона корректнее поместить в .h-файл.

	/*int iX = 1, iY = -1;


	Swap(iX, iY);
	cout << "iX= " << iX << " iY= " << iY << endl;

	double dX = 0.5, dY = -5.5;
	Swap(dX, dY);
	cout << "dX= " << dX << " dY= " << dY << endl;

	//Подсказка 2: подумайте, что нужно реализовать, для того,
	//			чтобы следующий вызов работал с объектами MyString
	//			не только корректно, но и эффективно
	MyString str1("One"), str2("Two");
	Swap(str1, str2);
	cout << "str1= " << str1 << " str2= " << str2 << endl;
	*/


/////////////////////////////////////////////////////////////////////
	
	//Тема. Шаблоны классов.
	//Задание 1.
	//Создайте шаблон класса MyStack для хранения элементов любого типа T.
	//Подсказка: 1.элементы нужно где-то хранить - простым и удобным средством
	//			для хранения последовательно расположенных в памяти элементов
	//			является массив, 
	//			2.для задания максимального размера стека может быть использован
	//			параметр-константа шаблона
	//			3.обязательными операциями со стеком являются "push" и "pop". Для
	//			того, чтобы гарантировать корректное выполнение этих операций 
	//			хорошо было бы генерировать исключение в аварийной ситуации
	//			4. дополнительно реализуйте operator[] таким образом, чтобы пользователь
	//			мог читать/изменять значения только тех элементов, которые он формировал

	
	//С помощью шаблона MyStack создайте стек из 5 элементов int - iStack и
	//стек из 10 элементов MyString - strStack и поэкспериментируйте с функциями
	//push() и pop(), operator[]

	/*const int size1 = 5;
	MyStack<int, size1> S1;
	//cout << S1.size() << endl;
	try
	{
		S1.push(1);
		S1.push(2);
		S1.push(3);
		S1.push(8);
		S1.push(18);
		//S1.push(28);
	
	//S1.pop();
	//S1.pop();
	
		cout << S1[2];
	}
	catch (const char* err)
	{
		cout << err << endl;
	}
	catch (MyStack<int,size1>::StackError& err)
	{
		cout << "You attempted to get " << err.Index << " element." <<
			endl << "There are " << err.Size <<
			" available elements in the stack!" <<
			endl << "Element numeration starts with zero." << endl;
	}
	*/
	
	/*{
		const int size2 = 10;
		MyStack<MyString, size2> S2;
		MyString Str1("hello");
		try
		{
			S2.push(Str1);
			S2.push(MyString("Ok"));
			S2.push(MyString("How are you?"));
			S2.push(MyString("I am doing lab now"));
			S2.push(MyString(Str1));
			S2.pop();

			cout << S2[3] << endl;
		}
		catch (const char* err)
		{
			cout << err << endl;
		}
		catch (MyStack<MyString, size2>::StackError& err)
		{
			cout << "You attempted to get " << err.Index << " element." <<
				endl << "There are " << err.Size <<
				" available elements in the stack!" <<
				endl << "Element numeration starts with zero." << endl;
		}
	}*/


	//Задание 2. Реализуйте шаблон стека - MyStack2 таким образом, чтобы 
	//для хранения элементов использовался ОДНОСВЯЗНЫЙ список.
	//Реализуйте возможность распечатать элементы стека в том порядке, в котором их заносил (push())
	//пользователь

	{
		/*try
		{
			MyStack2<int> S3;
			
			S3.push(1);
			S3.push(2);
			S3.push(3);
			//S3.pop();

			S3.PrintBackward();
			cout << endl;

			//S3.Invert();
			S3.PrintForward2();

			
			//cout << S3.top();
			S3.top() = 6;
			cout << S3.top() << endl;

			S3.pop();
			S3.pop();
			S3.pop();
			
		}
		catch (MyStack2<int>::StackErrMsg& msg)
		{
			cout << msg.Err << endl;
		}*/

		/*try
		{
			MyStack2<MyString> S4;
			//cout << S4.top();
			S4.push("hello");
			S4.push("How are you?");
			S4.push("I am doing 7 lab");
			S4.push("Oh..it is time to do 9 lab. Hurry up!");

			//S4.PrintBackward();
								
			//S4.PrintForward1();
			S4.PrintForward2();
			cout << endl;

			S4.top() = "New string at the top";

			cout << endl;
			S4.PrintForward1();

			S4.pop();
			S4.pop();
			S4.pop();
			S4.pop();
			//S4.pop();
		}
		catch (MyStack2<MyString>::StackErrMsg& msg)
		{
			cout << msg.Err << endl;
		}*/
	}

	//Задание 3. Реализуйте шаблон очереди - MyQueue таким образом, чтобы 
	//для хранения элементов использовался динамический массив.
	//При использовании массива следует учесть специфику очереди, то есть
	//когда заполнен "хвост", в "голове" скорее всего уже имеются свободные элементы
	//=> должен быть организован кольцевой буфер

	/*{
		int D = 0;
	
		try
		{
			int QSize1 = 10;
			MyQueue<int> Q1(QSize1);
			//while (true)
			//{
				Q1.Enqueue(0+D);
				Q1.Enqueue(1+D);
				Q1.Enqueue(2+D);
				Q1.Enqueue(3+D);
				Q1.Enqueue(4+D);
				Q1.Enqueue(5+D);
				Q1.Enqueue(6+D);
				Q1.Enqueue(7+D);
				Q1.Enqueue(8+D);
				Q1.Enqueue(9+D);
				//cout << "Size= " << Q1.Size() << " Capacity= " << Q1.Capacity() << endl;
				//Q1.Resize(2);
				Q1.Enqueue(10 + D);
				//cout << "Size= " << Q1.Size() << " Capacity= " << Q1.Capacity() << endl;
				Q1.Enqueue(11 + D);
				//cout << "Size= " << Q1.Size() << " Capacity= " << Q1.Capacity() << endl;
				
				MyQueue<int> Q2(Q1);

				while (Q1.Size())
				{
					cout << Q1.Dequeue() << endl;
				}

				cout << "New queue:" << endl;

				while (Q2.Size())
				{
					cout << Q2.Dequeue() << endl;
				}


				//D += 1;
				//system("cls");
			//}
			
			//cout << Q1.Dequeue() << endl;
			//cout << Q1.Dequeue() << endl;

			//cout << Q1[0] << endl;
		}
		catch (const char* err)
		{
			cout << err << endl;
		}
	}*/

	//cout << endl;

	/*{
		try
		{
			const int ArSize = 10;
			int k = 0;
			const char* Ar[ArSize] = {
				"*.........",
				".*........",
				"..*.......",
				"...*......",
				"....*.....",
				".....*....",
				"......*...",
				".......*..",
				"........*.",
				".........*"
			};

			int QSize2 = 10;
			MyQueue<MyString> Q2(QSize2);
			while (true)
			{

				Q2.Enqueue(Ar[(0 + k) % ArSize]);
				Q2.Enqueue(Ar[(1 + k) % ArSize]);
				Q2.Enqueue(Ar[(2 + k) % ArSize]);
				Q2.Enqueue(Ar[(3 + k) % ArSize]);
				Q2.Enqueue(Ar[(4 + k) % ArSize]);
				Q2.Enqueue(Ar[(5 + k) % ArSize]);
				Q2.Enqueue(Ar[(6 + k) % ArSize]);
				Q2.Enqueue(Ar[(7 + k) % ArSize]);
				Q2.Enqueue(Ar[(8 + k) % ArSize]);
				Q2.Enqueue(Ar[(9 + k) % ArSize]);



				while (Q2.Size())
				{
					cout << Q2.Dequeue() << endl;
				}

				system("cls");
				k++;
			}
			//cout << "Size= " << Q2.Size() << " Capacity= " << Q2.Capacity() << endl;
			
				
		}
		catch (const char* err)
		{
			cout << err << endl;
		}
	}*/

{
try
{
	for (size_t j = 0; j < 260; j++)
	{
		char Sym = 'A';
		Sym += j;
		char Arr[2];
		Arr[0] = Sym;
		Arr[1] = '\0';

		MyString Base = Arr;
		MyString Str;
		int Border = 25;
		int QSize2 = 1;
		MyQueue<MyString> Q2(QSize2);

		for (size_t k = 0; k < Border; k++)
		{
			Str += Base;
			for (size_t i = 0; i < k + 1; i++)
			{
				Q2.Enqueue(Str);
			}
			
			while (Q2.Size())
			{
				cout << Q2.Dequeue() << endl;
			}
			system("cls");
		}

	}


}
catch (const char* err)
{
	cout << err << endl;
}
}

/*try
{
	int QSize1 = 4;
	
	MyQueue<int> Q1(QSize1);
	MyQueue<int> Q2(0);

	Q1.Enqueue(3);
	Q1.Enqueue(7);
	cout << "Size= " << Q1.Size() << " Capacity= " << Q1.Capacity() << endl;
	Q2 = Q1;

	//cout << "Size= " << Q1.Size() << " Capacity= " << Q1.Capacity() << endl;

	//MyQueue<int> Q2(Q1);

	while (Q1.Size())
	{
		cout << Q1.Dequeue() << endl;
	}
	//cout << Q1[0] << endl;
	//cout << Q1[1] << endl;

	cout << "New queue:" << endl;
	cout << "Size= " << Q2.Size() << " Capacity= " << Q2.Capacity() << endl;
	while (Q2.Size())
	{
		cout << Q2.Dequeue() << endl;
	}


}
catch (const char* err)
{
	cout << err << endl;
}*/

	cout << endl << "end" << endl;
	system("pause");
	return 0;
}

