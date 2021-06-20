#include <iostream>
#include <cstring>
#include <string.h>
#include <stdio.h>
#include <cstdio>
#include <cstdlib>

#define _CRT_SECURE_NO_WARNINGS

using namespace std;

class String
{

protected:
	void set_string(char * string1)
	{
		if (string1 == NULL)
		{
			cout << "Создана пустая строка" << endl;
			string1 = new char;
			string1[0] = '\0';
		}
		else this->string1 = string1;
	}

	void set_length(int length)
	{
		this->length = length;
	}
	char *string1;
	int length;

public:
	char * get_string()
	{
		return this->string1;
	}
	String()
	{
		set_length(0);
		string1 = new char;
		string1[0] = '\0';
		cout << "String: сработал конструктор без параметров" << endl;
	}

	String(char *String)
	{
		string1 = new char[strlen(String) + 1];
		length = strlen(String);
		strcpy_s(string1, strlen(String) + 1, String);
		cout << "String: сработал конструктор с параметрами" << endl;
	}

	String(char c)
	{
		this->length = 1;
		string1 = new char;
		string1[0] = c;
		cout << "String: вызван конструктор с параметрами" << endl;
	}

	String(String & string2)
	{
		static int k = 0;
		length = string2.length;
		string1 = string2.string1;
		k++;
		cout << "String: конструктор копирования сработал " << k << " раз" << endl;
	}

	~String()
	{
		delete[] this->string1;
		cout << "String: вызван деструктор" << endl;
	}

	int get_length()
	{
		return this->length;
	}

	char *  get_string1()
	{
		return this->string1;
	}

	String& operator = (const String& other)
	{
		delete[]string1;
		length = other.length;
		string1 = new char[this->length];
		strcpy_s(string1, strlen(string1), other.string1);
		return *this;
	}

	ostream& operator << (ostream& out)
	{
		if (*string1 != '\0')
			if (length == 1)
				out << *string1;
			else out << string1;
		else cout << "Строка пуста" << endl;
		return out;
	}

};

class ID_String : public String
{

public:
	ID_String()
	{
		this->string1 = nullptr;
		this->length = 0;
		cout << "ID_String: вызван конструктор без параметров" << endl;
	}

	ID_String(char * c)
	{
		int i;
		this->string1 = c;
		this->length = 0;

		for (i = 0; this->string1[i] != '\0'; i++)
		{
			if (!(this->string1[i] >= 'A' && this->string1[i] <= 'Z' || this->string1[i] >= 'a' && this->string1[i] < 'z') && (i == 0 && !(this->string1[i] >= '0' && this->string1[i] <= '9')))
			{
				this->string1 = nullptr;
				this->length = 0;
				break;
			} this->length++;

		} cout << "ID_String: вызван конструктор с параметрами (символ)" << endl;

	}

	~ID_String()
	{
		this->length = 0;
		delete[] this->string1;
		cout << "ID_String: вызван деструктор" << endl;
	}


	bool operator > (const ID_String& other)
	{
		if (strcmp(this->string1, other.string1) > 0) return true;
		else return false;
	}

	bool operator < (const ID_String& other)
	{
		if (strcmp(this->string1, other.string1) < 0) return true;
		else return false;
	}

	int find_last(char c)
	{
		int i, j = 0;


		if (this->string1 == NULL)
			return 0;

		for (i = 0; i < this->length; i++)
		{
			if (this->string1[i] == c)
				j = i;
		}

		return j;
	}
};

class Des_String : public String
{

public:

	Des_String()
	{
		this->string1 = nullptr;
		this->length = 0;
		cout << "Des_String: вызван конструктор без параметров" << endl;
	}

