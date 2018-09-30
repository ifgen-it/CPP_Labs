// Лаба 4
// Объектно-ориентированный однородный двухсвязный список 

//#include "stdafx.h"	//если Вы используете предкомпиляцию заголовочных
					//файлов, раскомментируйте эту строчку
#define _CRT_SECURE_NO_WARNINGS
#include <tchar.h>
#include <iostream>
#include <fstream>
//#include "myString.h"
#include "point.h"
#include "list.h"


#define	  stop __asm nop

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	
	List L1;

	Circle C1(0, 0, 5);
	Circle C2(1, 1, 2);
	Circle C3(-4, 8, 10);
	Circle C4(C2);
	Circle C5(-5, 8, 4);

	//L1.AddToTail(&C1);
	L1.AddToTail(&C2);
	//L1.AddToTail(&C3);
	L1.AddToTail(&C4);
	L1.AddToTail(&C5);

	
	cout << L1;

	//L1.RemoveAllLike(&C2);

	/*L1.SortBySquare();
	cout << endl << "Sorted list order by circle square:" << endl;
	cout << L1;*/

	List L2;

	L2.AddToTail(&C1);
	L2.AddToTail(&C2);
	L2.AddToTail(&C3);
	L2.AddToTail(&C4);
	L2.AddToTail(&C5);
	

	cout << L2;

	L1 = L2;

	cout << endl << L1;

	//cout << C1;
	/*cout << L1;
	cout << "Input list of Circles: " << endl;
	cin >> L1;
	cout << "Your new list:" << endl;
	cout << L1;*/

	//L1.PrintList();

	/*cout << C1;
	cout << endl << "Input circle (x y rad) and press 'Enter': " << endl;
	cin >> C1;
	cout << "Your circle:" << endl << C1;
	*/
		

	ofstream fout("output.txt");
	fout << L1;
	fout.close();
	
	/*List L2;

	ifstream fin("output.txt");
	fin >> L2;
	fin.close();

	cout << L2;*/


cout << endl << "end" << endl;
system("pause");
	return 0;
}//endmain

