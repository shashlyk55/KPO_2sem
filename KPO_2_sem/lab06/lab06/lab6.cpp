#include<iostream>
#include<locale>
#include"D:\KPO_2_sem\lab_6\SE_Lab06L\DIctionary.h"

void main() {
	setlocale(LC_ALL, "ru");
	try {
		// Создание словаря

		Dictionary::Instance d1 = Dictionary::Create("Преподаватели", 7);

		// Элементы словаря
		Dictionary::Entry e1 = { 1, "Гладкий" }, e2 = { 2, "Веялкин" },
			e3 = { 3, "Смелов" }, e4 = { 4, "Урбанович" }, e5 = { 5, "Пацей" },
			e6 = { 6, "Паланик" }, e7 = { 7, "Кафка" };

		Dictionary::AddEntry(d1, e1);		// Доб. элемента словаря
		Dictionary::AddEntry(d1, e2);		// Доб. элемента словаря
		Dictionary::AddEntry(d1, e3);		// Доб. элемента словаря
		Dictionary::AddEntry(d1, e4);		// Доб. элемента словаря
		Dictionary::AddEntry(d1, e6);
		Dictionary::AddEntry(d1, e7);
		Dictionary::AddEntry(d1, e5);


		Dictionary::Entry ex2 = Dictionary::GetEntry(d1, 5);



		Dictionary::DelEntry(d1, 6);

		Dictionary::Entry newentry1 = { 3, "Гурин" };


		Dictionary::UpdEntry(d1, 3, newentry1);

		Dictionary::Print(d1);				// Распечатать элементы словаря

		Dictionary::Instance d2 = Dictionary::Create("Студенты", 7);
		Dictionary::Entry s1 = { 1, "Иванов" }, s2 = { 2, "Петров" }, s3 = { 3, "Сидоров" },
			s4 = { 4, "Печёрин" }, s5 = { 10, "Онегин" }, s6 = { 6, "Безухов" }, s7 = { 12, "Татарский" };

		Dictionary::AddEntry(d2, s1);
		Dictionary::AddEntry(d2, s2);
		Dictionary::AddEntry(d2, s3);
		Dictionary::AddEntry(d2, s4);
		Dictionary::AddEntry(d2, s5);
		Dictionary::AddEntry(d2, s6);
		Dictionary::AddEntry(d2, s7);



		Dictionary::Entry newentry3 = { 3, "Морковин" };
		Dictionary::UpdEntry(d2, 3, newentry3);

		Dictionary::Entry newentry4 = { 3, "Николаев" };
		Dictionary::UpdEntry(d2, 3, newentry4);

		Dictionary::Print(d2);

		Delete(d1);
		Delete(d2);
	}
	catch (const char* e) {
		std::cout << e << std::endl;
	};
	system("pause");

}