	Des_String(char * des)
	{
		int i = 0;
		char * des_s;

		if (!(des[0] == '-' || des[0] == '+' || des[0] >= '0' || des[0] <= 9))
		{
			delete get_string();
			des_s = new char;
			des_s[0] = '0';
			set_string(des_s);
			this->length = 1;
			cout << "класс Des_string: сработал конструктор с параметрами, принято нулевое значение (1)" << endl;

		}
		else { ; i++; }
		for (int j = 1; j < strlen(des); j++)
		{
			if (des[j] >= '0' || des[j] <= '9') { i++; }
		}
		if (i == strlen(des))
		{
			delete get_string();
			des_s = new char[strlen(des) + 1];
			strcpy_s(des_s, strlen(des) + 1, des);
			set_string(des_s);
			this->length = i;
			cout << "Des_String: сработал конструктор с параметрами" << endl;
		}
		else
		{
			des_s = new char;
			*des_s = '0';
			set_string(des_s);
			this->length = 1;
			cout << "Des_String: сработал конструктор с параметрами, принято нулевое значение (2)" << endl;
		}

	}

	Des_String(const Des_String& other)
	{
		int i;
		char *temp = new char[other.length + 1];

		for (i = 0; other.string1[i] != '\0'; i++)
			temp[i] = other.string1[i];
		temp[i] = '\0';
		this->string1 = temp;
		this->length = other.length;
		cout << "Des_String: вызван конструктор копирования" << endl;
	}

	~Des_String()
	{
		this->length = 0;
		delete[] this->string1;
		cout << "Des_String: вызван деструктор" << endl;
	}

	bool int_opr()
	{
		int chislo;
		if (this->string1[0] == '+')
		{
			if (this->length > 6) return false;
			else if ((chislo = atoi(this->string1)) > 32676) return false;
			else return true;
		}
		if (this->string1[0] == '-')
		{
			if (this->length > 6) return false;
			else if ((chislo = atoi(this->string1)) < (-32676)) return false;
			else return true;
		}
	}

	void reverse(char* string1)
	{
		int i = 0;
		int j = strlen(string1) - 1;
		char x;
		while (j - i > 0) {
			x = string1[i];
			string1[i] = string1[j];
			string1[j] = x;
			i++;
			j--;
		}
	}


