#include <iostream>
#include <locale>
#include "Dictionary.h"
#include "stdafx.h"

#if (defined TEST_CREATE_01 && defined TEST_CREATE_02) || (defined TEST_CREATE_01 && defined TEST_ADDENTRY_03) || (defined TEST_CREATE_01 && defined TEST_ADDENTRY_04) || (defined TEST_CREATE_01 && defined TEST_GETENTRY_05) || (defined TEST_CREATE_01 && defined TEST_DELENTRY_06) || (defined TEST_CREATE_01 && defined TEST_UPDENTRY_07) || (defined TEST_CREATE_01 && defined TEST_UPDENTRY_08) || (defined TEST_CREATE_01 && defined TEST_DICTIONARY) || \
(defined TEST_CREATE_02 && defined TEST_ADDENTRY_03) || (defined TEST_CREATE_02 && defined TEST_ADDENTRY_04) || (defined TEST_CREATE_02 && defined TEST_GETENTRY_05) || (defined TEST_CREATE_02 && defined TEST_DELENTRY_06) || (defined TEST_CREATE_02 && defined TEST_UPDENTRY_07) || (defined TEST_CREATE_02 && defined TEST_UPDENTRY_08) || (defined TEST_CREATE_02 && defined TEST_DICTIONARY) || \
(defined TEST_ADDENTRY_03 && defined TEST_ADDENTRY_04) || (defined TEST_ADDENTRY_03 && defined TEST_GETENTRY_05) || (defined TEST_ADDENTRY_03 && defined TEST_DELENTRY_06) || (defined TEST_ADDENTRY_03 && defined TEST_UPDENTRY_07) || (defined TEST_ADDENTRY_03 && defined TEST_UPDENTRY_08) || (defined TEST_ADDENTRY_03 && defined TEST_DICTIONARY) || \
(defined TEST_ADDENTRY_04 && defined TEST_GETENTRY_05) || (defined TEST_ADDENTRY_04 && defined TEST_DELENTRY_06) || (defined TEST_ADDENTRY_04 && defined TEST_UPDENTRY_07) || (defined TEST_ADDENTRY_04 && defined TEST_UPDENTRY_08) || (defined TEST_ADDENTRY_04 && defined TEST_DICTIONARY) || \
(defined TEST_GETENTRY_05 && defined TEST_DELENTRY_06) || (defined TEST_GETENTRY_05 && defined TEST_UPDENTRY_07) || (defined TEST_GETENTRY_05 && defined TEST_UPDENTRY_08) || (defined TEST_GETENTRY_05 && defined TEST_DICTIONARY) || \
(defined TEST_DELENTRY_06 && defined TEST_UPDENTRY_07) || (defined TEST_DELENTRY_06 && defined TEST_UPDENTRY_08) || (defined TEST_DELENTRY_06 && defined TEST_DICTIONARY) || \
(defined TEST_UPDENTRY_07 && defined TEST_UPDENTRY_08) || (defined TEST_UPDENTRY_07 && defined TEST_DICTIONARY) || \
(defined TEST_UPDENTRY_08 && defined TEST_DICTIONARY)
#error Определено слишком много макроссов
#endif

