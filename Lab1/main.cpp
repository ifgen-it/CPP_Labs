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

	//������� 1.���������� ������. �������� ���������� ������.
	//����� ������� ������. 
	//�������� �������� Class View - (����� �� ������� ����� ������� �
	//������ - ������� Rect � MyString)
	//�������� �������� �� ����������� ����� �� ���� ������ ������ - ���
	//���������� ������������ ������� � ������� ����� ������.

	//����� ����������� ���������� ��� �������� ���������� ������?
	{
		Rect rect;
		Rect Rect1;	// ���������� ����������� �� ���������
		stop
	}

	//1a. �������� � ���������� ����������� � ����������� ���
	//������������� ���������� ������. �������� ��������� ������ Rect
	//� ������� ������������ � �����������. ���� ���������� ������
	//������ � ���������� ���������, ��������� - ���� ��� ��
	//�������? ��������� ���������� ������.
	//�������� ������� � ������ ������ �� �����, ����������:
	//� ����� ������ ���������� ����� ������������(������?)?
	{
		Rect Rect2(5, 15, 2, 10);	// constructor with parameters



		stop
			//1�. ��� ��������������� ������� ����������� ������������ ��� ����������
			//������������� ������������� ���������� ������, ��������, �����

			Rect Rect3;			// by default constructor

		//1�. ���������, ��� ������� ��������� � ������, ����� ������������ �����
		//���������� ��������� �������:

		Rect rrr(4, 3, 2, 1);		// swap left <-> right AND top <-> bottom

		stop
			//1�. ��������, ���������� � �������� ����� ������ InflateRect(), 
			//������� ����������� ������� �������������� �� �������� ����������
			//(��������� ������� �� ������ - ������ ������� �� ���� ��������).
			//���������: �������� � ���������� ������ ����� �� ������ "�������",
			//�� � � ������� Wizard-a Class View. ��� �����: �������� ��������
			//ClassView ���� �������, �������� �������� ����� Rect � �������
			//������ ������ ���� - � ����������� ����������� ���� ��������
			//Add/Add Member Function... � ������� ����������� ���������� ������
			//"����� ��������" Wizard-� ��� �������� � ���������� �����.

			Rect Rect4(2, 6, 2, 4);
		Rect4.InflateRect(-3, -3, -3, -3);		// test for wrong parameters


		stop


			//������� 2.���������� ������������� � ������� ������.
			//����������� �����������.

			//2�.�������� � ���������� ����������� ����������� � ������ Rect.
			//�������� ������� �� �����, ����������, �����
			//����������� ���������� ��� �������� r1,r2,r3 � r4?
			//���� ����� ���������� ��������� ��������?
			Rect r1;			// default consrtuctor
		Rect r2(1, 2, 3, 4);	// constructor with parameters
		Rect r3 = r1;		// copy constructor implicitly
		Rect r4(r2);		// copy constructor explicitly
		stop


			//2�. �������� � ���������� � ������ Rect ����� InflateRect(),
			  //������� ��������� ��� ���������, �� ��������� ������ 1, � 
			  //���������� ������� �������������� �� �� �������� ����������.
			  //��� ����� �������� ���������� ������� InflateRect()?

			r1.InflateRect(1, 1);
		r2.InflateRect(2, 2);
		//����� �� ������� InflateRect() ���������� � ������ �� ���� �������?
			//  ������� � 2 �����������

		r3.InflateRect(2, 2, 2, 2);
		r3.InflateRect(3, 3);
		r3.InflateRect(5);
		r3.InflateRect();

		stop

	}

	//������� 3.������������� �������. ������������. 
	{
		Rect r;
		//���������������� ��������� ������. ��������� ������
		//�����������

		//int tmp = r.m_left;		// member variable is private



		//������� � ����� Rect ����� void SetAll(...),
		//������� ����������� ���������� ������ ������������
		//��������. �������� ��������� �����, ��������� ������������. 

		r.SetAll(2, 1, 5, 4);

		//������� � ����� Rect ������ ����� GetAll(...),
		//������� "�������" �������� private-���������� ������.
		//�������� ��������� �����, ��������� ������������. 
		int left;
		int right;
		int top;
		int bottom;

		r.GetAll(left, right, top, bottom);

		stop
	}


	//������� 4.�������� ���������� ������ � �������� ���������
	//�������. ����������� ������� ������ �� ��������. ��������
	//�������� � ������������ ����������� ��� �������� ��������
	//�� �����, ����������: � ����� ������ ���������� ���������
	//� ������������ �����������. 
	//�������� ���������� ������� 
	// Rect BoundingRect(Rect, Rect);
	//������� ��������� ��� ������� ������ Rect �� �������� �
	//���������� ������ ������ Rect, ������� �������� ���������������,
	//� ������� ������� �������� ��������������. ��� ����������
	//�������� ���������� � ����������� ������� ������?

	//���������*: ������ ���� �� ������ ��� ����, ��� �������������
	//����� ��������� "�����������������", �� ���� m_left>m_right ���/�
	//m_top>m_bottom

	{

		Rect r1(1, 2, 3, 4), r2(5, 6, 7, 8), r3;
		r3 = BoundingRect(r1, r2);

		stop
	}
	//������� 4�. �������� �������� �� ������.
	//�������� ���������� ������� BoundingRect2, ������� ��������� �� ��
	//������, �������� ��������� �� ������
	//���������� �� ������������ ��� �������� ����������?

	{

		Rect r1(1, 2, 3, 4), r2(5, 6, 7, 8), r3;
		r3 = BoundingRect2(r1, r2);
		stop

	}


	//������� 5. ��������� �� �����. �������� � ����������
	//����� ���������� ������. ��������� �������� � 
	//������������ (�������������) � �����������. ����������: ����� ���
	//������� �� �������� ���������� �����������, � ����� - ����������?
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


	//������� 6.����������� + ���������� = ��������������
	// ���������. ����� MyString
	// ����������� ������������ (�������������) � ����������� ����������
	//���������� ������������� � ����������� �������
	//C ������� ��������� ���������� ����� ����������
	//������ � ������������ ������ ��� ������-����� ������
	{
		const char* s1 = "Hello";
		char s2[] = "Second string";

		MyString str("It's my string!");
		MyString str1(s1);
		MyString str2(s2);

		//�������� ����� GetString(), ������� ��������� ������ � ���������� ������.
		//� ������� cout � ������ GetString() ������������ ������ ������� str
		//���������: ���������, ��� ������� ��������� ����������� ����� GetString().

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


		//6a. ���������������� ��������� ��������. ��������� - �����
		//������������ ��� �������. ���������� ��������� ��������� (���?)

	{
		MyString str1("The first string!");		// ���������� �����������
		MyString str2 = str1;					// ���������� ����������� � ����� ������ ����� ��� ��
												// ��� ������ ����������� ��� 2 ������� ��������� ��� �� �����
						// ����� ����������� ����������� �����������
		

//6�. ���������� ����� SetNewString, ������� ����� �������� ������
// �� �����
		cout << str1.GetString() << endl;

		str1.SetNewString("New string");
		cout << str1.GetString() << endl;

		system("pause");
		stop
	}

		//6�. �������� ���������� �������, ������� ����� ��������� �����
		//���������� ���������� �� ������, � ���������� ������ MyString,
		//� ������� ������ ����� ������������� ����������

		// label:
	{

	MyString SumStr(ConcatString("first", "second", nullptr));

	cout << SumStr.GetString() << endl;

	system("pause");
	}

	//������� 7.������ �������� ������.

	// label:
	{
		MyString s(nullptr);
		MyString s1(s);

	}
		{
			//�������� � ������������������ ������ ar �� ��������
			// ���� MyString. ��������:
			//��� ������ �����������? N=3

			const int N = 5;

			MyString arstr[N] = { "first","second","third" };
			MyString* pAr = new MyString[N]{ "first","second","third" };

			//�������� - ������ �����-������ ������
			for (int i = 0; i < N; i++) {
				cout << "pAr[" << i << "] = " << pAr[i].GetString() << endl;
			}

			//��������� ������ �������, �� ������� ������ ���������������:
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

			

	//�������� � ������������������ ������ ��������	���� Rect.

			Rect ArRect[3] = {Rect(1,2,3,4), Rect(2,5,6,8)};



	system("pause");
	}
	stop


	//������� 8.������ ���������� �� ������� ������.

	// label:
	{
	//�������� � ������������������ ������ arPtr �� ���� 
	//���������� �� ������� ���� MyString.
	
		const int size = 3;
		MyString* arPtr[size] = { nullptr, new MyString("One of strings") , new MyString() };
	
		MyString Str1("it is string for array");

		//arPtr[0] = &Str1;

	//������ �����-������ ������

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
	

	//������� 9.  ������ � ������� ������� ��������� ������:
	//���� ��� ����� ���������� ������. � ����� ����� � ��������� ������
	//������� ���������� ����� (96%), � ������ � ����.
	//������� �������� 1� ���������� ���������� ���������� �� ����� �����
	//� ������ ��������� ��������: �� ������ ��������
	//���������� �� ������ ����� -> ������ �� ������
	//���������� �� ������ ����� -> ������ � ������.
	//��������� ���������� ����� ��������, �� ������� ������������ ������ �
	//������ ����� ������ ������ 50%.

	

	//Bochka spirt(...);
	//Bochka water(...);
	//...
	//	while(������������ ������ � ����� spirt > 50%)
	//	{
	//		spirt.Pereliv(water); //��� spirt.Pereliv(water, �����_������);
	//		water.Pereliv(spirt); // ����������
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

