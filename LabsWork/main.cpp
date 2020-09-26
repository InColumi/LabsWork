#include <iostream>
#include <stdio.h>
#include <stdlib.h> // ��� �������� �� ������� ����
#include <ctime>
#include <string>
#include <windows.h>
using namespace std;

struct Store
{
	public:
	char Name[17];
	private:
	int _countCategories = 4;
	int _amountBooks;
	int* _categories = new int[_countCategories];
	
	void SetAmountBooks()
	{
		_amountBooks = 0;
		for(int i = 0; i < _countCategories; i++)
		{
			_amountBooks += _categories[i];
		}
	}

	public:
	int GetIndexMaxAmountBooks()
	{
		int max = _categories[0];
		int amountBooks = 0;
		int indexMax = 0;
		for(int i = 1; i < _countCategories; i++)
		{
			amountBooks = _categories[i];
			if(amountBooks > max)
			{
				max = amountBooks;
				indexMax = i;
			}
		}
		return indexMax;
	}

	void ShowNameCategoriesByIndex(int index)
	{
		
		switch(index)
		{
			case 0:
			{
				char name[14] = { '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�' };
				for(int i = 0; i < 14; i++)
				{
					cout << name[i];
				}
				break;
			}
				
			case 1:
			{
				char name[10] = { '�', '�', '�', '�', '�', '�', '�', '�', '�', '�' };
				for(int i = 0; i < 10; i++)
				{
					cout << name[i];
				}
				break;
			}
				
			case 2:
			{
				char name[9] = { '�', '�', '�', '�', '�', '�', '�', '�', '�' };
				for(int i = 0; i < 9; i++)
				{
					cout << name[i];
				}
				break;
			}
				
			case 3:
			{
				char name[15] = { '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�', '�' };
				for(int i = 0; i < 15; i++)
				{
					cout << name[i];
				}
				break;
			}

		}

	}

	void SetArtBooks(int amount)
	{
		_categories[0] = amount;
	}

	void SetSportBooks(int amount)
	{
		_categories[1] = amount;
	}

	void SetEducationBooks(int amount)
	{
		_categories[2] = amount;
	}

	void SetEntertainingBooks(int amount)
	{
		_categories[3] = amount;
	}

	int GetArtBooks()
	{
		return _categories[0];
	}

	int GetSportBooks()
	{
		return _categories[1];
	}

	int GetEducationBooks()
	{
		return _categories[2];
	}

	int GetEntertainingBooks()
	{
		return _categories[3];
	}

	int GetAmountBooks()
	{
		return _amountBooks;
	}

	void ShowNames()
	{
		printf("%-0.17s\t%-0.17s\t%-0.17s\t%-0.17s\t%-0.17s\n", "�������� ��������", "�������������", "����������", "���������", "���������������");
	}

	void ShowValueInfo()
	{
		printf("%-17s\t%-13d\t%-10d\t%-9d\t%-17d\n", Name, _categories[0], _categories[1], _categories[2], _categories[3]);
	}

	void InputFromConsole()
	{
		int inputUser;
		cout << "������� �������� �������� ��������: ";
		cin >> Name;
		cout << "������� ���-�� ��������� �������������� ����: ";
		cin >> inputUser;
		SetArtBooks(inputUser);
		cout << "������� ���-�� ��������� ���������� ����: ";
		cin >> inputUser;
		SetSportBooks(inputUser);
		cout << "������� ���-�� ��������� ������� ����: ";
		cin >> inputUser;
		SetEducationBooks(inputUser);
		cout << "������� ���-�� ��������� ��������������� ����: ";
		cin >> inputUser;
		SetEntertainingBooks(inputUser);
		SetAmountBooks();
	}

	/*void SetValue(int artBooks, int sportBooks, int educationBooks, int entertainingBooks)
	{
		ArtBooks = artBooks;
		SportBooks = sportBooks;
		EducationBooks = educationBooks;
		EntertainingBooks = entertainingBooks;
		SetAmountBooks();
	}*/
	int GetValueCategotyByNumber(int number)
	{
		int value;
		switch(number)
		{
			case 1:
			{
				value = GetArtBooks();
				break;
			}	
			case 2:
			{
				value = GetSportBooks();
				break;
			}
			case 3:
			{
				value = GetEducationBooks();
				break;
			}
			case 4:
			{
				value = GetEntertainingBooks();
				break;
			}
		}
		return value;
	}
};

