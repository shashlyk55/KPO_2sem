#include"stdafx.h"
#include "Error.h"		//обработка ошибок
#include "Parm.h"		//обработка параметров
#include "Log.h"		//работв с протоколом
#include "In.h"			//ввод исходного файла

int main(int argc, _TCHAR* argv[]) {

	argv[0] = (_TCHAR*)L"-in:D:\\KPO_2_sem\\lab14\\SE_Lab14\\text.txt";

	setlocale(LC_ALL, "ru");

	//----------------------------------
	//std::cout << "---- тест Error::geterror ----\n\n";

	//try {
	//	throw ERROR_THROW(100);
	//}
	//catch (Error::ERROR e) {
	//	std::cout << "Ошибка " << e.id << ": " << e.message << std::endl << std::endl;
	//}

	//std::cout << "---- тест Error::geterrorin ----\n\n";
	//try {
	//	throw ERROR_THROW_IN(111, 7, 7);
	//}
	//catch (Error::ERROR e) {
	//	std::cout << "Ошибка " << e.id << ": " << e.message 
	//		<< ", строка " << e.inext.line 
	//		<< ", позиция " << e.inext.col << std::endl << std::endl;
	//}

	////----------------------------------
	//std::cout << "---- тест Parm::getparm ----\n\n";

	//try {
	//	Parm::PARM parm = Parm::getparm(argc, argv);
	//	std::wcout << "-in:" << parm.in << ", -out:" << parm.out << ", -log:" << parm.log << std::endl << std::endl;
	//}
	//catch (Error::ERROR e) {
	//	std::cout << "Ошибка " << e.id << ": " << e.message << std::endl << std::endl;
	//}
	////----------------------------------
	//std::cout << "---- тест In::getin ----\n\n";

	//try {
	//	Parm::PARM parm = Parm::getparm(argc, argv);
	//	In::IN in = In::getin(parm.in);
	//	std::cout << in.text << std::endl;
	//	std::cout << "Всего символов: " << in.size << std::endl;
	//	std::cout << "Всего строк: " << in.lines << std::endl;
	//	std::cout << "Пропущено: " << in.ignor << std::endl;
	//}
	//catch (Error::ERROR e) {
	//	std::cout << "Ошибка " << e.id << ": " << e.message << std::endl << std::endl;
	//}

	////----------------------------------
	/*std::cout << "---- тест In::getin ----\n\n";

	try {
		Parm::PARM parm = Parm::getparm(argc, argv);
		In::IN in = In::getin(parm.in);
		std::cout << in.text << std::endl;
		std::cout << "Всего символов: " << in.size << std::endl;
		std::cout << "Всего строк: " << in.lines << std::endl;
		std::cout << "Пропущено: " << in.ignor << std::endl;
	}
	catch (Error::ERROR e) {
		std::cout << "Ошибка " << e.id << ": " << e.message << std::endl << std::endl;
		std::cout << "строка " << e.inext.line << " позиция " << e.inext.col << std::endl << std::endl;
	}*/
	//-----------------------------------
	Log::LOG log = Log::INITLOG;
	try {
		Parm::PARM parm = Parm::getparm(argc, argv);
		log = Log::getlog(parm.log);
		Log::WriteLine(log, (char*)"Тест:", (char*)" без ошибок \n", "");
		Log::WriteLine(log, (wchar_t*)L"Тест:", (wchar_t*)L" без ошибок \n", L"");
		Log::WriteLog(log);
		Log::WriteParm(log, parm);
		In::IN in = In::getin(parm.in);
		Log::WriteIn(log, in);
		Log::Close(log);
	}
	catch (Error::ERROR e) {
		Log::WriteError(log, e);
	}
	//-----------------------------------

	system("pause");
	return 0;
}
