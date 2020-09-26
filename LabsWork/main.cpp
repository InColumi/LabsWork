#include <iostream>
#include <stdio.h>
#include <string>
#include <ctime>

using namespace std;

struct Store
{
	public:
	string Name;
	int CountArtBooks;
	int CountSportBooks;
	int CountEducationBooks;
	int CountEntertainingBooks;

	void ShowNames()
	{
		cout << "Название магазина" << "\t" <<
			"Художественые" << "\t" <<
			"Спортивные" << "\t" <<
			"Учебные " << "\t" <<
			"Развлекательные\n";
	}

	void ShowValueInfo()
	{
		cout << '|'  <<
			Name << "\t\t" <<
			CountArtBooks << "\t\t" <<
			CountSportBooks << "\t\t" <<
			CountEducationBooks << "\t\t" <<
			CountEntertainingBooks << "\t\n";
		
		/*cout << '|' <<
			Name << setw(25) << left <<
			CountArtBooks << setw(22) <<
			CountSportBooks << setw(22) <<
			CountEducationBooks << setw(15) <<
			CountEntertainingBooks << setw(15) << "|\n";*/
	}
};

Store* GenerateStores(int countSores)
{
	Store* newStores = new Store[countSores];
	for(int i = 0; i < countSores; i++)
	{
		newStores[i].Name = "name123213123";
		newStores[i].CountArtBooks = 0 + rand() % 11;
		newStores[i].CountSportBooks = 0 + rand() % 11;
		newStores[i].CountEducationBooks = 0 + rand() % 11;
		newStores[i].CountEntertainingBooks = 0 + rand() % 11;
	}
	return newStores;
}
void Laba1()
{
	srand(time(0));
	Store store;
	/*cout << "Введите название книжного магазина: ";
	cin >> store.Name;
	cout << "Введите кол-во проданных художественных книг: ";
	cin >> store.CountArtBooks;
	cout << "Введите кол-во проданных спортивных книг: ";
	cin >> store.CountSportBooks;
	cout << "Введите кол-во проданных учебных книг: ";
	cin >> store.CountEducationBooks;
	cout << "Введите кол-во проданных развлекательных книг: ";
	cin >> store.CountEntertainingBooks;*/
	int countStores = 10;
	Store* stores = GenerateStores(countStores);
	stores[0].ShowNames();
	for(size_t i = 0; i < countStores; i++)
	{
		stores[i].ShowValueInfo();
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	Laba1();
	return 0;
}