		Des_String operator-(const Des_String& str1, const Des_String& str2)
		{
			int x = str1.string1[0] == '-' || str1.string1[0] == '+';
			char* fir = new char[strlen(str1.string1) - x + 1];
			for (int i = x; i <= strlen(str1.string1); i++)
			{
				fir[i - x] = str1.string1[i];
			}
			reverse(str1);

			x = str2.string1[0] == '+' str2.string2 == '-';
			char* sec = new char[strlen(str2.string1) - x + 1];
			for (int i = x; i <= strlen(str2.string1); i++)
			{
				sec[i - x] = str2.string1[i];
			}
			reverse(str2);

			char *new_s = new char[strlen(str1.string1) + strlen(str2.string1) + 2];
			char l;
			if (str1.string1[0] == '-' || str1.string1[0] == '+')
			{
				l = str1.string[0];
			}
			else { l = '+'; }
			char r;
			if (str2.string1[0] == '-' || str2.string1[0] == '+')
			{
				l = str2.string[0];
			}
			else { r = '+'; }

			int i=0;


			if (l == '+' && r == '+')
			{
				bool rem = 0;
				int curr = 0;
				i = 0;
				while (i < strlen(str1.string1) || i < strlen(str2.string1))
				{
					int str1 = i < strlen(fir) ? fir[i] - '0' : 0;
					int str2 = i < strlen(sec) ? fir[i] - '0' : 0;
					curr = fir - sec - rem;
					rem = 0;
					if (curr < 0)
					{
						curr += 10;
						rem++;
					}
					new_s[i] = curr + '0';
					i++;
				}
				if (rem)
				{
					rem = 0;
					curr = 0;
					i = 0;
					while (i < strlen(fir) || i < strlen(sec))
					{
						int str1 = i < strlen(fir) ? fir[i] - '0' : 0;
						int str2 = i < strlen(sec) ? sec[i] - '0' : 0;
						curr = sec - fir - rem;
						rem = 0;
						if (curr < 0)
						{
							curr += 10;
							rem++;
						}
						new_s[i] = curr + '0';
						i++;
					}
					new_s[i] = '-';
					i++;
					}
				}


			else if (l == '-' || r == '-')
			{
				bool rem = 0;
				int curr = 0;
				i = 0;
				while (i < strlen(fir) || i < strlen(sec))
				{
					int str1 = i < strlen(fir) ? fir[i] - '0' : 0;
					int str2 = i < strlen(sec) ? fir[i] - '0' : 0;
					curr = fir - sec - rem;
					rem = 0;
					if (curr < 0)
					{
						curr += 10;
						rem++;
					}
					new_s[i] = curr + '0';
					i++;

				}
				if (rem)
				{
					rem = 0;
					curr = 0;
					i = 0;
					while (i < strlen(fir) || i < strlen(sec))
					{
						int str1 = i < strlen(fir) ? fir[i] - '0' : 0;
						int str2 = i < strlen(sec) ? sec[i] - '0' : 0;
						curr = fir - sec - rem;
						rem = 0;
						if (curr < 0)
						{
							curr += 10;
							rem++;
						}
						new_s[i] = curr + '0';
						i++;
					}
					new_s[i] = '-';
					i++;
				}
			}

			
			else if (l == '-' && r == '+')
			{
				bool rem = 0;
				int curr = 0;
				i = 0;
				while (i < strlen(fir) || i < strlen(sec))
				{
					int str1 = i < strlen(fir) ? fir[i] - '0' : 0;
					int str2 = i < strlen(sec) ? sec[i] - '0' : 0;
					curr = fir + sec + rem;
					rem = 0;
					new_s[i] = curr % 10 + '0';
					rem = curr >= 10;
					i++;
				}
				if (rem)
				{
					new_s[i] = rem + '0';
					i++;
				}
				new_s[i] = '-';
				i++;
			}

			else if (l == '+' && r == '-')
			{
			bool rem = 0;
			int curr = 0;
			i = 0;
			while (i < strlen(fir) || i < strlen(sec))
			{
				int str1 = i < strlen(fir) ? fir[i] - '0' : 0;
				int str2 = i < strlen(sec) ? sec[i] - '0' : 0;
				curr = fir + sec + rem;
				rem = 0;
				new_s[i] = curr % 10 + '0';
				rem = curr >= 10;
				i++;
			}
			if (rem)
			{
				new_s[i] = rem + '0';
				i++;
			}
			}
			new_s[i] = '\0';
			delete[] sec;
			delete[] fir;
			reverse(new_s);
			return new_s;
		}


