// ����:
// ���������� ����������.
// ���������� ������� 

//#include "stdafx.h"	//���� �� ����������� �������������� ������������
					//������, ���������������� ��� �������
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

	//������� 1.���������� ����������.

	//���������� � ������� ����� MyString.cpp � MyString.h
	//������ MyString, �������������� ���� �� ���������� �������
	//9a. ����������� �������� ������������ ��� ������ MyString
	//��������� ������������ ������ �������������� ���������

	{
		/*MyString s1("AAA"), s2;
		s2=s1;	// ������-�� ��� ���������� ���������= ��������� �� ����������, ����� reference a deleted function
		s1="CCC";
		s2= MyString("tmp");
		s1=s1;
		cout << s2.GetString() << endl;
		stop
		*/
	}

	//�������� ����� Point, ������� ����� ��������� ����������
	//"�����". �������� ����������� (������������) ������   


	/*Point P1;
	P1.Print();
	P1.SetPoint(1, 1);
	Point P2(P1);
	P2.Print();
	*/

	//1b. "�����������" �������� += ���, ����� ��� ����������
	//�������� ���� pt2+=pt1; ������������
	//����������� ���������� �������� pt1 � pt2, � �����
	//������������� ��������������� ���������� ������� pt2 ���
	// � ������  pt2+=1; ��� ���������� ������� pt2 ������������� ��
	// ��������� ��������
	//a) � ������� ������ ������ (�������� +=)
	//�) � ������� ���������� ������� (�������� -=)
	//��������� ������������ ������ �������������� ���������

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

	//������� 1c. ����������� �������� +/- 
	//a)� ������� ������� ������ (�������� +)
	//�) � �������  ���������� ������� (�������� -)
	//���, ����� ����� �� ������������������ �����
	//���� ����������� ���������


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

//������� 1d. ����������� ������� �������� +/- 

/*Point pt1(1, 1);
Point pt2(2, 2);
Point pt3;

pt3 = -pt1;//-1
pt3 = +pt2;//2
pt2.Print();
*/



//������� 1d. ����������� �������� << (������ � �����) ���
//������ MyString ����� �������, ����� ��� ���������� ����������� ������
//�� ����� ���� ��������:
//contents:  "QWERTY"

/*MyString s("QWERTY");

cout << s << endl << s << endl;

ofstream fout("dat.txt");
fout << s << endl << s << endl;
*/

//cout<<s<<endl;

//������� 1� ����������� �������� + � += ��� ������ MyString

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

//������� 2. ����������� "���� ������" � ����������� ����������� ��������������
//�������. ������ �������� ������� (���� � ������� ��������, ������� ���������� ��������
//� ���� ���� �� �����), � �������: ���, �������, ���������, ��������...
//����������:
//���������� ����������� � ����
//����������
//����� ���������� � ���������� ����������
//����� ���� (��� ������������) ���������� � ���� �����������
//��������:


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


		/*BD bd;	//�������� ������ ����
		bd["Ivanov"] = Data(30,MALE,<��������� ������>);	//���� Ivanov-� � ���� ��� ���, ��
						//����������, ���� ��� ����, �� ������ ��� ����������
		std::cout<<bd;	//����� ���������� ��� ���� �����������
		//� �����:
		// BD bdnew = bd;
		//
		// bdnew = bd;

		//� ����� ����� ��������� ��� ��������� �����������...
		*/


cout << endl << "end" << endl;
system("pause");
	return 0;
}//endmain

