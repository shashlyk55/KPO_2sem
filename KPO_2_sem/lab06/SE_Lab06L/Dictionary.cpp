#include<iostream>
#include"Dictionary.h"

namespace Dictionary {
	Instance Create(			// ������� �������
		std::string name,		// ��� �������
		int size) {		//������� �������
		if (name.length() > DICTNAMEMAXSIZE) {
			throw THROW01;
		}
		if (size > DICTMAXSIZE) {
			throw THROW02;
		}
		Entry* mass_entry = new Entry[size];
		Instance d1;
		d1.size = 0;
		d1.maxsize = size;
		d1.dictionary = mass_entry;
		d1.name = name;
		return d1;
	}

	void AddEntry(				// �������� ��. �������
		Instance& inst, // ��������� �������
		Entry ed) {		// ������� �������
		if (inst.size >= inst.maxsize) {
			throw THROW03;
		}
		for (int i = 0; i <= inst.size; i++) {
			if (ed.id == inst.dictionary[i].id) {
				throw THROW04;
			}
		}
		inst.dictionary[inst.size] = ed;
		inst.size++;
	}

	void DelEntry(			// ������� ��. �������
		Instance& inst,	// ��������� �������
		int id) {		// ������������� ���������� �������� (����������)
		bool flag = true;
		for (int i = 0; i <= inst.size; i++) {
			if (id == inst.dictionary[i].id) {
				flag = false;
				for (int ndel = id - 1; ndel < inst.size; ndel++) {
					inst.dictionary[ndel] = inst.dictionary[ndel + 1];
				}
				inst.size -= 1;
				break;
			}
		}
		if (flag) {
			throw THROW06;
		}
	}

	void UpdEntry(				// �������� ������� �������
		Instance& inst, // ��������� �������
		int id,			// ������������� ����������� ��������
		Entry new_ed) {	// ����� ������� �������
		for (int j = 0; j <= inst.size; j++) {
			if (id == inst.dictionary[j].id) {
				continue;
			}
			if (new_ed.id == inst.dictionary[j].id) {
				throw THROW08;
			}
		}
		bool flag = true;
		for (int j = 0; j <= inst.size; j++) {
			if (id == inst.dictionary[j].id) {
				flag = false;
				break;
			}
		}
		if (flag) {
			throw THROW07;
		}
		for (int i = 0; i <= inst.size; i++) {
			if (inst.dictionary[i].id == id) {
				inst.dictionary[i] = new_ed;
				break;
			}
		}
	}

	Entry GetEntry(				// �������� ������� �������
		Instance inst,	// ��������� �������
		int id) {		// ������������� ����������� ��������
		bool flag = true;
		for (int j = 0; j <= inst.size; j++) {
			if (id == inst.dictionary[j].id) {
				flag = false;
				break;
			}
		}
		if (flag) {
			throw THROW05;
		}
		for (int i = 0; i <= inst.size; i++) {
			if (inst.dictionary[i].id == id) {
				return inst.dictionary[i];
			}
		}
	}

	void Print(Instance d) {		// ������ �������
		std::cout << "---------" << d.name << "---------" << std::endl;
		for (int i = 0; i < d.size; i++) {
			std::cout << d.dictionary[i].id << " " << d.dictionary[i].name << std::endl;
		}
	}
	void Delete(Instance& d) {	// ������� �������
		delete[] d.dictionary;
	}
}