		bool operator > (const Des_String& other)
		{
			if (strcmp(this->string1, other.string1) > 0)
				return true;
			else return false;
		}
	};

	int main()
	{
		setlocale(LC_ALL, "Russian");
		char *str;
		int n = 0, i = 0, size, j, menu;
		String ** strings = nullptr;

		do
		{
			system("CLS");
			cout << "1. Инициализация" << endl << "2. Тестирование" << endl << "9. Выход" << endl;
			cin >> menu;
			getchar();
			switch (menu)
			{
			case 1:

				do
				{
					system("CLS");
					cout << "1. Ввести число элементов" << endl;
					cout << "2. Ввести начальные значение" << endl;
					cout << "3. Назад" << endl;
					cin >> menu;

					switch (menu)
					{
					case 1:
						if (strings == NULL)
						{
							do
							{
								cout << "Введите число элементов:" << endl;
								cin >> size;
								getchar();
							} while (size <= 0);

							strings = new String*[size];

						} break;
					case 2:
						if (strings != NULL)
						{
							do
							{
								cout << "Введите номер нового элемента: ";
								cin >> i;
								getchar();
							} while (i <= 0 || i > size);

							do
							{
								cout << "Выберите тип нового элемента:	 1) Строка	  2) Строка-идентификатор		3) Десятичная строка" << endl;
								cin >> j;
								getchar();
							} while (j < 1 || j>3);

							cout << "Введите значение нового элемента: " << endl;
							str = new char[80];
							cin.getline(str, 80);

							switch (j)
							{
							case 1:
								strings[i - 1] = new String(str);
								break;

							case 2:
								strings[i - 1] = new ID_String(str);
								break;

							case 3:
								strings[i - 1] = new Des_String(str);
								break;
							}

							i = j = 0;
							getchar();

						} break;
					}
				} while (menu != 3);

				break;

			case 2:
				if (strings != NULL)
					do
					{
						system("CLS");
						cout << "1. Строка" << endl << "2. Строка-идентификатор" << endl << "3. Десятичная строка" << endl << "4. Задать операнды" << endl << "5. Назад" << endl;
						cin >> menu; getchar();
						switch (menu)
						{
						case 1:
							do
							{
								system("CLS");
								cout << "1. Вывести длину строки" << endl;
								cout << "2. Приравнять первый операнд ко второму" << endl;
								cout << "3. Назад" << endl;

								cin >> menu;
								getchar();

								if (menu == 1)
									cout << "Длина строки 1-го операнда: " << strings[i]->get_length() << endl;
								else if (menu == 2)
								{

									*strings[i] = *strings[j];
									cout << "1-ый операнд: " << strings[i]->get_string() << endl;
									cout << "2-ой операнд: " << strings[j]->get_string() << endl;
								}
								getchar();
							} while (menu != 3);
							break;

						case 2:
							do
							{
								system("CLS");
								cout << "1. Найти последнее вхождение заданного символа в строку" << endl;
								cout << "2. Проверить, является ли первый операнд больше второго" << endl;
								cout << "3. Проверить, является ли первый операнд меньше второго" << endl;
								cout << "4. Назад" << endl;
								cin >> menu;
								getchar();
								switch (menu)
								{
								case 1:
									cout << "Введите символ: " << endl;
									cout << "Последнее вхождение этого символа - " << ((ID_String*)strings[i])->find_last(getchar()) << endl;
									getchar();
									break;
								case 2:
									if (*(ID_String*)strings[i] > *(ID_String*)strings[j])
										cout << "1-ый операнд больше второго" << endl;
									else
										cout << "1-ый операнд не больше второго" << endl;
									break;
								case 3:
									if (*(ID_String*)strings[i] < *(ID_String*)strings[j])
										cout << "1-ый операнд меньше второго" << endl;
									else
										cout << "1-ый операнд не меньше второго" << endl;
									break;
								}
								getchar();
							} while (menu != 4);
							break;

						case 3:
							do
							{
								system("CLS");
								cout << "1. Проверить, можно ли представить первый операнд в формате int " << endl;
								cout << "2. Вычесть из первого операнда второй" << endl;
								cout << "3. Сравнить операнды" << endl;
								cout << "4. Назад" << endl;
								cin >> menu;
								getchar();
								switch (menu)
								{
								case 1:

									if ((*(Des_String*)strings[i - 1]).int_opr()) cout << "Число может быть представлено как int" << endl;
									else cout << "Число не может быть представлено как тип int" << endl;
									break;

								case 2:
								/*	*(Des_String*)strings[i - 1] = *(Des_String*)strings[i - 1] - *(Des_String*)strings[j - 1];
									cout << "Результат: " << (Des_String*)strings[i]->get_string() << endl;*/
									*(Des_String*)strings[i-1] - *(Des_String*)strings[j-1];
									break;

								case 3:

									if (*(Des_String*)strings[i] > *(Des_String*)strings[j])
										cout << "1-ый операнд больше второго" << endl;
									else
										cout << "1-ый операнд меньше или равен второму" << endl;
									break;

								}getchar();
							} while (menu != 4);
							break;

						case 4:
							cout << "Введите номер 1-го операнда: ";
							cin >> i;
							i = i - 1;
							getchar();

							cout << "Введите номер 2-го операнда: ";
							cin >> j;
							j = j - 1;
							getchar();

							break;
						}
					} while (menu != 5);
					break;
			}
		} while (menu != 9);

		return 0;
	}
