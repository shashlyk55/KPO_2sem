#include <iostream>
#include <Windows.h>
#define number 8
using namespace std;

int main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int a = 1, menu1(), menu2();

	do {
		//������� ����
		menu1();
		char n;
		cin >> n;
		cout << "\n";
		//�������� �� ���� ����������� ��������
		while ('2' < n || n < '1') {
			cout << "������ ������������ �����, �� ���� ���������� � ����.\n\n";
			menu2();
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
			//������� ������ � ���
			int month = (data[2] - '0') * 10 + data[3] - '0';
			int day = (data[0] - '0') * 10 + data[1] - '0';
			//��� �������� ������������ ����
			int cel = 0;
			int year = (data[4] - '0') * 1000 + (data[5] - '0') * 100 + (data[6] - '0') * 10 + data[7] - '0';
			int CheckingYear(int x, int y);
			while (CheckingYear(year, cel) == 0 && month == 2 && day > 28) {
				system("cls");
				cout << "������� ������������ ����!\n\n������� ���� � ������� ��������:\n";
				cin >> data;
				//���������� ������ �� ����
				month = (data[2] - '0') * 10 + data[3] - '0';
				//���������� ��� �� ����
				day = (data[0] - '0') * 10 + data[1] - '0';
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

		//����� �� ���������

		case '2': {
			system("cls");
			cout << "\n\n�� ����� �� ���������.\n\n";

			return 0;
		}
		}
	} while (a != 0);
	return 0;
}


//������� ����
int menu1() {
	using namespace std;
	cout << "�������� ������� ���������� ���������:\n1-���������� � ��������� ����\n2-����� �� ���������\n\n";
	cout << "��� ������� ���������� ���������: ";
	return 0;
};

//����������� � ����
int menu2() {
	int menu1();
	using namespace std;
	system("cls");
	cout << "������ ������������ ������� ����������!\n�� ���� ���������� � ����\n\n";
	
	menu1();
	return 0;
};

//������� �������� ���� �� �������������
int CheckingYear(int x, int y) {
	using namespace std;
	if (x % 4 == 0 && x % 400 != 100 && x % 400 != 200 && x % 400 != 300){
		y = 1;
	}
	else {
		y = 0;
	}
	return y;
}

//������� ����������� ���������� ����� ���������� ���
int quantity(int x, int y, int z) {
	using namespace std;
	int Mounthes[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int sumday = 0;
	if (z == 1) {
		Mounthes[1] = 29;
	}
	for (int i = 0; i < x - 1; i++) {
		sumday = sumday + Mounthes[i];
	}
	sumday = sumday + y;

	return sumday;
}