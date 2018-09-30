// Лаба 6
// RTTI - Run Time Type Identification

//#include "stdafx.h"	//если Вы используете предкомпиляцию заголовочных
					//файлов, раскомментируйте эту строчку
#define _CRT_SECURE_NO_WARNINGS
#include <tchar.h>
#include <iostream>
#include <fstream>

#include "point.h"

#include "shape.h"
#include "circle.h"
#include "rect.h"
#include "list.h"

#include <typeinfo>



#define	  stop __asm nop

using namespace std;

//void SortArrShapes(Shape** Arr, size_t size, const char* mode);

int _tmain(int argc, _TCHAR* argv[])
{
	{
		Point P1(1, 1);
		Point P2;

		//cin >> P2;
		P1 = P2;
		//cout << P1;

		Circle C1(4, 5, 2, Shape::PINK);
		Circle C2(4, 5, 3, Shape::WHITE);
		Circle C3(4, 5, 4, Shape::BLACK);
		Circle C4(4, 5, 5, Shape::RED);
		
		/*cout << C1;
		cin >> C2;
		cout << C2;*/

		Rect R1(0, 6, -5, 5, Shape::GREY);
		Rect R2(2, 5, 3, 10, Shape::GREEN);

		cout << R1;
		cout << R2;
		cout << C1;

		double Sr1 = R1.Square();
		double Sr2 = R2.Square();
		double Sc1 = C1.Square();
		cout << Sr1 << endl;
		cout << Sr2 << endl;
		cout << Sc1 << endl;
		cout << endl;
		// Array
	/*
		size_t size = 4;
		Shape* S1[] = { &R1, &R2, &C1, new Circle(45, 56, 1,Shape::PINK) };

		for (size_t i = 0; i < sizeof(S1)/sizeof(S1[0]); i++)
		{
			//if (dynamic_cast<Rect*>(S1[i]))   //(typeid(Rect) == typeid(*S1[i]))

			cout << i+1 << " " << typeid(*S1[i]).name() << endl;
			cout << *S1[i];
			cout << "Square: " << S1[i]->Square() << endl << endl;
		}


		cout << "After sorting:" << endl << endl;
		SortArrShapes(S1, size, "color");

		for (size_t i = 0; i < sizeof(S1) / sizeof(S1[0]); i++)
		{

			cout << i + 1 << " " << typeid(*S1[i]).name() << endl;
			cout << *S1[i];
			cout << "Square: " << S1[i]->Square() << endl << endl;
		}
		*/

		List L1;
		L1.AddToTail(&C4);
		L1.AddToHead(&C1);
		L1.AddToTail(&R2);
		L1.AddToTail(&C2);
		L1.AddToTail(&C3);

		//L1.PrintList();
		cout << L1;

		/*ofstream fout("output.txt");
		fout << L1;
		fout.close();

		cout << endl << "List L2:" << endl;
		List L2;
		ifstream fin("output.txt");
		fin >> L2;
		fin.close();*/
		/*L2.AddToHead(&R1);
		L2.AddToTail(&R2);
		L2.AddToTail(&C1);*/

		//cin >> L2;

		cout << endl << "List L2:" << endl;
		List L2; 
		L2 = L1;

		L2.Sort("color");
		cout << L2;

	}
cout << endl << "end" << endl;
system("pause");
	return 0;
}//endmain




/*
void SortArrShapes(Shape** Arr, size_t size, const char* mode)
{
	int CaseMode = -1;
	if (strcmp(mode, "square") == 0)
	{
		CaseMode = 0;
	}
	else if (strcmp(mode, "color") == 0)
	{
		CaseMode = 1;
	}
	switch (CaseMode)
	{
	case 0:	// Square
		for (size_t j = 0; j < size; j++)
			{
				size_t MinInd = j;
				double Min = Arr[MinInd]->Square();
				for (size_t i = j + 1; i < size; i++)
				{
					if (Arr[i]->Square() < Min)
					{
						MinInd = i;
						Min = Arr[MinInd]->Square();
					}
				}
				if (MinInd != j)
				{
					Shape* pTemp = Arr[j];
					Arr[j] = Arr[MinInd];
					Arr[MinInd] = pTemp;
				}
			}
		break;

	case 1:	// Color
		for (size_t j = 0; j < size; j++)
		{
			size_t MinInd = j;
			Shape::Color Min = Arr[MinInd]->m_color;
			for (size_t i = j + 1; i < size; i++)
			{
				if (Arr[i]->m_color < Min)
				{
					MinInd = i;
					Min = Arr[MinInd]->m_color;
				}
			}
			if (MinInd != j)
			{
				Shape* pTemp = Arr[j];
				Arr[j] = Arr[MinInd];
				Arr[MinInd] = pTemp;
			}
		}
		break;

	default:
		break;
	}
	
}*/