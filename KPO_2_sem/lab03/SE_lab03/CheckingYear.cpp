#include<iostream>

//Функция проверки года на высокостность
int CheckingYear(int x, int y) {
	using namespace std;
	if (x % 4 == 0 && x % 400 != 100 && x % 400 != 200 && x % 400 != 300) {
		y = 1;
	}
	else {
		y = 0;
	}
	return y;
}