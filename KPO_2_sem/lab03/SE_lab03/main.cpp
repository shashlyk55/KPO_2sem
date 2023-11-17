#include <iostream>
#include <windows.h>
#include<fstream>
#include<string>
#include<fstream>

using namespace std;

string months[12] = { "������","�������","����","������","����","����","����","��������","�������","������","�������" };
void prazdnik(int x);
int main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "ru");
	int a = 1, menu2();
	const int number = 8;
	do {
		//������� ����
		cout << "�������� ������� ���������� ���������:\n1-���������� � ��������� ����\n2-�������� �� ����������� ������ ��� � ����\n3-����� �� ���������\n\n";
		cout << "��� ������� ���������� ���������: ";
		char n;
		cin >> n;
		cout << "\n";
		//�������� �� ���� ����������� ��������
		while ('2' < n || n < '1') {
			cout << "������ ������������ �����, �� ���� ���������� � ����.\n\n";
			system("cls");
			cout << "������ ������������ ������� ����������!\n�� ���� ���������� � ����\n\n";
			cout << "�������� ������� ���������� ���������:\n1-���������� � ��������� ����\n2-�������� �� ����������� ������ ��� � ����\n3-����� �� ���������\n\n";
			cout << "��� ������� ���������� ���������: ";
			cin >> n;
			cout << "\n";
		}
		system("cls");
		//�������� ���������� ���������

		switch (n) {

			//���������� � �������� ���� ����

		case '1': {
			cout << "������� ���� � ������� ��������:\n";
			static char data[number];
			cin >> data;
			//�������� ������������ ����
			for (int i = 0; i < 8; i++) {

				if (data[i] > '9' || data[i] < '0') {
					system("cls");
					cout << "���� ������� �����������!\n������� ���� � ������� ��������:\n";
					cin >> data;
				}
			}

			int month = (data[2] - '0') * 10 + data[3] - '0';//������� ������ � ���
			int day = (data[0] - '0') * 10 + data[1] - '0';
			//��� �������� ������������ ����
			int cel = 0;
			int year = (data[4] - '0') * 1000 + (data[5] - '0') * 100 + (data[6] - '0') * 10 + data[7] - '0';
			int CheckingYear(int x, int y);
			while (CheckingYear(year, cel) == 0 && month == 2 && day > 28) {
				system("cls");
				cout << "������� ������������ ����!\n\n������� ���� � ������� ��������:\n";
				cin >> data;

				month = (data[2] - '0') * 10 + data[3] - '0';//���������� ������ �� ����

				day = (data[0] - '0') * 10 + data[1] - '0';//���������� ��� �� ����
				year = (data[4] - '0') * 1000 + (data[5] - '0') * 100 + (data[6] - '0') * 10 + data[7] - '0';
			}
			while (data[0] > '3' || data[0] < '0' || month > 12 || month < 1 || day < 1 || day > 31) {

				system("cls");
				cout << "���� ������� �����������!\n\n������� ���� � ������� ��������:\n";
				cin >> data;
				//���������� ������ �� ����
				month = (data[2] - '0') * 10 + data[3] - '0';
				//���������� ��� �� ����
				day = (data[0] - '0') * 10 + data[1] - '0';
				year = (data[4] - '0') * 1000 + (data[5] - '0') * 100 + (data[6] - '0') * 10 + data[7] - '0';

			}
			//���������� ���� �� ����
			year = (data[4] - '0') * 1000 + (data[5] - '0') * 100 + (data[6] - '0') * 10 + data[7] - '0';
			system("cls");
			//���� ���� ��������-
			cout << "������� ���� �������� � ������� ��������:\n";
			static char birthDay[number];
			cin >> birthDay;
			//�������� ������������ ����
			for (int i = 0; i < 8; i++) {

				if (birthDay[i] > '9' || birthDay[i] < '0') {
					system("cls");
					cout << "������� ������������ ����!\n\n������� ���� �������� � ������� ��������:\n";
					cin >> birthDay;
				}
			}
			//���������� ������ �� ����
			int happyMonth = (birthDay[2] - '0') * 10 + birthDay[3] - '0';
			//���������� ��� �� ����
			int happyDay = (birthDay[0] - '0') * 10 + birthDay[1] - '0';
			//��� �������� ������������ ����
			int CheckingYear(int x, int y);
			int happyYear = (birthDay[4] - '0') * 1000 + (birthDay[5] - '0') * 100 + (birthDay[6] - '0') * 10 + birthDay[7] - '0';
			while (CheckingYear(happyYear, cel) == 0 && happyMonth == 2 && happyDay > 28) {
				system("cls");
				cout << "������� ������������ ����!\n\n������� ���� � ������� ��������:\n";
				cin >> data;
				//���������� ������ �� ����
				month = (data[2] - '0') * 10 + data[3] - '0';
				//���������� ��� �� ����
				day = (data[0] - '0') * 10 + data[1] - '0';
				happyYear = (birthDay[4] - '0') * 1000 + (birthDay[5] - '0') * 100 + (birthDay[6] - '0') * 10 + birthDay[7] - '0';
			}
			while (birthDay[0] > '3' || birthDay[1] < '0' || happyMonth > 12 || happyMonth < 1 || happyDay < 1 || happyDay > 31) {
				system("cls");

				cin >> birthDay;
				//���������� ������ �� ����
				happyMonth = (birthDay[2] - '0') * 10 + birthDay[3] - '0';
				//���������� ��� �� ����
				happyDay = (birthDay[0] - '0') * 10 + birthDay[1] - '0';
				happyYear = (birthDay[4] - '0') * 1000 + (birthDay[5] - '0') * 100 + (birthDay[6] - '0') * 10 + birthDay[7] - '0';
			}
			//���������� ���� �� ����
			happyYear = (birthDay[4] - '0') * 1000 + (birthDay[5] - '0') * 100 + (birthDay[6] - '0') * 10 + birthDay[7] - '0';

			//����� ���������� � ����
			system("cls");
			cout << "��������� ����: " << day << "." << month << "." << year << "\n\n";
			cout << "��������� �����: " << months[month - 1] << "\n\n";
			cout << "��������� ���� ��������: " << happyDay << "." << happyMonth << "." << happyYear << "\n\n";
			cout << "�������������� ��������� ����: \n\n";
			cel = 0;
			//�������� �� �������������
			int CheckingYear(int x, int y);
			if (CheckingYear(year, cel) == 1) {
				cout << "������ ��� �������� �����������\n\n";
			}
			else {
				cout << "������ ��� �� �������� �����������\n\n";
			}
			//���������� ����������� ������ ��� � ����
			int quantity(int x, int y, int z);
			cout << "�������� ���� ���� �������� " << quantity(month, day, CheckingYear(year, cel)) << " � ����\n\n";
			//���������� ���������� ���� �� ������ ���������� ��� ��������

			if (quantity(month, day, CheckingYear(year, cel)) < quantity(happyMonth, happyDay, CheckingYear(year, cel))) {

				int daycout = quantity(month, day, CheckingYear(year, cel));
				int dayhappys = quantity(happyMonth, happyDay, CheckingYear(year, cel));
				int colvoday = dayhappys - daycout;
				cout << "�� ���������� ������ ��� �������� " << colvoday << " ���(��)\n\n";
			}
			else if (quantity(month, day, CheckingYear(year, cel)) == quantity(happyMonth, happyDay, CheckingYear(year, cel))) {
				cout << "����������, � ��� ������� ���� ��������\n";
			}
			else {

				int daycout = quantity(month, day, CheckingYear(year, cel));
				int jatgod = year + 1;
				int dayhappys = quantity(happyMonth, happyDay, CheckingYear(jatgod, cel));
				int daygod = 365 + CheckingYear(year, cel);
				int daystar = daygod - daycout;
				int colvoday = dayhappys + daystar;
				cout << "�� ���������� ������ ��� �������� " << colvoday << " ���(��)\n\n";
			}
			cout << "\n\n";
			system("pause");
			system("cls");
			break;
		}

		case '2': {
			int num;
			
			cout << "\n������� ����� ��� � ����(1-365): ";
			cin >> num;
			if (num < 1 || num>365) {
				cout << "������\n";
				cin >> num;
			}
			prazdnik(num);
			break;
		}

		case '3': {
			system("cls");
			cout << "\n\n�� ����� �� ���������.\n\n";
			exit(1);
			return 0;
		}
		}
	} while (true);
	return 0;
}

void prazdnik(int x) {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "ru");
	string file = "prazdniki.txt";
	ifstream fin;
	fin.open(file);
	string str;
	for (int i = 0; i < x; i++) {
		getline(fin, str);
	}
	cout << str << endl;
	fin.close();
}