Store* GenerateStores(int countSores)
{
	char* names = *new char[6][12]{ 
		"�������", 
		"�������", 
		"������", 
		"�������",
		"������", 
		"�����" };
	int randMaxNumber = 10;
	Store* newStores = new Store[countSores];
	for(int i = 0; i < countSores; i++)
	{
		cout << "���: ";
		cin >> newStores[i].Name;
		newStores[i].SetArtBooks(0 + rand() % randMaxNumber);
		newStores[i].SetSportBooks(0 + rand() % randMaxNumber);
		newStores[i].SetEducationBooks(0 + rand() % randMaxNumber);
		newStores[i].SetEntertainingBooks(0 + rand() % randMaxNumber);
	}
	return newStores;
}

void Generator(int countStores)
{
	srand(time(0));
	Store* stores = GenerateStores(countStores);
	stores[0].ShowNames();
	for(size_t i = 0; i < countStores; i++)
	{
		stores[i].ShowValueInfo();
	}
}

void Initialization(Store& store)
{
	store.InputFromConsole();
}

void ShowStoreToConsole(Store& store, bool isShowMaxAmountBooks = true, bool isShowNamesCategort = true)
{
	if(isShowNamesCategort)
	{
		store.ShowNames();
	}
	
	store.ShowValueInfo();
	if(isShowMaxAmountBooks)
	{
		cout << "����� ������� ����: " << store.GetAmountBooks();
		cout << "\n������ ����� ������� ";
		store.ShowNameCategoriesByIndex(store.GetIndexMaxAmountBooks());
	}
	
	cout << '\n';
}

void ShowStoreInTable(Store* stores, int size)
{
	ShowStoreToConsole(stores[0], false);
	for(int i = 1; i < size; i++)
	{
		ShowStoreToConsole(stores[i], false, false);
	}
	cout << "------------------------------------------------------------------------\n";
}

void Laba1()
{
	Store store;
	Initialization(store);
	ShowStoreToConsole(store);
}

int ReturnIndexMaxByAmount(int* arr, int size)
{
	int max = arr[0];
	int index = 0;
	for(int i = 1; i < size; i++)
	{
		if(max <arr[i])
		{
			max = arr[i];
			index = i;
		}
	}
	return index;
}

void Laba2()
{
	cout << "������� ���-�� ���������: ";
	int countStores;
	cin >> countStores;
	Store* stores = new Store[countStores];
	int* amountsBooks = new int[countStores];
	for(int i = 0; i < countStores; i++)
	{
		Initialization(stores[i]);
		amountsBooks[i] = stores[i].GetAmountBooks();
		cout << "------------------------------------------------------------------------\n";
	}
	system("cls");
	ShowStoreInTable(stores, countStores);
	int index = ReturnIndexMaxByAmount(amountsBooks, countStores);
	cout << "������ ����� ������: \n";
	ShowStoreToConsole(stores[index]);
}

void SortStoreByNubmerColum(Store* stores, int size, int column, bool inAscendingOrder = true)
{
	for(int i = 0; i < size - 1; i++)
	{
		for(int j = 0; j < size - i - 1; j++)
		{
			if(inAscendingOrder)
			{
				if(stores[j].GetValueCategotyByNumber(column) > stores[j + 1].GetValueCategotyByNumber(column))
				{
					// ������ �������� �������
					Store tempStore = stores[j];
					stores[j] = stores[j + 1];
					stores[j + 1] = tempStore;
				}
			}
			else
			{
				if(stores[j].GetValueCategotyByNumber(column) < stores[j + 1].GetValueCategotyByNumber(column))
				{
					// ������ �������� �������
					Store tempStore = stores[j];
					stores[j] = stores[j + 1];
					stores[j + 1] = tempStore;
				}
			}
		}
	}
}

void Laba3()
{
	int countStores = 3;
	Store* stores = new Store[countStores];

	for(int i = 0; i < countStores; i++)
	{
		Initialization(stores[i]);
		cout << "------------------------------------------------------------------------\n";
	}
	system("cls");
	ShowStoreInTable(stores, countStores);

	cout << "������� ����� ������� ��� ����������: ";
	int numberOfColumn;
	cin >> numberOfColumn;
	if(numberOfColumn < 0 || numberOfColumn > 4)
	{
		cout << "�� ����� ������ ����� �������\n";
		exit(0);
	}
	SortStoreByNubmerColum(stores, countStores, numberOfColumn);
	ShowStoreInTable(stores, countStores);
}

int main()
{
	system("chcp 1251"); // ��������� � ������� �� ������� ����
	system("cls");
	setlocale(LC_ALL, "Russian");
	//Laba1();
	//Laba2();
	Laba3();
	//Generator(1);
	
	return 0;
}