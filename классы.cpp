/* ����� ������������� ����� (��). ����: ���������, �����������. ������: ����������
�������� ���������� ���� � float, �������� ��������� �*� ���� �� � �� � ����� ������,
��������� �� ��������� �==� ���� �� � �� � ����� ������. */

#include <stdio.h> //����������� ���������
#include <iostream>
#include <locale.h>

using namespace std; //������������ ����

class RNum //����������� ������
{
	private: 
	float ch, zn;
	public: 
	
	RNum (float a, float b) //�������� ������������ � �����������
	{
		ch=a;
		zn=b;
		cout << "����������� � ����������� ������� ��������!" <<"("<<this<<")"<< endl  << endl;
	}
	
	~RNum () //�������� �����������
	{
		cout << "���������� ������� ��������!" <<"("<<this<<")" <<endl << endl;
	}
	
	RNum (const RNum &other) //�������� ������������ �����������
	{
		this->ch=other.ch;
		this->zn=other.zn;
		cout << "����������� ����������� ������� ��������!" <<"("<<this<<")" <<endl << endl;
	}
	
	float getCh() {return ch;}; //���� ��������� � ����������
	
	float getZn() {return zn;}; //���� ����������� � ����������
	
	void setCh(float a) //��������� ���������
	{
		ch=a;
	}
	
	void setZn(float a) //��������� �����������
	{
		zn=a;
	}
	
	void Print() //������� ��� ������ ��������� � ����������� �� �����
	{
		cout <<"��������� ����� "<<ch<<endl<<"����������� ����� "<<zn<<endl;
	}
	
	void Scan() //������� ����� ��������� � ����������� 
	{
		cout<<"������� ���������: ";
		cin>>ch;
		cout<<"������� �����������: ";
		cin>>zn;
		Print ();
	}
	//�������� ����������
	operator float() {return ch/zn;} //���������� ���������� � ���� float
	float operator * (const RNum &other) //���������� ��������� ���� ������
	{
		this->ch*=other.zn;
		this->zn*=other.ch;
		return ch/zn;
	}
	float operator * (int a) //���������� ��������� ����� � ������ �����
	{
		this->zn*=a;
		return ch/zn;
	}
	
	bool operator == (const RNum &other) //���������� ��������� �� ��������� ���� ������
	{
		return (this->ch/this->zn)==(other.ch/other.zn);
	 } 
	bool operator == (int a) //���������� ��������� �� ��������� ����� � ������ �����
	
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
	//����������� ����
		do {
		cout <<"\t����:"<<endl;
		cout << "1-���� ������ � ����������" << endl;
		cout << "2-����� ������ �� �����" << endl;
		cout << "3-����� ���������" << endl;
		cout << "4-����� �����������" << endl;
		cout << "5-��������� ���������" << endl;
		cout << "6-��������� �����������" << endl;
		cout << "7-�����������" << endl;
		cout << "8-���������� � ���� float" << endl;
		cout << "9-�������� ��������� ���� ������������ �����" << endl; 
		cout << "10-�������� ��������� ������������� � ������ �����" << endl;
		cout << "11-��������� �� ��������� ���� ������������ �����" << endl;
		cout << "12-��������� �� ��������� ������������� � ������ �����" << endl;
		cout << "13-�����"<<endl<<endl;
		cout << "�������� ����� ����: " << endl; 
		cin >> menu;
		
		RNum a(1,2), b(3,4);// (??)
		switch (menu)
		{
			case 1: a.Scan(); break;
			case 2: a.Print(); break;
			case 3: cout<<"���������: "<<a.getCh()<<endl; break;
			case 4: cout<<"�����������: "<<a.getZn()<<endl; break;
			case 5: a.setCh(20); cout<<"���������: "<<a.getCh()<<endl; break;
			case 6: a.setZn(10); cout<<"�����������: "<<a.getZn()<<endl; break;
			case 7: {RNum b(a); b.Print();
				break;
			}
			case 8: cout<<PrintFloat(a)<<endl; break;
			case 9: cout<<a*b<<endl; break;
			case 10: cout<<"������� ����� �����: "<<endl;
			cin>>c;
			cout<<a*b<<endl; break;
			case 11: if (a==b) cout<<"����� �����"<<endl; 
			else cout<<"����� �� �����"; break;
			case 12:
			cout <<"������� ����� �����: "<<endl;
			cin>>c;
			if (a==c) cout<<"����� �����"<<endl;
			else cout<<"����� �� �����"<<endl; break;	
		
		}	
	} while (menu!=13);
	
	
	return 0;
}




