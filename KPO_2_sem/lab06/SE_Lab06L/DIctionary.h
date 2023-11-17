#pragma once
#include <cstring>
#include <locale>
#include <iostream>

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

	Instance Create(std::string name,int size);

	void AddEntry(Instance& inst,Entry ed);

	void DelEntry(Instance& inst,int id);

	void UpdEntry(Instance& inst,int id,Entry new_ed);

	Entry GetEntry(Instance inst, int id);

	void Print(Instance d);
	void Delete(Instance& d);
};