#include <iostream>
#include <stdio.h>
#include <stdlib.h> // для перехода на русский язык
#include <ctime>
#include <string>
#include <windows.h>
using namespace std;

struct Store
{
	public:
	char Name[17];
	int CountArtBooks;
	int CountSportBooks;
	int CountEducationBooks;
	int CountEntertainingBooks;

	void ShowNames()
	{
		printf("%-0.17s\t%-0.17s\t%-0.17s\t%-0.17s\t%-0.17s\n", "Название магазина", "Художественые", "Спортивные", "Обучающие", "Развлекательные");
	}

	void ShowValueInfo()
	{
		printf("%-17s\t%-13d\t%-10d\t%-9d\t%-17d\n", Name, CountArtBooks, CountSportBooks, CountEducationBooks, CountEntertainingBooks);
	}

	void InputFromConsole()
	{
		cout << "Введите название книжного магазина: ";
		cin >> Name;
		cout << "Введите кол-во проданных художественных книг: ";
		cin >> CountArtBooks;
		cout << "Введите кол-во проданных спортивных книг: ";
		cin >> CountSportBooks;
		cout << "Введите кол-во проданных учебных книг: ";
		cin >> CountEducationBooks;
		cout << "Введите кол-во проданных развлекательных книг: ";
		cin >> CountEntertainingBooks;
	}

	void SetValue(int artBooks, int sportBooks, int educationBooks, int entertainingBooks)
	{
		CountArtBooks = artBooks;
		CountSportBooks = sportBooks;
		CountEducationBooks = educationBooks;
		CountEntertainingBooks = entertainingBooks;
	}
};

Store* GenerateStores(int countSores)
{
	char* names = *new char[6][12]{ 
		"Свобода", 
		"Надежда", 
		"Улыбка", 
		"Свобода",
		"Радуга", 
		"Закат" };
	int randMaxNumber = 10;
	Store* newStores = new Store[countSores];
	for(int i = 0; i < countSores; i++)
	{
		cout << "Имя: ";
		cin >> newStores[i].Name;
		newStores[i].CountArtBooks = 0 + rand() % randMaxNumber;
		newStores[i].CountSportBooks = 0 + rand() % randMaxNumber;
		newStores[i].CountEducationBooks = 0 + rand() % randMaxNumber;
		newStores[i].CountEntertainingBooks = 0 + rand() % randMaxNumber;
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

void Laba1()
{
	Store store;
	store.InputFromConsole();
	store.ShowNames();
	store.ShowValueInfo();	
}

int main()
{
	system("chcp 1251"); // переходим в консоли на русский язык
	system("cls");
	setlocale(LC_ALL, "Russian");
	Laba1();
	//Generator(1);
	return 0;
}