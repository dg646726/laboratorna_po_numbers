#include<iostream>
#include<Windows.h>
#include<math.h>
#include<ctime>
#include<string>
#include<conio.h>
#include<list>
#include<fstream>
#include "Header.h"



using namespace std;
HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);

#define CLEAR system("cls");
#define PAUSE system("pause");



int main() {
	setlocale(LC_CTYPE, "");


	create();

	


	int action;
	do {
		SetConsoleTextAttribute(color, FOREGROUND_RED | FOREGROUND_GREEN);
		cout << "1.Zapovnennya array" << endl;
		cout << "2.Show array" << endl;
		cout << "3.Add number" << endl;
		cout << "4.Delete number" << endl;
		cout << "5.Delete numbers in any position" << endl;
		cout << "6.Max and min" << endl;
		cout << "7.Average" << endl;
		cout << "8.Reverse array" << endl;
		cout << "0.Exit" << endl;
		cout << endl;
		SetConsoleTextAttribute(color, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);

		cout << "Select action:";
		cin >> action;
		cout << endl;
		switch (action)
		{
		case 1:
			random();
			break;
		case 2:
			show_arr();
			PAUSE;
			CLEAR;
			break;
		case 3:
			add_number();
			break;
		case 4:
			del_number();
			break;
		case 5:
			del_numbers_in_any_position();
			break;
		case 6:
			MinAndMax();
			break;
		case 7:
			Average();
			break;
		case 8:
			reverse();
			break;
		case 0:
			cout << "Bye" << endl;
			break;
		default:
			cout << "Error" << endl;
			break;
		}
	} while (action != 0);




	system("pause");
	return 0;
}