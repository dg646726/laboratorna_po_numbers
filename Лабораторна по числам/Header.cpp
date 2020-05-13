#include "Header.h"
#include<iostream>
#include<Windows.h>
#include<math.h>
#include<ctime>
#include<string>
#include<conio.h>
#include<list>
#include<fstream>

using namespace std;
HANDLE colorHeader = GetStdHandle(STD_OUTPUT_HANDLE);

#define CLEAR system("cls")
#define PAUSE system("pause")
#define ENDL cout<<endl


const string fileName = "FileWithNumbers.txt";

int* numbers;
int* arrayNumbers;

int sizeArray = 0;

void create()
{
		SetConsoleTextAttribute(colorHeader, FOREGROUND_RED | FOREGROUND_GREEN);
		cout << "Enter size array:";
		SetConsoleTextAttribute(colorHeader, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
		cin >> sizeArray;

		numbers = new int[sizeArray];
}

void random()
{
	srand(time(0));
	CLEAR;
	for (int i = 0; i < sizeArray; i++)
	{
		numbers[i] = rand() % 10;
	}

}

void show_arr()
{
	CLEAR;
	for (int i = 0; i < sizeArray; i++) {

		cout << numbers[i] << " ";
		if (i == 9 || i == 19 || i == 29 || i == 39 || i == 49 || i == 59 || i == 69 || i == 79 || i == 89 || i == 99) {
			ENDL;
		}
	}
	ENDL;
	
}

void add_number()
{
	CLEAR;
	int newNumber;
	SetConsoleTextAttribute(colorHeader, FOREGROUND_RED | FOREGROUND_GREEN);
	cout << "Enter new number:";
	SetConsoleTextAttribute(colorHeader, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
	cin >> newNumber;

	int* temp = new int[sizeArray + 1];
	for (int i = 0; i < sizeArray; i++)
	{
		temp[i] = numbers[i];
	}
	temp[sizeArray] = newNumber;
	sizeArray++;
	numbers = new int[sizeArray];
	for (int i = 0; i < sizeArray; i++)
	{
		numbers[i] = temp[i];
	}
	delete[]temp;

	ENDL;
	PAUSE;
	CLEAR;
}

void del_number()
{
	show_arr();

	int Number;
	int j = 0;
	SetConsoleTextAttribute(colorHeader, FOREGROUND_RED | FOREGROUND_GREEN);
	cout << "Enter the sequence number of the number you want to delete:";
	SetConsoleTextAttribute(colorHeader, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
	cin >> Number;

	int* temp = new int[sizeArray - 1];
	for (int i = 0; i < sizeArray; i++)
	{
		if (i != Number-1) {
			temp[j] = numbers[i];
			j++;
		}
	}
	sizeArray--;
	numbers = new int[sizeArray];
	for (int i = 0; i < sizeArray; i++)
	{
		numbers[i] = temp[i];
	}
	delete[]temp;

}

void add_number_in_any_position()
{
	show_arr();

	int newNumber;
	int Number;

	SetConsoleTextAttribute(colorHeader, FOREGROUND_RED | FOREGROUND_GREEN);
	cout << "Enter new number:";
	SetConsoleTextAttribute(colorHeader, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
	cin >> newNumber;

	SetConsoleTextAttribute(colorHeader, FOREGROUND_RED | FOREGROUND_GREEN);
	cout << "Enter the number where you want to put the number:";
	SetConsoleTextAttribute(colorHeader, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
	cin >> Number;

	int* temp = new int[sizeArray + 1];
	for (int i = 0; i < sizeArray+1; i++)
	{
		if (i == Number-1) {
			temp[i] = newNumber;
		}
		else {
			temp[i] = numbers[i];
		}
	}
	sizeArray++;
	numbers = new int[sizeArray];
	for (int i = 0; i < sizeArray; i++)
	{
		numbers[i] = temp[i];
	}
	delete[]temp;
}

void add_array_numbers_in_any_position()
{
	show_arr();

	int sizeArrayNumbers;
	int Number;
	int k=0;
	SetConsoleTextAttribute(colorHeader, FOREGROUND_RED | FOREGROUND_GREEN);
	cout << "Enter how many numbers you want to add:";
	SetConsoleTextAttribute(colorHeader, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
	cin >> sizeArrayNumbers;
	arrayNumbers = new int[sizeArrayNumbers];

	SetConsoleTextAttribute(colorHeader, FOREGROUND_RED | FOREGROUND_GREEN);
	cout << "Enter the number where you want to put the numbers:";
	SetConsoleTextAttribute(colorHeader, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
	cin >> Number;

	int* temp = new int[sizeArray + sizeArrayNumbers];
	for (int i = 0; i < sizeArray + sizeArrayNumbers; i++)
	{
		if (i == Number - 1&&k<sizeArrayNumbers) {
			temp[i] = arrayNumbers[k];
			k++;
			Number++;
		}
		else {
			temp[i] = numbers[i];
		}
	}
	sizeArray+=sizeArrayNumbers;
	numbers = new int[sizeArray];
	for (int i = 0; i < sizeArray; i++)
	{
		numbers[i] = temp[i];
	}
	delete[]temp;
}

void del_numbers_in_any_position()
{
	show_arr();

	int sizeArrayNumbers;
	int Number;
	int k = 0;
	int j = 0;
	SetConsoleTextAttribute(colorHeader, FOREGROUND_RED | FOREGROUND_GREEN);
	cout << "Enter how many numbers you want to delete:";
	SetConsoleTextAttribute(colorHeader, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
	cin >> sizeArrayNumbers;

	SetConsoleTextAttribute(colorHeader, FOREGROUND_RED | FOREGROUND_GREEN);
	cout << "Enter the number where you want to put the numbers:";
	SetConsoleTextAttribute(colorHeader, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
	cin >> Number;
	if (sizeArray < sizeArrayNumbers||sizeArray<sizeArrayNumbers+Number-1) {
		cout << "Error" << endl;
	}
	else {
		int* temp = new int[sizeArray - sizeArrayNumbers];
		for (int i = 0; i < sizeArray; i++)
		{
			if (i == Number - 1 && k < sizeArrayNumbers) {
				Number++;
				k++;
			}
			else {
				temp[j] = numbers[i];
				j++;
			}
		}
		sizeArray -= sizeArrayNumbers;
		numbers = new int[sizeArray];
		for (int i = 0; i < sizeArray; i++)
		{
			numbers[i] = temp[i];
		}
		delete[]temp;
	}
}

void MinAndMax()
{
	
	int min;
	int max;

	for (int i = 0; i < sizeArray; i++)
	{
		if (i == 0) {
			min = numbers[i];
			max = numbers[i];
		}
		if (min > numbers[i]) {
			min = numbers[i];
		}
		if (max < numbers[i]) {
			max = numbers[i];
		}
		
	}
	cout << "Max:" << max << endl;
	cout << "Min:" << min << endl;
	PAUSE;
	CLEAR;
}

void Average()
{
	
	show_arr();
	double average;
	int suma=0;
	for (int i = 0; i < sizeArray; i++)
	{
		suma += numbers[i];
	}
	average = (double)(suma)/sizeArray;
	cout << "Average:" << average << endl;
	
	PAUSE;
	CLEAR;
}

void reverse()
{
	
	show_arr();
	ENDL;
	for (int i = sizeArray-1; i > 0; i--) {

		cout << numbers[i] << " ";
		
	}
	ENDL;
}

