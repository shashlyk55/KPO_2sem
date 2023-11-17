#include"stdafx.h"
#include <iostream>
#include <Windows.h>

using namespace std;

int main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int a = 1, menu2();
	const int number = 8;
	do {
		//ГЛАВНОЕ МЕНЮ
		cout << "Выберите вариант выполнения программы:\n1-Информация о введенной дате\n2-Выход их программы\n\n";
		cout << "Ваш вариант выполнения программы: ";
		char n;
		cin >> n;
		cout << "\n";
		//проверка на ввод корректного варианта
		while ('2' < n || n < '1') {
			cout << "Выбран некорректный пункт, вы были возвращены в меню.\n\n";
			system("cls");
			cout << "Введен некорректный вариант выполнения!\nВы были возвращены в меню\n\n";
			cout << "Выберите вариант выполнения программы:\n1-Информация о введенной дате\n2-Выход их программы\n\n";
			cout << "Ваш вариант выполнения программы: ";
			cin >> n;
			cout << "\n";
		}
		system("cls");
		//Варианты выполнения программы

		switch (n) {

			//Информация о введённой Вами дате

		case '1': {
			cout << "Введите дату в формате ДДММГГГГ:\n";
			static char data[number];
			cin >> data;
			//Проверка корректности даты
			for (int i = 0; i < 8; i++) {

				if (data[i] > '9' || data[i] < '0') {
					system("cls");
					cout << "Дата введена некорректно!\nВведите дату в формате ДДММГГГГ:\n";
					cin >> data;
				}
			}

			int month = (data[2] - '0') * 10 + data[3] - '0';//рассчет месяца и дня
			int day = (data[0] - '0') * 10 + data[1] - '0';
			//Доп проверка корректности даты
			int cel = 0;
			int year = (data[4] - '0') * 1000 + (data[5] - '0') * 100 + (data[6] - '0') * 10 + data[7] - '0';
			int CheckingYear(int x, int y);
			while (CheckingYear(year, cel) == 0 && month == 2 && day > 28) {
				system("cls");
				cout << "Введена некорректная дата!\n\nВведите дату в формате ДДММГГГГ:\n";
				cin >> data;

				month = (data[2] - '0') * 10 + data[3] - '0';//извлечение месяца из даты

				day = (data[0] - '0') * 10 + data[1] - '0';//извлечение дня из даты
				year = (data[4] - '0') * 1000 + (data[5] - '0') * 100 + (data[6] - '0') * 10 + data[7] - '0';
			}
			while (data[0] > '3' || data[0] < '0' || month > 12 || month < 1 || day < 1 || day > 31) {

				system("cls");
				cout << "Дата введена некорректно!\n\nВведите дату в формате ДДММГГГГ:\n";
				cin >> data;
				//извлечение месяца из даты
				month = (data[2] - '0') * 10 + data[3] - '0';
				//извлечение дня из даты
				day = (data[0] - '0') * 10 + data[1] - '0';
				year = (data[4] - '0') * 1000 + (data[5] - '0') * 100 + (data[6] - '0') * 10 + data[7] - '0';

			}
			//извлечение года из даты
			year = (data[4] - '0') * 1000 + (data[5] - '0') * 100 + (data[6] - '0') * 10 + data[7] - '0';
			system("cls");
			//Ввод даты рождения-
			cout << "Введите дату рождения в формате ДДММГГГГ:\n";
			static char birthDay[number];
			cin >> birthDay;
			//Проверка корректности даты
			for (int i = 0; i < 8; i++) {

				if (birthDay[i] > '9' || birthDay[i] < '0') {
					system("cls");
					cout << "Введена некорректная дата!\n\nВведите дату рождения в формате ДДММГГГГ:\n";
					cin >> birthDay;
				}
			}
			//извлечение месяца из даты
			int happyMonth = (birthDay[2] - '0') * 10 + birthDay[3] - '0';
			//извлечение дня из даты
			int happyDay = (birthDay[0] - '0') * 10 + birthDay[1] - '0';
			//Доп проверка корректности даты
			int CheckingYear(int x, int y);
			int happyYear = (birthDay[4] - '0') * 1000 + (birthDay[5] - '0') * 100 + (birthDay[6] - '0') * 10 + birthDay[7] - '0';
			while (CheckingYear(happyYear, cel) == 0 && happyMonth == 2 && happyDay > 28) {
				system("cls");
				cout << "Введена некорректная дата!\n\nВведите дату в формате ДДММГГГГ:\n";
				cin >> data;
				//извлечение месяца из даты
				month = (data[2] - '0') * 10 + data[3] - '0';
				//извлечение дня из даты
				day = (data[0] - '0') * 10 + data[1] - '0';
				happyYear = (birthDay[4] - '0') * 1000 + (birthDay[5] - '0') * 100 + (birthDay[6] - '0') * 10 + birthDay[7] - '0';
			}
			while (birthDay[0] > '3' || birthDay[1] < '0' || happyMonth > 12 || happyMonth < 1 || happyDay < 1 || happyDay > 31) {
				system("cls");

				cin >> birthDay;
				//извлечение месяца из даты
				happyMonth = (birthDay[2] - '0') * 10 + birthDay[3] - '0';
				//извлечение дня из даты
				happyDay = (birthDay[0] - '0') * 10 + birthDay[1] - '0';
				happyYear = (birthDay[4] - '0') * 1000 + (birthDay[5] - '0') * 100 + (birthDay[6] - '0') * 10 + birthDay[7] - '0';
			}
			//извлечение года из даты
			happyYear = (birthDay[4] - '0') * 1000 + (birthDay[5] - '0') * 100 + (birthDay[6] - '0') * 10 + birthDay[7] - '0';



			//Вывод информации о дате
			system("cls");
			cout << "Введенная дата: " << day << "." << month << "." << year << "\n\n";
			cout << "Введенная дата рождения: " << happyDay << "." << happyMonth << "." << happyYear << "\n\n";
			cout << "Характеристика введенной даты: \n\n";
			cel = 0;
			//Проверка на высокостность
			int CheckingYear(int x, int y);
			if (CheckingYear(year, cel) == 1) {
				cout << "Данный год является высокостным\n\n";
			}
			else {
				cout << "Данный год не является высокостным\n\n";
			}
			//Вычисление порядкового номера дня в году
			int quantity(int x, int y, int z);
			cout << "Введённый вами день является " << quantity(month, day, CheckingYear(year, cel)) << " в году\n\n";

			//Вычисление количества дней до Вашего ближайшего дня рождения

			if (quantity(month, day, CheckingYear(year, cel)) < quantity(happyMonth, happyDay, CheckingYear(year, cel))) {

				int daycout = quantity(month, day, CheckingYear(year, cel));
				int dayhappys = quantity(happyMonth, happyDay, CheckingYear(year, cel));
				int colvoday = dayhappys - daycout;
				cout << "До ближайшего вашего дня рождения " << colvoday << " дня(ей)\n\n";
			}
			else if (quantity(month, day, CheckingYear(year, cel)) == quantity(happyMonth, happyDay, CheckingYear(year, cel))) {
				cout << "Поздравляю, у Вас сегодня день рождения\n";
			}
			else {

				int daycout = quantity(month, day, CheckingYear(year, cel));
				int jatgod = year + 1;
				int dayhappys = quantity(happyMonth, happyDay, CheckingYear(jatgod, cel));
				int daygod = 365 + CheckingYear(year, cel);
				int daystar = daygod - daycout;
				int colvoday = dayhappys + daystar;
				cout << "До ближайшего вашего дня рождения " << colvoday << " дня(ей)\n\n";
			}

			cout << "\n\n";
			system("pause");
			system("cls");
			break;
		}

		case '2': {
			system("cls");
			cout << "\n\nВы вышли из программы.\n\n";

			return 0;
		}
		}
	} while (a != 0);
	return 0;
}