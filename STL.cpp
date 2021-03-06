/* Вариант 5: Типы аргументов double и char.
1. Поиск наименьшего неотрицательного элемента массива.
2. АТД Дек с ограниченным выходом. Структура хранения – связный список */

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

template <class data>
data search(vector<data> arr)
{
	vector<data> tmp;
	copy_if(arr.begin(), arr.end(), back_inserter(tmp), [](data x) {return x >= 0; });
	return *min_element(tmp.begin(), tmp.end());
}


template <class data2>  class deque
{
private:
	list <data2> dec;
public:
	deque()
	{

	}

	~deque()
	{

	}

	void del_deque()
	{
		dec.clear();
	}

	void in_r(data2 in)
	{
		if (!dec.empty())
		{
			dec.push_back(in);
			cout << "Элемент добавлен вправо" << endl;
		}
		else
		{
			dec.push_front(in);
			cout << "Добавленный элемент первый" << endl;
		}
	}

	void in_l(data2 in)
	{
		if (!dec.empty())
		{
			dec.push_front(in);
			cout << "Элемент добавлен влево" << endl;
		}
		else
		{
			dec.push_back(in);
			cout << "Добавленный элемент первый" << endl;
		}
	}

	data2 out_l()
	{
		if (dec.empty())
		{
			cout << "Дек пуст. Возвращен 0" << endl;
			return 0;
		}
		else
		{
			data2 n;
			n = dec.front();
			dec.pop_front();
			return n;
		}
	}

};

template <class data>
void poisk(vector <data> arr)
{
	int i=0, j=0, n;
	cout << "Введите количество элементов массива: " << endl;
	cin >> n;
	data p, x;

	arr.reserve(n);
	for (int i = 0; i < n; i++) 
		
		{
		cout <<endl<< "Введите элемент №" <<i+1<< endl;
			cin >> x;
			arr.push_back(x);
		}
	
	p = search(arr);
	cout << endl << "Значение минимального неотрицательного элемента равно " << p << endl;
	arr.clear();
}

template <class data>
void DEQUE(deque <data> dec)
{
	char menu;
	data data1;
	do
	{
		system("CLS");
		cout << "1. Добавить элемент вправо" << endl;
		cout << "2. Добавить элемент влево " << endl;
		cout << "3. Извлечь элемент с левого конца " << endl;
		cout << "4. Конец тестирования" << endl;
		cin >> menu;
		switch (menu)
		{
		case '1':
			system("CLS");
			cout << "Введите значение элемента: " << endl;
			cin >> data1;
			dec.in_r(data1);
			break;
		case '2':
			system("CLS");
			cout << "Введите значение элемента: " << endl;
			cin >> data1;
			dec.in_l(data1);
			break;
		case '3':
			system("CLS");
			cout << dec.out_l();
			break;
		case '4':
			system("CLS");
			dec.del_deque();
			break;
		}
		getchar(); getchar();
	} while (menu != '4');
}

int main()
{
	setlocale(LC_ALL, "Russian");

	vector <char> c;
	vector <double> d;

	char menu;
	do
	{
		system("CLS");
		cout << "1. Тестирование шаблона функции" << endl;
		cout << "2. Тестирование шаблона класс" << endl;
		cout << "3. Конец тестирования" << endl;
		cin >> menu;
		switch (menu)
		{
		case '1':
			system("CLS");
			cout << "1. Проверка типа double" << endl;
			cout << "2. Проверка типа char" << endl;
			cin >> menu;
			switch (menu)
			{
			case'1':
				poisk(d);
				break;
			case '2':
				poisk(c);
				break;
			} getchar(); getchar(); break;
		case '2':
			system("CLS");
			cout << "1. Создание АТД: дек с ограниченным выходом. Тип doble " << endl;
			cout << "2. Создание АТД: дек с ограниченным выходом. Тип char" << endl;
			cin >> menu;
			if (menu == '1')
			{
				deque<double> dec;
				DEQUE(dec);
			}
			else if (menu == '2')
			{
				deque<char> dec;
				DEQUE(dec);
			}

		}
	} while (menu != '3');
	return 0;
}
