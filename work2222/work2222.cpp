#include <iostream>
#include <cmath>
#include <string>
#include <string.h>
#include <cstdlib>
#include <fstream>
#include <Windows.h>
using namespace std;
// Функции...
void Start();
void SummonmenuNoLog();
void SummonmenuLog();
void Selling();
void CreateStorage();
template<typename ArrType>
void FillArray(ArrType staticArr[], ArrType dinArr[], int size);
bool Password(int passwordsNum, bool retur);
template<typename ArrType>
void PrintArray(ArrType dinArr[], int size);
void Shop();
void Delete();
void OpenStore();
void IzmPrise();
// Значения...
int siz = 10;
int* idArr = new int[siz];
string* nameArr = new string[siz];
int* countArr = new int[siz];
double* priceArr = new double[siz];
// Значения чека...
int receoptSize = 1;
string* nameReciptArr = new string[receoptSize];
int* countReceiptArr = new int[receoptSize];
double* receoptPriceArr = new double[receoptSize];

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));

	Start(); // Морожонное! Cладкое, Не Очень сладкое, Прям сладкое морожонное, Очень сладное, Клубничное.

	Delete();
	return 0;
}
void Delete()
{
	delete[]priceArr;
	delete[]countArr;
	delete[]nameArr;
	delete[]idArr;

	delete[]nameReciptArr;
	delete[]countReceiptArr;
	delete[]receoptPriceArr;
}
void Start()
{
	int leave;
	bool exit = false;
	int password;
	bool bols = false;
	do
	{
		SummonmenuNoLog();
		cin >> password;
		if (Password(password, bols) == true)
		{
			exit = true;
			SummonmenuLog();
		}
		else
		{
			cerr << "Неверные логин или пароль\n";
			cout << "Выйти из программы?\n1) Да 2) Нет\n";
			cin >> leave;
			if (leave == 2) {}
			else
			{
				break;
			}
		}
	} while (exit != true);
}
void SummonmenuNoLog()
{
	system("cls");
	cout << "[]======================================================================[]\n\n";
	cout << "\t\tДобро Пожаловать в 'Теплый ледъ'\n";
	cout << "\t\t    Введите Пароль\n\nВвод: ";
}
bool Password(int passwordsNum, bool retur)
{

	if (passwordsNum == 2311)
	{
		return retur = true;
	}
	else
	{
		return retur = false;
	}
}
void CreateStorage()
{
	const int sizest = 10;
	int id[sizest]{ 0,1,2,3,4,5,6,7,8,9 };
	string name[sizest]{ "Cладкое ", "Карамель", "Фруктовое", "Огурцовое", "Клубничное", "Шоколадное"
	, "Банановое", "Пустое  ", "Ванильное", "Кокосовое" };
	int count[sizest]{ 4,2,3,3,5,1,4,0,2,1 };
	double price[sizest]{ 125 , 150.75, 149.89 , 72.85 ,179.89, 240.20, 345.50, 65.65, 94.85, 139.98 };
	FillArray(id, idArr, sizest);
	FillArray(name, nameArr, sizest);
	FillArray(count, countArr, sizest);
	FillArray(price, priceArr, sizest);
}
void SummonmenuLog()
{
	int vibor;
	do
	{
		system("cls");
		cout << "[]======================================================================[]\n\n";
		cout << "\t\tДобро Пожаловать в 'Теплый ледъ'\n";
		cout << "\t\t   Выберите, что сделать\t\n\n1) Открыть Действ. Склад  \t\n2) Создать новый Cклад\n\n";
		cin >> vibor;
	} while (vibor < 1 || vibor > 2);
	if (vibor == 1)
	{
		CreateStorage();
		Shop();
	}
	else
	{
		cout << "in progressive";
	}
}
template<typename ArrType>
void FillArray(ArrType staticArr[], ArrType dinArr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		dinArr[i] = staticArr[i];
	}
}
template<typename ArrType>
void PrintArray(ArrType dinArr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << dinArr[i] << " ";
	}
}
void Shop()
{
	int ch;

	while (true)
	{
		do
		{
			system("cls");
			cout << "[]======================================================================[]\n\n";
			cout << "\t\t#Welcom To admin menu storage#\n\n";

			cout << "1) Показать Склад(готово)\n2) Начать Продажу(не готово)\n3) Изм. Цену(готово)\n4) Списать Товар(не готово)\n5) Пополнить Товар(не готово)\n6) Изменить Товар(не готово)\n0) Стоп смену(готово)\n";
			cin >> ch;
		} while (ch < 0 || ch > 6);
		if (ch == 1)
		{
			system("cls");
			OpenStore();
			system("pause");
		}
		else if (ch == 2)
		{
			system("cls");
			Selling();
		}
		else if (ch == 3)
		{
			system("cls");
			IzmPrise();
		}
		else if (ch == 4)
		{

		}
		else if (ch == 5)
		{

		}
		else if (ch == 6)
		{

		}
		else if (ch == 0)
		{
			break;
		}
		else
		{
			cerr << "errrrr";
		}



	}

}
void OpenStore()
{
	cout << "[]======================================================================[]\n";
	cout << "[]\tid\t\tName\t\t\tPrise\t\tCount   []\n[]——————————————————————————————————————————————————————————————————————[]\n";
	for (int i = 0; i < siz; i++)
	{
		cout << "#" << "\t " << idArr[i] + 1 << "\t\t" << nameArr[i] << "\t\t" << priceArr[i] << "\t\t  " << countArr[i] << "      #\n";
	}
	cout << "[]======================================================================[]\n\n";
}
void IzmPrise()
{
	int vibor;
	double price;
	do
	{

		cout << "[]======================================================================[]\n\n";
		cout << "\tВведите id продукта\n\tВвод: ";
		cin >> vibor;
	} while (vibor < 0 || vibor > siz);
	system("cls");
	cout << "[]======================================================================[]\n\n";
	cout << "\tВведите цену для " << nameArr[vibor - 1] << " Cейчас ее цена: " << priceArr[vibor - 1] << "\n\tВвод: ";
	cin >> price;
	priceArr[vibor - 1] = price;
	system("cls");
	cout << "**************************************************************************\n\n";
	cout << "\tОперация Успешна! Товар:" << nameArr[vibor - 1] << " Изменил свою Цену на: " << priceArr[vibor - 1] << "\n\n";
	cout << "**************************************************************************\n\n";
	system("pause");

}
void Selling()
{
	int viborId, vibCount;
	int yesOrNot;
	while (true)
	{
		do
		{
			system("cls");
			cout << "[]======================================================================[]\n\n";
			cout << "\tВведите id продукта\n\tВвод: ";
			cin >> viborId;
			if (viborId < 1 || viborId > siz)
			{
				cerr << "\nThis is invalid id\n";
				system("pause");
				continue;
			}
			do
			{
				system("cls");
				cout << "[]======================================================================[]\n\n";
				cout << "\tВведите Сколько вам нужно " << nameArr[viborId - 1] << "\n\tСейчас на складе: " << countArr[viborId - 1] << "\n\tВвод: ";
				cin >> vibCount;
				if (vibCount < 1 || vibCount > countArr[viborId - 1])
				{
					cerr << "Товара не хватает\n";
					system("pause");
					continue;
				}
				else
				{
					break;
				}
			} while (true);

			system("cls");
			cout << "[]======================================================================[]\n\n";
			cout << "Вы выбрали " << nameArr[viborId - 1] << " В Количестве: " << vibCount << "\n";
			cout << "Подтвердите выбор:\n1)Да \n2)Нет \n";
			cin >> yesOrNot;
			if (yesOrNot == 2)
			{
				continue;
			}
			break;
			system("cls");
		} while (viborId < 0 || viborId > siz);
		break;
	}
}
