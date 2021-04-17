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
	int ch, zn;
public:

	RNum(int a, int b) //описание конструктора с параметрами
	{
		ch = a;
	/*	try
		{
			if (b == 0)
				//throw  "The denominator must not be zero";
				throw invalid_argument{ "Знаменатель=0" };
			zn = b;
		}

		catch (const char* exception)
		{
			cerr << "Error: " << exception << endl;
		}*/
		zn = b.setZn;
		

		cout << "Конструктор с параметрами успешно сработал!" << "(" << this << ")" << endl << endl;
		
	}

	~RNum() //описание деструктора
	{
		cout << "Деструктор успешно сработал!" << "(" << this << ")" << endl << endl;
	}

	RNum(const RNum &other) //описание конктруктора копирования
	{
		this->ch = other.ch;
		this->zn = other.zn;
		cout << "Конструктор копирования успешно сработал!" << "(" << this << ")" << endl << endl;
	}

	int getCh() { return ch; }; //ввод числителя с клавиатуры

	int getZn() { return zn; }; //ввод знаменателя с клавиатуры

	void setCh(int a) //установка числителя
	{
		ch = a;
	}

	void setZn(int a) //установка знаменателя
	{
	/*	if (a!=0)
		zn = a;
		else cout << "Знаменатель не может быть равен нулю!"<< endl;*/
		try
		{
			if (a == 0)
				//		throw  "The denominator must not be zero";
				throw invalid_argument{ "Знаменатель=0" };
				zn = a;
		}

	}

	void Print() //функция для вывода числителя и знаменателя на экран
	{
		cout << "Числитель равен " << ch << endl << "Знаменатель равен " << zn << endl;
	}

	void Scan() //функция ввода числителя и знаменателя 
	{
		cout << "Введите числитель: ";
		cin >> ch;
		cout << "Введите знаменатель: ";
		cin >> zn;
		while (zn == 0)
		{
			cout << "Ошибка. Знаменатель не может равняться нулю!" << endl;
			cout << "Введите новый знаменатель: ";
			cin >> zn;
		}
		Print();
	}
	//описание перегрузок
	operator float() { return (float)ch / zn; } //перегрузка приведения к типу float

	RNum operator * (const RNum &other) //перегрузка умножения двух дробей
	{
		this->ch *= other.ch;
		this->zn *= other.zn;
		return *this;
	}

	RNum operator * (int a) //перегрузка умножения дроби и целого числа
	{
		this->ch *= a;
		return *this;
	}

	bool operator == (const RNum &other) //перегрузка сравнения на равенство двух дробей
	{
		int q, p;
		q = this->ch;
		p = other.ch;
		return ( (double) q/ this->zn) == ((double) p / other.zn);
	}
	bool operator == (int a) //перегрузка сравнения на равенство дроби и целого числа

	{
		int q;
		q = this->ch;
		return ((double)q) / (this->zn) == a;
	}

};

float PrintFloat(float a) { return a; }

int main()
{
	setlocale(LC_ALL, "Russian");
	int menu;
	int c, chb, znb;
	char otv;
	//организация меню
	do {
		system("CLS");
		cout << "\tМЕНЮ:" << endl;
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
		cout << "13-Выход" << endl << endl;
		cout << "Выберите пункт меню: " << endl;
		cin >> menu;

		RNum a(1, 2), b(3, 4);
		switch (menu)
		{
		case 1: a.Scan(); break;
		case 2: a.Print(); break;
		case 3: cout << "Числитель: " << a.getCh() << endl; break;
		case 4: cout << "Знаменатель: " << a.getZn() << endl; break;
		case 5: a.setCh(20); cout << "Числитель: " << a.getCh() << endl; break;
		case 6: a.setZn(10); cout << "Знаменатель: " << a.getZn() << endl; break;
		case 7: {RNum b(a); b.Print();
			break;
		}
		case 8: cout << PrintFloat(a) << endl; break;
		case 9: cout << "Изменить дробь b=3/4?" << endl;
			cout << "1-ДА        2-НЕТ" << endl;
			cin >> otv;
			if (otv == 2)
			{
				cout << a * b << endl; break;
			}
			else
			{
				b.Scan();
				cout << a * b << endl; break;
			}
			
		case 10: cout << "Введите целое число: " << endl;
			cin >> c;
			cout << a * c << endl; break;
		case 11:  cout << "Изменить дробь b=3/4?" << endl;
			cout << "1-ДА        2-НЕТ" << endl;
			cin >> otv;
			if (otv == 2)
			{
				if (a == b) cout << "Числа равны" << endl;
				else cout << "Числа не равны"; break;
			}
			else
			{
				b.Scan();
				if (a == b) cout << "Числа равны" << endl;
				else cout << "Числа не равны"; break;
			}
			
			
			if (a == b) cout << "Числа равны" << endl;
				 else cout << "Числа не равны"; break;
		case 12:
			cout << "Введите целое число: " << endl;
			cin >> c;
			if (a == c) cout << "Числа равны" << endl;
			else cout << "Числа не равны" << endl; break;

		}
		getchar();
		getchar();
	} while (menu != 13);


	return 0;
}








