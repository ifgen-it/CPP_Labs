// Темы:
// Простое наследование. Виртуальные функции. Абстрактные классы.
// Битовые поля.

#include <iostream>
#include "header.h"

#include "shape.h"
//#include "shape.cpp"
#include "circle.h"
//#include "circle.cpp"
#include "rect.h"
//#include "rect.cpp"

#include "bin.h"
#include "oct.h"
#include "hex.h"
#include "bytes.h"

// #include <tchar.h>
 #define	  stop __asm nop

// #define stop ;

void FuncWhere(Shape& S);
using namespace std;

//int _tmain(int argc, _TCHAR* argv[])
int main()
{

	
/*
Shape S1;
Shape S2(GREEN);
Circle C1;
Circle C2(20, 30, 40, GREEN);

Rect R1(2, 1, 9, 3, RED);

int l, t, r, d;

R1.GetRect(l, t, r, d);

C2.SetCircle(1,2,3);
int x, y, rad;
C2.GetCircle(x, y, rad);

printf("%d %d %d %d\n", x, y, rad,C2.GetColor());
//cout << C2.GetColor()<< endl;

printf("%d %d %d %d\n", l, t, r, d);

S2.SetColor(BLUE);
cout << S2.GetColor() << endl;

C1.SetColor(RED);
cout << C1.GetColor() << endl;

Circle* pC1 = new Circle;
pC1->SetColor(BLUE);
cout << pC1->GetColor() << endl;

Shape* pS1 = new Shape;
pS1 = pC1;
cout << pS1->GetColor() << endl;

*/
	//Задание 1.Простое наследование.Аргументы конструктора,
	// передаваемые в базовый класс.

	//Создайте иерархию классов:
	//базовый класс Shape (который описывает любую фигуру)
	//и два производных класса Rect и Circle.
	//Подумайте: какие данные и методы нужно ввести в базовый
	//и производные классы (например, любую фигуру можно сделать
	//цветной => в базовом классе можно ввести переменную, которая
	//будет определять цвет фигуры.
	//Подсказка: для хранения цвета объявите перечисление (RED,GREEN,BLUE...);
	

	
	//В конструкторах производных классов предусмотрите передачу
	//параметра-цвета конструктору базового класса.
	//При создании и уничтожении объекта производного типа определите
	//последовательность вызовов конструкторов и деструкторов базового
	//и производного классов
	



	stop
//////////////////////////////////////////////////////////////////////

	//Задание 2.Виртуальные функции.
	//2а) Модифицируйте классы Shape,Rect и Circle:
	//добавьте в каждый класс public метод void WhereAmI().
	//Реализация каждой функции должна выводить сообщение 
	//следующего вида "Now I am in class Shape(Rect или Circle)".
	//Выполните приведенный фрагмент, объясните результат.
/*
Shape S1;
S1.Print();
S1.WhereAmI();

Circle C1;
C1.Print();
C1.WhereAmI();

Rect R1;
R1.Print();
R1.WhereAmI();
*/

  // для каждого типа вызывается свой метод, если он есть, это раннее связывание ? (перегрузка) либо переопределение метода в наследуемом классе
  





	//2б) Сделайте метод WhereAmI() виртуальным.
	//Снова выполните приведенный фрагмент, объясните разницу.


/*

Shape S1;
Rect R1;
Circle C1;

        Shape* pShape = &S1;
		Shape* pRect = &R1;
		Shape* pCircle = &C1;
		
    	pShape->WhereAmI();	//	???
		pRect->WhereAmI();	//	???
		pCircle->WhereAmI(); //
		// то же самое
		
		Shape& rShape = S1; //псевдоним s
		Shape& rRect = R1; //псевдоним r
		Shape& rCircle = C1; //псевдоним c
    	rShape.WhereAmI();	//вызов посредством rShape	???
		rRect.WhereAmI();	//вызов посредством	rRect	???
		rCircle.WhereAmI(); //вызов посредством rCircle	???
	*/

	// если методы Where не виртуальные вызывается метод класса Shape, т.к указатель типа Shape
		
		
		// теперь метод Виртуальный
		/*
		{
		Shape s;
		Rect r;
		Circle c;

	
		//Метод какого класса вызывается в следующих строчках???
		s.WhereAmI();	//	???
		r.WhereAmI();	//	???
		c.WhereAmI();	//	???
		stop


		Shape* pShape = &s;
		Shape* pRect = &r;
		Shape* pCircle = &c;
    	pShape->WhereAmI();	//	???
		pRect->WhereAmI();	//	???
		pCircle->WhereAmI(); //	???
		stop


		//Заполните ... согласно комментариям
		Shape& rShape = s; //псевдоним s
		Shape& rRect = r; //псевдоним r
		Shape& rCircle = c; //псевдоним c
    	rShape.WhereAmI();	//вызов посредством rShape	???
		rRect.WhereAmI();	//вызов посредством	rRect	???
		rCircle.WhereAmI(); //вызов посредством rCircle	???
		stop
    }
	*/
	
	

//////////////////////////////////////////////////////////////////////

	//Задание 3.Виртуальные деструкторы.
	//Модифицируйте классы:
	//a) введите соответствующие
	// деструкторы (без ключевого слова virtual).
	//Реализация каждого деструктора
	//должна выводить сообщение следующего вида
	// "Now I am in Shape's destructor!" или
	// "Now I am in Rect's destructor!"
	//Выполните фрагмент. Объясните результат.
/*
cout << "start" << endl;

{
	Circle C1;
	Rect R1;
	// C1.WhereAmI();
	// R1.WhereAmI();
	Shape S1;
	
	
    FuncWhere(S1);
    
    FuncWhere(R1);

    FuncWhere(C1);
    
}

cout << "end" << endl;
*/


	// b) Добавьте в объявление деструкторов ключевое слово virtual 
	//Выполните фрагмент.Объясните разницу.

	
	//Подумайте: какие конструкторы вызываются в следующей строке?
		//Если в разработанных классов каких-то конструкторов
		//не хватает - реализуйте
		//Если Вы считаете, что в приведенном фрагменте чего-то
		//не хватает - добавьте

/*
{
		Rect r(1,2,3,4,GREEN);
	// не ясно как Shape(r) отработал ?
		Shape* ar[]={new Shape(r), new Rect(r), new Circle(r), new Circle() };
	
		//Вызовите для каждого элемента массива метод WhereAmI()
	for (int i = 0; i < sizeof (ar)/sizeof (ar[0]); i++){
		ar[i]->WhereAmI();
		ar[i]->Print();
	}
	
	for (int i = 0; i < sizeof (ar)/sizeof (ar[0]); i++){
		delete ar[i];
	}
	
}
cout << "end";
	stop

*/

	//Задание 4*. В чем заключается отличие 1) и 2)
	/*
	{
		Shape* pShapes = new Rect[10];//1)
		Rect* pRects = new Rect[10];//2)

		//Попробуйте вызвать метод WhereAmI() для каждого элемента обоих массивов -
		//в чем заключается проблема???
	// проблема в том, что идет обращение не к своему элементу массива из-за разного размера типов
	
		
	for (int i = 0; i < 10; i++){
		pRects[ i ].WhereAmI();
		pRects[ i ].Print();
	}
	
	
	// segmentation fault:
	for (int i = 0; i < 10; i++) {
		static_cast<Rect*>(pShapes)[i].WhereAmI();
		
	}


		//Освободите динамически захваченную память
      
      delete[] pRects;
      delete[] pShapes;
	}

*/

//////////////////////////////////////////////////////////////////////

	//Задание 5.Виртуальные функции и оператор разрешения области видимости. 
/*
	{
		Rect r(10, 20, 30, 40, GREEN);
		
		Shape* p = &r;	
		p->WhereAmI();  // Rect
		stop
	
		
		//4a Оператор разрешения области видимости.
		//Посредством объекта r и указателя p вызовите виртуальную функцию
		//WhereAmI()класса Shape
		p->Shape::WhereAmI();
	
	}
*/

//////////////////////////////////////////////////////////////////////

	//Задание 6.Чисто виртуальные функции. 
	//Введите в базовый класс метод void Inflate(int); Подумайте:
	//можно ли реализовать такой метод для базового класса? => как его нужно объявить.
	//Реализуйте этот метод для производных классов.
	/*
	{
		Rect r(4, 4, 8, 8, RED);
		Shape* p = &r;
		p->Inflate(5);
		p->Print();
		
		Circle c(3, 3, 10, BLUE);
		p = &c;
		p->Inflate(5);
		p->Print();
	}
*/

//////////////////////////////////////////////////////////////////////

	//Задание 7.Объединения (union) C++. Битовые поля.
	//1.
	//Создайте следующие классы для различных представлений значений байта:
	//Bin - для двоичного представления
	//Hex - для шестнадцатерчного представления
	//Oct - для восьмеричного представления.
	//Подсказка 1: - для удобства используйте битовые поля.
	//Подсказка 2: - конструкторов в таких вспомогательных классах быть не должно,
	//так как все они будут членами объединения (union).
	//2.
	//В каждом классе введите метод Show, который должен выводить значение в
	//соответствующем виде
	//3.
	//Посредством объединения MyByte предоставьте пользователю возможность манипулировать
	//одним и тем же значением по-разному:
	//а) выводить: десятичное, шестнадцатеричное, восьмеричное, двоичное значение байта 
	//          а также символ, соответствующий хранимому значению (если есть соответствие);
	//б) выводить отдельные (указанные посредством параметра) шестнадцатеричные,
	//			восьмеричные, двоичные цифры;
	//в) изменять отдельные двоичные, восьмеричные или шестнадцатеричные цифры;
/*
	MyByte byte(0x1f);
	byte.ShowHex();
	byte.ShowBin();
	//...


*/


/*
Bin b;
b.Show();
b.ShowPos(0);
b.Edit(6, 1);
b.Show();



Oct o;
o.Show();
o.ShowPos(2);
o.Edit(1, 5);
o.Show();

Hex h;
h.Show();
h.ShowPos(0);
h.Edit(0, 15);
h.Show();
*/
//cout << "Bytes size = " << sizeof(Bytes);



Bytes byte(128);

//byte.EditBin(3, 0);
//byte.EditOct(1, 2);
//byte.EditHex(1, 8);
//byte.EditDec(2, 0);

byte.ShowBin();
byte.ShowOct();
byte.ShowHex();
byte.ShowDec();
//byte.ShowOctPos(2);



stop
/*
union Four{
	int A:2;
	int B:16;
};

Four X;
X.B = 0xff;
cout << X.B;
*/



cout << endl;
system("pause");
	return 0;
}//endmain

void FuncWhere(Shape& S){
	S.WhereAmI();
}