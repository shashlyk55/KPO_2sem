#include<iostream>
#include<locale>
using namespace std;

typedef unsigned char day;
typedef unsigned char month;
typedef unsigned short year;

struct Date {
	day dd;
	month mm;
	year yyyy;
};

bool operator> (Date first, Date second) {
	if (first.yyyy > second.yyyy) return true;
	if (first.yyyy == second.yyyy) {
		if (first.mm > second.mm) return true;
		if(first.mm==second.mm) {
			if (first.dd > second.dd)return true;
		}
	}
	else return false;
}

bool operator< (Date first, Date second) {
	if (first.yyyy < second.yyyy) return true;
	if (first.yyyy == second.yyyy) {
		if (first.mm < second.mm) return true;
		if (first.mm == second.mm) {
			if (first.dd < second.dd)return true;
		}
	}
	else return false;
}

bool operator== (Date first, Date second) {
	if (first.yyyy == second.yyyy) {
		if (first.mm == second.mm) {
			if (first.dd == second.dd) return true;
		}
	}
	else return false;
}

typedef unsigned short sec;
typedef unsigned short minutes;
typedef unsigned short hour;

struct Time {
	sec s;
	minutes m;
	hour h;
};

//сравнение структур типа Time

bool operator> (Time first, Time second) {
	if (first.h > second.h) return true;
	if (first.h == second.h) {
		if (first.m > second.m) return true;
		if (first.m == second.m) {
			if (first.s > second.s)return true;
		}
	}
	else return false;
}

bool operator< (Time first, Time second) {
	if (first.h < second.h) return true;
	if (first.h == second.h) {
		if (first.m < second.m) return true;
		if (first.m == second.m) {
			if (first.s < second.s)return true;
		}
	}
	else return false;
}

bool operator== (Time first, Time second) {
	if (first.h == second.h) {
		if (first.m == second.m) {
			if (first.s == second.s) return true;
		}
	}
	else return false;
}

//сумма структур
Time operator+(Time a, Time b) {
	Time sum = { 0,0,0 };
//сложение секунд
	sum.s = a.s + b.s;
	if (sum.s >= 60) {
		sum.m += sum.s / 60;
		sum.s = (a.s + b.s) % 60;
	}
//сложение минут
	sum.m = a.m + b.m;
	if ((a.m + b.m) >= 60) {
		sum.h += sum.m / 60;
		sum.m = (a.m + b.m) % 60;
	}

//сложение часов
	sum.h = a.h + b.h;

	return sum;
}

//увеличение структуры Time на заднное количество секунд
Time operator+=(Time &a,const int b) {
	a.s = a.s + b;
	if (a.s >= 60) {
		a.m+=(a.s/60);
		a.s = a.s % 60;
		
	}
	//a.m+=b;
	if (a.m >= 60) {
		a.h+=(a.m/60);
		a.m = a.m % 60;
		
	}
	//a.h+=b;
	return a;
}

int main() {
	setlocale(LC_ALL, "ru");

	Date date1 = { 7,1,1999 };
	Date date2 = { 7,2,1930 };
	Date date3 = { 7,1,1999 };

	if (date1 < date2)
		cout << "true\n";
	else
		cout << "false\n";

	if (date1 > date2)
		cout << "true\n";
	else
		cout << "false\n";

	if (date1 == date2)
		cout << "true\n";
	else
		cout << "false\n";

	if (date1 == date3)
		cout << "true\n\n";
	else
		cout << "false\n\n";

	Time t1 = { 20,40,5 };
	Time t2 = { 50,20,2 };
	Time t3 = { 15,30,4 };

	if (t1 < t2)
		cout << "true\n";
	else
		cout << "false\n";

	if (t1 > t2)
		cout << "true\n";
	else
		cout << "false\n";

	if (t1 == t2)
		cout << "true\n";
	else
		cout << "false\n";

	if (t1 == t3)
		cout << "true\n\n";
	else
		cout << "false\n\n";

	Time summa;
	summa = t1 + t2;
	printf("%d сек %d мин %d ч\n", summa.s, summa.m, summa.h);
	summa = t1 + t3;
	printf("%d сек %d мин %d ч\n", summa.s, summa.m, summa.h);
	summa = t2 + t3;
	printf("%d сек %d мин %d ч\n\n", summa.s, summa.m, summa.h);

	t1 += 7;
	printf("%d сек %d мин %d ч\n", t1.s, t1.m, t1.h);
	t2 += 15;
	printf("%d сек %d мин %d ч\n", t2.s, t2.m, t2.h);
	t3 += 1845;
	printf("%d сек %d мин %d ч\n", t3.s, t3.m, t3.h);

	return 0;
}