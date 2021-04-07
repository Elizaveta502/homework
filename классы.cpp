/* Класс «Рациональное число» (РЧ). Поля: числитель, знаменатель. Методы: перегрузка
операции приведения типа к float, операций умножения «*» двух РЧ и РЧ с целым числом,
сравнения на равенство «==» двух РЧ и РЧ с целым числом. */

#include <stdio.h> //подключение библиотек
#include <iostream>
#include <locale.h>

using namespace std; //пространство имен

class RNum //определение класса
{
	private: 
	float ch, zn;
	public: 
	
	RNum (float a, float b) //описание конструктора с параметрами
	{
		ch=a;
		zn=b;
		cout << "Конструктор с параметрами успешно сработал!" <<"("<<this<<")"<< endl  << endl;
	}
	
	~RNum () //описание деструктора
	{
		cout << "Деструктор успешно сработал!" <<"("<<this<<")" <<endl << endl;
	}
	
	RNum (const RNum &other) //описание конктруктора копирования
	{
		this->ch=other.ch;
		this->zn=other.zn;
		cout << "Конструктор копирования успешно сработал!" <<"("<<this<<")" <<endl << endl;
	}
	
	float getCh() {return ch;}; //ввод числителя с клавиатуры
	
	float getZn() {return zn;}; //ввод знаменателя с клавиатуры
	
	void setCh(float a) //установка числителя
	{
		ch=a;
	}
	
	void setZn(float a) //установка знаменателя
	{
		zn=a;
	}
	
	void Print() //функция для вывода числителя и знаменателя на экран
	{
		cout <<"Числитель равен "<<ch<<endl<<"Знаменатель равен "<<zn<<endl;
	}
	
	void Scan() //функция ввода числителя и знаменателя 
	{
		cout<<"Введите числитель: ";
		cin>>ch;
		cout<<"Введите знаменатель: ";
		cin>>zn;
		Print ();
	}
	//описание перегрузок
	operator float() {return ch/zn;} //перегрузка приведения к типу float
	float operator * (const RNum &other) //перегрузка умножения двух дробей
	{
		this->ch*=other.zn;
		this->zn*=other.ch;
		return ch/zn;
	}
	float operator * (int a) //перегрузка умножения дроби и целого числа
	{
		this->zn*=a;
		return ch/zn;
	}
	
	bool operator == (const RNum &other) //перегрузка сравнения на равенство двух дробей
	{
		return (this->ch/this->zn)==(other.ch/other.zn);
	 } 
	bool operator == (int a) //перегрузка сравнения на равенство дроби и целого числа
	
	{
		return (this->ch/this->zn)==a;
	}
	
};

float PrintFloat(float a) {return a;}

int main ()
{
	setlocale (LC_ALL, "Russian");
	int menu;
	int c;
	//организация меню
		do {
		cout <<"\tМЕНЮ:"<<endl;
		cout << "1-Ввод данных с клавиатуры" << endl;
		cout << "2-Вывод данных на экран" << endl;
		cout << "3-Вывод числителя" << endl;
		cout << "4-Вывод знаменателя" << endl;
		cout << "5-Установка числителя" << endl;
		cout << "6-Установка знаменателя" << endl;
		cout << "7-Копирование" << endl;
		cout << "8-Приведение к типу float" << endl;
		cout << "9-Операция умножения двух рациональных чисел" << endl; 
		cout << "10-Операция умножения рационального и целого чисел" << endl;
		cout << "11-Сравнение на равенство двух рациональных чисел" << endl;
		cout << "12-Сравнение на равенство рационального и целого чисел" << endl;
		cout << "13-Выход"<<endl<<endl;
		cout << "Выберите пункт меню: " << endl; 
		cin >> menu;
		
		RNum a(1,2), b(3,4);// (??)
		switch (menu)
		{
			case 1: a.Scan(); break;
			case 2: a.Print(); break;
			case 3: cout<<"Числитель: "<<a.getCh()<<endl; break;
			case 4: cout<<"Знаменатель: "<<a.getZn()<<endl; break;
			case 5: a.setCh(20); cout<<"Числитель: "<<a.getCh()<<endl; break;
			case 6: a.setZn(10); cout<<"Знаменатель: "<<a.getZn()<<endl; break;
			case 7: {RNum b(a); b.Print();
				break;
			}
			case 8: cout<<PrintFloat(a)<<endl; break;
			case 9: cout<<a*b<<endl; break;
			case 10: cout<<"Введите целое число: "<<endl;
			cin>>c;
			cout<<a*b<<endl; break;
			case 11: if (a==b) cout<<"Числа равны"<<endl; 
			else cout<<"Числа не равны"; break;
			case 12:
			cout <<"Введите целое число: "<<endl;
			cin>>c;
			if (a==c) cout<<"Числа равны"<<endl;
			else cout<<"Числа не равны"<<endl; break;	
		
		}	
	} while (menu!=13);
	
	
	return 0;
}




