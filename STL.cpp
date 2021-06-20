/* Вариант 5: Типы аргументов double и char.
1. Поиск наименьшего неотрицательного элемента массива.
2. АТД Дек с ограниченным выходом. Структура хранения – связный список */

#include <iostream>
#include <vector>
#include <list>

using namespace std;

template <class data>
data search(data arr[], int n)
{
	int j;
	data p = 1000000000;
	for (j = 0; j < n; j++)
	{
		if (arr[j] > 0 && arr[j] < p)
			p = arr[j];
	}
	return p;
}

template <class data2> class deque
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
void poisk(data *arr)
{
	int i, n;
	cout << "Введите количество элементов массива: " << endl;
	cin >> n;
	data p;
	arr = new data[n];
	for (i = 0; i < n; i++)
	{
		cout << endl << "Введите " << i + 1 << " элемент:";
		cin >> arr[i];
	}
	p = search(arr, n);
	cout << endl << "Значение минимального неотрицательного элемента равно " << p << endl;
	delete[]arr;
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
		cout << "Конец тестирования" << endl;
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

	double *d = nullptr;
	char *c = nullptr;
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
