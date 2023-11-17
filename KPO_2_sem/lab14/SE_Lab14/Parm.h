#pragma once
#include"stdafx.h"
#define PARM_IN L"-in:"					// ключ файла исзодного кода
#define PARM_OUT L"-out:"				// ключ для файла объектного окда
#define PARM_LOG L"-log:"				// ключ для файла журнала
#define PARM_MAX_SIZE 300				// максимальная длинна строки параметра 
#define PARM_OUT_DEFAULT_EXT L".out"	// расширение файла объектного кода по умолчанию
#define PARM_LOG_DEFAULT_EXT L".log"	// расширение файла протокола по умолчанию

namespace Parm {
	struct PARM {
		wchar_t in[PARM_MAX_SIZE];		// -in: имя файла исходного кода
		wchar_t out[PARM_MAX_SIZE];		// -out: имя файла объектного кода
		wchar_t log[PARM_MAX_SIZE];		// -log: имя файла проокола
	};

	PARM getparm(int argc, _TCHAR* argv[]);
}
