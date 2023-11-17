#include<iostream>
#include<locale>
#include"D:\KPO_2_sem\lab_6\SE_Lab06L\DIctionary.h"

void main() {
	setlocale(LC_ALL, "ru");
	try {
		// �������� �������

		Dictionary::Instance d1 = Dictionary::Create("�������������", 7);

		// �������� �������
		Dictionary::Entry e1 = { 1, "�������" }, e2 = { 2, "�������" },
			e3 = { 3, "������" }, e4 = { 4, "���������" }, e5 = { 5, "�����" },
			e6 = { 6, "�������" }, e7 = { 7, "�����" };

		Dictionary::AddEntry(d1, e1);		// ���. �������� �������
		Dictionary::AddEntry(d1, e2);		// ���. �������� �������
		Dictionary::AddEntry(d1, e3);		// ���. �������� �������
		Dictionary::AddEntry(d1, e4);		// ���. �������� �������
		Dictionary::AddEntry(d1, e6);
		Dictionary::AddEntry(d1, e7);
		Dictionary::AddEntry(d1, e5);


		Dictionary::Entry ex2 = Dictionary::GetEntry(d1, 5);



		Dictionary::DelEntry(d1, 6);

		Dictionary::Entry newentry1 = { 3, "�����" };


		Dictionary::UpdEntry(d1, 3, newentry1);

		Dictionary::Print(d1);				// ����������� �������� �������

		Dictionary::Instance d2 = Dictionary::Create("��������", 7);
		Dictionary::Entry s1 = { 1, "������" }, s2 = { 2, "������" }, s3 = { 3, "�������" },
			s4 = { 4, "�������" }, s5 = { 10, "������" }, s6 = { 6, "�������" }, s7 = { 12, "���������" };

		Dictionary::AddEntry(d2, s1);
		Dictionary::AddEntry(d2, s2);
		Dictionary::AddEntry(d2, s3);
		Dictionary::AddEntry(d2, s4);
		Dictionary::AddEntry(d2, s5);
		Dictionary::AddEntry(d2, s6);
		Dictionary::AddEntry(d2, s7);



		Dictionary::Entry newentry3 = { 3, "��������" };
		Dictionary::UpdEntry(d2, 3, newentry3);

		Dictionary::Entry newentry4 = { 3, "��������" };
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