#include <cstring>
#include <locale>
#include <iostream>
#include "stdafx.h"
#define DICTNAMEMAXSIZE		20	// Длина для названия словаря
#define DICTMAXSIZE			100	// Макс. размер словаря
#define ENTRYNAMEMAXSIZE	30	// Максимальный размер имени элемента словаря
#define THROW01 "Create: превышен размер имени словаря"
#define THROW02 "Create: превышен размер максимальной ёмкости словаря"
#define THROW03 "AddEntry: переполнение словаря"
#define THROW04 "AddEntry: дублирование идентификатора"
#define THROW05 "GetEntry: не найден элемент"
#define THROW06 "DelEntry: не найден элемент"
#define THROW07 "UpdEntry: не найден элемент"
#define THROW08 "UpdEntry: дублирование идентификатора"


namespace Dictionary {
	struct Entry {				// Элемент словаря
		int id;			// Идентификатор (уникальный)
		char name[ENTRYNAMEMAXSIZE];	// Символьная информация
	};

	struct Instance {			// Экземпляр словаря
		std::string name;		// Наименование словаря
		int maxsize;	// Макс. размер словаря
		int size;		// текущий размер словаря < DICTMAXSIZE	
		Entry* dictionary;				// Массив элементов словаря
	};

	Instance Create(			// Создать словарь
		std::string name,		// Имя словаря
		int size) {		//Элемент словаря
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

	void AddEntry(				// Добавить эл. словаря
		Instance& inst, // Экземпляр словаря
		Entry ed) {		// Элемент словаря
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

	void DelEntry(			// Удалить эл. словаря
		Instance& inst,	// Экземпляр словаря
		int id) {		// Идентификатор удаляемого элемента (уникальный)
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

	void UpdEntry(				// Изменить элемент словаря
		Instance& inst, // Экземпляр словаря
		int id,			// Идентификатор заменяемого элемента
		Entry new_ed) {	// Новый элемент словаря
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

	Entry GetEntry(				// Получить элемент словаря
		Instance inst,	// Экземпляр словаря
		int id) {		// Идентификатор получаемого элемента
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

	void Print(Instance d) {		// Печать словаря
		std::cout << "---------" << d.name << "---------" << std::endl;
		for (int i = 0; i < d.size; i++) {
			std::cout << d.dictionary[i].id << " " << d.dictionary[i].name << std::endl;
		}
	}
	void Delete(Instance& d) {	// Удалить словарь
		delete[] d.dictionary;
	}
};