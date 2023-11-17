#include "Parm.h"
#include"Error.h"
#include"stdafx.h"

namespace Parm
{
	PARM getparm(int argc, _TCHAR* argv[])
	{
		PARM parm;

		bool hasIn = false;
		bool hasOut = false;
		bool hasLog = false;

		for (int i = 0; i < argc; i++)
		{
			if (wcsstr(argv[i], PARM_IN))
				hasIn = true;

			if (wcsstr(argv[i], PARM_OUT))
				hasOut = true;

			if (wcsstr(argv[i], PARM_LOG))
				hasLog = true;
		}

		if (!hasIn)
			throw ERROR_THROW(100)

			for (int i = 0; i < argc; i++)
			{
				if (wcslen(argv[i]) > PARM_MAX_SIZE)
					throw ERROR_THROW(104);

				if (wcsstr(argv[i], PARM_IN))
					wcscpy_s(parm.in, wcsstr(argv[i], L":") + 1);

				if (wcsstr(argv[i], PARM_OUT))
					wcscpy_s(parm.out, wcsstr(argv[i], L":") + 1);

				if (wcsstr(argv[i], PARM_LOG))
					wcscpy_s(parm.log, wcsstr(argv[i], L":") + 1);
			}

		if (!hasOut)
		{
			wcscpy_s(parm.out, parm.in);
			wcscat_s(parm.out, PARM_OUT_DEFAULT_EXT);
		}

		if (!hasLog)
		{
			wcscpy_s(parm.log, parm.in);
			wcscat_s(parm.log, PARM_LOG_DEFAULT_EXT);
		}

		return parm;
		/*PARM f;

		bool rc = 0, rb = 0, rl = 0;

		for (int l = 0; l < argc; l++)
		{
			if (wcsstr(argv[l], PARM_IN))
			{
				rc = 1;
			}
			if (wcsstr(argv[l], PARM_OUT))
			{
				rb = 1;
			}
			if (wcsstr(argv[l], PARM_LOG))
			{
				rl = 1;
			}
		}
		if (rc == 0)
		{
			throw ERROR_THROW(100)
		}
		for (int i = 0; i < argc; i++)
		{
			if (wcslen(argv[i]) > PARM_MAX_SIZE) throw ERROR_THROW(104);

			if (wcsstr(argv[i], PARM_IN))
			{
				wchar_t* h = wcsstr(argv[i], L":") + 1;
				wcscpy_s(f.in, h);
			}
			if (wcsstr(argv[i], PARM_OUT))
			{
				wchar_t* h = wcsstr(argv[i], L":") + 1;
				wcscpy_s(f.out, h);
			}
			if (wcsstr(argv[i], PARM_LOG))
			{
				wchar_t* h = wcsstr(argv[i], L":") + 1;
				wcscpy_s(f.log, h);
			}

		}
		if (rb == 0)
		{
			wcscpy_s(f.out, f.in);
			wcscat_s(f.out, PARM_OUT_DEFAULT_EXT);
		}
		if (rl == 0)
		{
			wcscpy_s(f.log, f.in);
			wcscat_s(f.log, PARM_LOG_DEFAULT_EXT);
		}
		return f;*/
	}
};