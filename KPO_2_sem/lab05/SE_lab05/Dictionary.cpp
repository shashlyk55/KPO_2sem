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
#error ���������� ������� ����� ���������
#endif

void main() {
	setlocale(LC_ALL, "ru");
	try {
		// �������� �������
		#ifdef TEST_CREATE_01
			Dictionary::Instance d1 = Dictionary::Create("������������� � ������� ��� �������� � ������� ��������", 5);
		#elif defined TEST_CREATE_02
			Dictionary::Instance d1 = Dictionary::Create("�������������", 110);
		#elif !defined TEST_DICTIONARY
			Dictionary::Instance d1 = Dictionary::Create("�������������", 5);
		#endif

		#if defined TEST_DICTIONARY
			Dictionary::Instance d1 = Dictionary::Create("�������������", 7);
		#endif 

		// �������� �������
		Dictionary::Entry e1 = { 1, "�������" }, e2 = { 2, "�������" },
				e3 = { 3, "������" }, e4 = { 4, "���������" }, e5 = { 2, "�����" },
				e6 = { 5, "�������" }, e7 = { 6, "�����" }, e8 = { 7, "Ը�����" };

		Dictionary::AddEntry(d1, e1);		// ���. �������� �������
		Dictionary::AddEntry(d1, e2);		// ���. �������� �������
		Dictionary::AddEntry(d1, e3);		// ���. �������� �������
		Dictionary::AddEntry(d1, e4);		// ���. �������� �������
		#if defined TEST_DICTIONARY
			Dictionary::AddEntry(d1, e6);
			Dictionary::AddEntry(d1, e7);
			Dictionary::AddEntry(d1, e8);
		#endif 
		#ifdef TEST_ADDENTRY_03
			e6 = { 19, "�������" }, e7 = { 84, "������" };
			Dictionary::AddEntry(d1, e6);
			Dictionary::AddEntry(d1, e7);
		#elif defined TEST_ADDENTRY_04
			Dictionary::AddEntry(d1, e5);
		#endif

		// ����� ��. ������� �� ��������������
		#ifdef TEST_GETENTRY_05
			Dictionary::Entry ex3 = Dictionary::GetEntry(d1, 14);
		#elif !defined TEST_DICTIONARY
			Dictionary::Entry ex2 = Dictionary::GetEntry(d1, 4);
		#endif
		#if defined TEST_DICTIONARY
			Dictionary::Entry ex2 = Dictionary::GetEntry(d1, 5);
		#endif

		// ������� ��. ������� �� ��������������
		#ifdef TEST_DELENTRY_06
			Dictionary::DelEntry(d1, 14);
		#elif !defined TEST_DICTIONARY
			Dictionary::DelEntry(d1, 2);
		#endif 
		#if defined TEST_DICTIONARY
			Dictionary::DelEntry(d1, 6);
		#endif

		Dictionary::Entry newentry1 = { 3, "�����" };

		// �������� ������� ������� �� ��������������
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

		Dictionary::Print(d1);				// ����������� �������� �������

		Dictionary::Instance d2 = Dictionary::Create("��������", 7);
		Dictionary::Entry s1 = { 1, "������" }, s2 = { 2, "������" }, s3 = { 3, "�������" },
			s4 = { 4, "�������" }, s5 = { 10, "������" }, s6 = { 6, "�������" }, s7 = { 12, "���������" };

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
			Dictionary::Entry newentry3 = { 3, "��������" };
			Dictionary::UpdEntry(d2, 3, newentry3);
		#else
			Dictionary::Entry newentry4 = { 3, "��������" };
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