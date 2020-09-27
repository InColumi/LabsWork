#include <iostream>
#include <stdio.h>
#include <stdlib.h> // ��� �������� �� ������� ����
#include <ctime>
#include <string>
#include <windows.h>
#include <fstream>

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
	cout << "������� ���-�� ���������: ";
	int countStores;
	cin >> countStores;
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

void SaveToFile(Store* stores, int size, string fileName)
{
	ofstream out;
	out.open(fileName);
	if(out.is_open() == false)
	{
		cout << "���� �� ������!";
		exit(0);
	}

	for(int i = 0; i < size; i++)
	{
		out << stores[i].Name << " ";
		out << stores[i].GetArtBooks() << " ";
		out << stores[i].GetSportBooks() << " ";
		out << stores[i].GetEducationBooks() << " ";
		out << stores[i].GetEntertainingBooks() << "\n";
	}
	out.close();
}

void CommandHandler(bool &isNextCommand, Store* stores = NULL, int countStores = 0)
{
	bool isCorrectCommand = false;
	while(isCorrectCommand == false)
	{
		if(stores)
		{
			cout << "������� T, ���� ������ ��������� � ��������� ����.\n";
			cout << "������� B, ���� ������ ��������� � �������� ����.\n";
		}
		cout << "������� Y, ���� ������ ����������.\n";
		cout << "������� N, ���� ������ ����� �� ��������.\n";
		char command;
		cin >> command;

		switch(command)
		{
			case 'Y':
			{
				isCorrectCommand = true;
				system("cls");
				break;
			}
			case 'T':
			{
				if(stores)
				{
					string fileName = "fileInfo.txt";
					SaveToFile(stores, countStores, fileName);
					cout << "��������� ���� ������� ��� - " << fileName << "\n\n";
				}
				break;
			}
			case 'B':
			{
				if(stores)
				{
					string fileName = "fileInfoB.txt";
					SaveToFile(stores, countStores, fileName);
					cout << "�������� ���� ������� ��� - " << fileName << "\n";
				}
				
				break;
			}
			case 'N':
			{
				cout << "��������� ��������� �������������\n";
				isCorrectCommand = true;
				isNextCommand = false;
				break;
			}
			default:
				cout << "� �� ���� ����� �������, ���������� ���.";
				break;
		}
	}
}

void Laba4()
{
	cout << "������� ���-�� ���������: ";
	int countStores;
	cin >> countStores;
	Store* stores = new Store[countStores];

	for(int i = 0; i < countStores; i++)
	{
		Initialization(stores[i]);
		cout << "------------------------------------------------------------------------\n";
	}
	system("cls");
	ShowStoreInTable(stores, countStores);

	bool isNextCommand = true;
	while(isNextCommand)
	{
		cout << "������� ����� ������� ��� ����������: ";
		int numberOfColumn;
		cin >> numberOfColumn;
		if(numberOfColumn < 0 || numberOfColumn > 4)
		{
			cout << "�� ����� ������ ����� �������\n";
			exit(0);
		}
		SortStoreByNubmerColum(stores, countStores, numberOfColumn);
		system("cls");
		ShowStoreInTable(stores, countStores);
		CommandHandler(isNextCommand);
	}
}

void ReadFromFile()
{
	string line;
	ifstream in("fileInfo.txt");
	if(in.is_open() == false)
	{
		cout << "���� �� ������!";
		exit(0);
	}
	int countStores = 0;
	while(getline(in, line))
	{
		cout << line << endl;
	}
}


void Laba5()
{
	cout << "������� ���-�� ���������: ";
	int countStores = 1;
	cin >> countStores;
	Store* stores = new Store[countStores];

	for(int i = 0; i < countStores; i++)
	{
		Initialization(stores[i]);
		cout << "------------------------------------------------------------------------\n";
	}
	system("cls");
	ShowStoreInTable(stores, countStores);

	bool isNextCommand = true;
	while(isNextCommand)
	{
		cout << "������� ����� ������� ��� ����������: ";
		int numberOfColumn;
		cin >> numberOfColumn;
		if(numberOfColumn < 0 || numberOfColumn > 4)
		{
			cout << "�� ����� ������ ����� �������\n";
			exit(0);
		}
		SortStoreByNubmerColum(stores, countStores, numberOfColumn);
		system("cls");
		ShowStoreInTable(stores, countStores);
		CommandHandler(isNextCommand, stores, countStores);
	}
}

int main()
{
	system("chcp 1251"); // ��������� � ������� �� ������� ����
	system("cls");
	setlocale(LC_ALL, "Russian");
	//Laba1();
	//Laba2();
	//Laba3();
	//Laba4();
	Laba5();
	return 0;
}