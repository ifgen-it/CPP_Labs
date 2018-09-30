// Темы:
// Перегрузка операторов.
// Встроенные объекты 

//#include "stdafx.h"	//если Вы используете предкомпиляцию заголовочных
					//файлов, раскомментируйте эту строчку
#define _CRT_SECURE_NO_WARNINGS
#include <tchar.h>
#include <iostream>
#include <fstream>
#include "myString.h"
#include "point.h"
#include "mydata.h"
#include "pair.h"
#include "base.h"

#define	  stop __asm nop

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{

	//Задание 1.Перегрузка операторов.

	//Подключите к проекту файлы MyString.cpp и MyString.h
	//класса MyString, разработанного Вами на предыдущем занятии
	//9a. Перегрузите оператор присваивания для класса MyString
	//Проверьте корректность работы перегруженного оператора

	{
		/*MyString s1("AAA"), s2;
		s2=s1;	// почему-то без перегрузки оператора= дефолтный не вызывается, пишет reference a deleted function
		s1="CCC";
		s2= MyString("tmp");
		s1=s1;
		cout << s2.GetString() << endl;
		stop
		*/
	}

	//Создайте класс Point, который будет содержать координаты
	//"точки". Объявите конструктор (конструкторы) класса   


	/*Point P1;
	P1.Print();
	P1.SetPoint(1, 1);
	Point P2(P1);
	P2.Print();
	*/

	//1b. "Перегрузите" оператор += так, чтобы при выполнении
	//операции типа pt2+=pt1; складывались
	//одноименные переменные объектов pt1 и pt2, а сумма
	//присваивалась соответствующим переменным объекта pt2 или
	// в случае  pt2+=1; обе переменные объекта pt2 увеличивались на
	// указанное значение
	//a) с помощью метода класса (оператор +=)
	//б) с помощью глобальной функции (оператор -=)
	//Проверьте корректность работы перегруженного оператора

	/*cout << "Overloading:" << endl;
	Point P1(6, 6), P2, P3(2, 2);

	P2.Print();
	P2 = P1;
	P1.Print();

	
	P2 += P3 += P1;
	P2 += 4;
	P2.Print();	//12

	P2 -= P3;	//4
	//P2 = operator-=(P2, P3);	//4
	P2.Print();
	P2 -= -12;	//16
	P2.Print();
	P1 = 3;
	P2 = 4;
	P3 = 5;

	P1 += P2 -= P3;
	cout << "----------" << endl;
	P1.Print();//2
	P2.Print();//-1
	P3.Print();//5
	*/

	/*Point pt1(1,1);
	Point pt2(2,2);
//	pt2+=pt1;
//  pt2+=1;
	Point pt3(3,3);
//  pt2+=pt1+=pt3;
	stop
	*/

	//Задание 1c. Перегрузите оператор +/- 
	//a)с помощью методов класса (оператор +)
	//б) с помощью  глобальных функций (оператор -)
	//так, чтобы любая из закомментированных строк
	//кода выполнялась корректно


	/*Point pt1(1,1);
	Point pt2(2,2);
	Point pt3;
	pt1.Print();
	pt2.Print();
	pt3.Print();

	pt3 = pt1 + pt2;//3
	pt1 = 2 + pt3;//5
	cout << "After:\n";
	pt1.Print();

	pt3 = pt1 - pt2;//3
	pt1 = 5 - pt3;//2
	pt1.Print();
	*/
//	pt3 = pt1 + 5;
//	pt3 = 2 + pt1;
//	pt3 = pt1 + pt2;

//	pt3 = pt1 - 5;
//	pt3 = pt1 - pt2;
stop

//Задание 1d. Перегрузите унарный оператор +/- 

/*Point pt1(1, 1);
Point pt2(2, 2);
Point pt3;

pt3 = -pt1;//-1
pt3 = +pt2;//2
pt2.Print();
*/



//Задание 1d. Перегрузите оператор << (вывода в поток) для
//класса MyString таким образом, чтобы при выполнении приведенной строки
//на экран было выведено:
//contents:  "QWERTY"

/*MyString s("QWERTY");

cout << s << endl << s << endl;

ofstream fout("dat.txt");
fout << s << endl << s << endl;
*/

//cout<<s<<endl;

//Задание 1е Перегрузите оператор + и += для класса MyString

/*MyString s;
MyString s1, s2("kkk"), s3;
//s1 += s += "first";
//cout << s << endl;
//cout << s1 << endl;
s2 = s3+s1;
cout << s2 << endl;

MyString s4;
s4 = "hi";
cout << s4;
operator<<(cout, s4);
cout << "Input word:\n";

cin >> s4;
cout << "You typed: " << s4;
*/

//Задание 2. Разработать "базу данных" о сотрудниках посредством ассоциативного
//массива. Ключом является фамилия (ключ в задании уникален, поэтому нескольких Ивановых
//в базе быть не может), а данными: пол, возраст, должность, зарплата...
//Реализуйте:
//добавление сотрудников в базу
//исключение
//вывод информации о конкретном сотруднике
//вывод всей (или интересующей) информации о всех сотрудниках
//Например:


{
MyData Emp2(MyData::MALE, 30, "PROG", 800);
MyData Emp1;
Emp1 = Emp2;
//cout << Emp1;
//cout << Emp2;


Pair fE1;
//cout << fE1.data;
//cout << fE1.key;

Pair fE2("Smirnov", MyData(MyData::MALE,32,"Dev",1200));

Base myBase;
//cout << myBase;

myBase["Smirnov"] = MyData(MyData::MALE, 32, "Developer", 1200);
myBase["Neratova"] = MyData(MyData::FMALE, 32, "Bisiness_Woman", 3000);
myBase["Ketov"] = MyData(MyData::MALE, 22, "Student", 300);
Base B1;
B1 = myBase;

//cout << "Smirnov: " << B1["Smirnov"] << endl;
//cout << "Neratova: " << B1["Neratova"] << endl;


//B1.deletePair("Smirnov");

cout << B1;
//cout << myBase;


}

//cout << fE2.data;
//cout << fE2.key;

//cout << fE2 << endl;


		/*BD bd;	//создание пустой базы
		bd["Ivanov"] = Data(30,MALE,<остальные данные>);	//если Ivanov-а в базе еще нет, то
						//добавление, если уже есть, то замена его реквизитов
		std::cout<<bd;	//вывод информации обо всех сотрудниках
		//А также:
		// BD bdnew = bd;
		//
		// bdnew = bd;

		//А также можно вспомнить про семантику перемещения...
		*/


cout << endl << "end" << endl;
system("pause");
	return 0;
}//endmain

