#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
class NUMER
{
	char strb[20];
	char stre[50];
	unsigned int osnova;

public:
	NUMER();
	NUMER(char*, unsigned int);
	~NUMER() {}
	void Perevod();
	bool Analiz();
public:
	void Print();
};
NUMER::NUMER()
{
	cout << "ЧИСЛО" << endl;
	cin >> strb;
	cout << "ОСНОВАНИЕ" << endl;
	cin >> osnova;

}

void NUMER::Perevod()
{
	int i1 = atoi(strb);
	int k;
	int j;
	int i2 = atoi(strb);
	int Sum = 0, n = 0;
	do
	{
		i1 = i1 / 10;
		n++;
	} while (i1 != 0);

	for (int i = 0; i < n; i++)
	{
		k = i2 % 10;
		i2 = i2 / 10;
		j = (k)*pow(osnova, i);
		Sum += j;
	}
	_itoa_s(Sum, stre, 10);


}
bool NUMER::Analiz()
{

	if (osnova < 2 || osnova>9)
	{
		cout << "Неверное основание" << endl;
		return false;
	}

	for (int i = 0; i < strlen(strb); i++)
	{
		if (strb[i] - '0' > osnova - 1)
		{
			cout << "Неверное основание" << endl;
			return false;
		}
		if (isdigit(strb[i]) == 0)
		{
			cout << "Некорректные символы" << endl;
			return false;
		}
	}
	return true;
}
void NUMER::Print()
{
	cout << stre;
}
int main()
{
	setlocale(0, "");
	NUMER num;
	num.Perevod();
	if (num.Analiz() == true) num.Print();
}
