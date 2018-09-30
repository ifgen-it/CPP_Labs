// Лаба 5
// Статические члены класса

//#include "stdafx.h"	//если Вы используете предкомпиляцию заголовочных
					//файлов, раскомментируйте эту строчку
#define _CRT_SECURE_NO_WARNINGS
#include <tchar.h>
#include <iostream>
#include <fstream>
//#include "myString.h"
//#include "point.h"
//#include "list.h"

#include "counter.h"
#include "mystring.h"

#define	  stop __asm nop

void Lower(char* Str);
void Upper(char* Str);

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	//cout << "begin" << endl;

	{

		MyString::PrintStrings();
		cout << endl;

		MyString S1("FIrst");
		MyString S2("seCONd");
		MyString* pS5 = new MyString("ThiRD");
		MyString S3("fOURth");
		MyString S4(MyString("FIrst"));
		MyString St = MyString("TeMp");
		MyString S6;
		S6 = MyString("FIrst");


		//MyString::SortAscStrings();
		MyString::PrintStrings();

		cout << endl << "After delete THIRD and Lower:" << endl << endl;

		delete pS5;
		MyString::LowerStrings();
		MyString::PrintStrings();

		cout << endl << "After Upper:" << endl << endl;

		MyString::UpperStrings();
		MyString::PrintStrings();

		cout << endl << "After Sorting Asc:" << endl << endl;

		MyString::SortAscStrings();
		MyString::PrintStrings();

	}

	/*char Str[] = "HeLLo KiTTy!";
	cout << endl << Str << endl;
	Upper(Str);
	cout << endl << Str << endl;*/

	//cout << endl << "end" << endl;
	system("pause");
	return 0;
}//endmain

void Lower(char* Str)
{
	char* p = Str;
	while (*p)
	{
		if (*p>=65 && *p<=90)
		{
			*p = *p + 32;
		}
		p++;
	}
}

void Upper(char* Str)
{
	char* p = Str;
	while (*p)
	{
		if (*p >= 97 && *p <= 122)
		{
			*p = *p - 32;
		}
		p++;
	}
}