void main() {
	setlocale(LC_ALL, "ru");
	try {
		// Создание словаря
		#ifdef TEST_CREATE_01
			Dictionary::Instance d1 = Dictionary::Create("Преподаватели и фамилия имя отчество с номером телефона", 5);
		#elif defined TEST_CREATE_02
			Dictionary::Instance d1 = Dictionary::Create("Преподаватели", 110);
		#elif !defined TEST_DICTIONARY
			Dictionary::Instance d1 = Dictionary::Create("Преподаватели", 5);
		#endif

		#if defined TEST_DICTIONARY
			Dictionary::Instance d1 = Dictionary::Create("Преподаватели", 7);
		#endif 

		// Элементы словаря
		Dictionary::Entry e1 = { 1, "Гладкий" }, e2 = { 2, "Веялкин" },
				e3 = { 3, "Смелов" }, e4 = { 4, "Урбанович" }, e5 = { 2, "Пацей" },
				e6 = { 5, "Паланик" }, e7 = { 6, "Кафка" }, e8 = { 7, "Фёдоров" };

		Dictionary::AddEntry(d1, e1);		// Доб. элемента словаря
		Dictionary::AddEntry(d1, e2);		// Доб. элемента словаря
		Dictionary::AddEntry(d1, e3);		// Доб. элемента словаря
		Dictionary::AddEntry(d1, e4);		// Доб. элемента словаря
		#if defined TEST_DICTIONARY
			Dictionary::AddEntry(d1, e6);
			Dictionary::AddEntry(d1, e7);
			Dictionary::AddEntry(d1, e8);
		#endif 
		#ifdef TEST_ADDENTRY_03
			e6 = { 19, "Пелевин" }, e7 = { 84, "Оруэлл" };
			Dictionary::AddEntry(d1, e6);
			Dictionary::AddEntry(d1, e7);
		#elif defined TEST_ADDENTRY_04
			Dictionary::AddEntry(d1, e5);
		#endif

		// Найти эл. словаря по идентификатору
		#ifdef TEST_GETENTRY_05
			Dictionary::Entry ex3 = Dictionary::GetEntry(d1, 14);
		#elif !defined TEST_DICTIONARY
			Dictionary::Entry ex2 = Dictionary::GetEntry(d1, 4);
		#endif
		#if defined TEST_DICTIONARY
			Dictionary::Entry ex2 = Dictionary::GetEntry(d1, 5);
		#endif

		// Удалить эл. словаря по идентификатору
		#ifdef TEST_DELENTRY_06
			Dictionary::DelEntry(d1, 14);
		#elif !defined TEST_DICTIONARY
			Dictionary::DelEntry(d1, 2);
		#endif 
		#if defined TEST_DICTIONARY
			Dictionary::DelEntry(d1, 6);
		#endif

		Dictionary::Entry newentry1 = { 3, "Гурин" };

		// Заменить элемент словаря по идентификатору
		#ifdef TEST_UPDENTRY_07
			Dictionary::UpdEntry(d1, 14, newentry1);
		#elif defined TEST_UPDENTRY_08
			Dictionary::UpdEntry(d1, 1, newentry1);
		#else
			Dictionary::UpdEntry(d1, 3, newentry1);
		#endif	
		#if defined TEST_DICTIONARY
			Dictionary::UpdEntry(d1, 3, newentry1);
		#endif

		Dictionary::Print(d1);				// Распечатать элементы словаря

		Dictionary::Instance d2 = Dictionary::Create("Студенты", 7);
		Dictionary::Entry s1 = { 1, "Иванов" }, s2 = { 2, "Петров" }, s3 = { 3, "Сидоров" },
			s4 = { 4, "Печёрин" }, s5 = { 10, "Онегин" }, s6 = { 6, "Безухов" }, s7 = { 12, "Татарский" };

		Dictionary::AddEntry(d2, s1);
		Dictionary::AddEntry(d2, s2);
		Dictionary::AddEntry(d2, s3);
		#ifdef TEST_DICTIONARY
			Dictionary::AddEntry(d2, s4);
			Dictionary::AddEntry(d2, s5);
			Dictionary::AddEntry(d2, s6);
			Dictionary::AddEntry(d2, s7);
		#endif 

		#ifdef TEST_DICTIONARY
			Dictionary::Entry newentry3 = { 3, "Морковин" };
			Dictionary::UpdEntry(d2, 3, newentry3);
		#else
			Dictionary::Entry newentry4 = { 3, "Николаев" };
			Dictionary::UpdEntry(d2, 3, newentry4);
		#endif

		Dictionary::Print(d2);

		Delete(d1);
		Delete(d2);
	}
	catch (const char* e) {
		std::cout << e << std::endl;
	};
}