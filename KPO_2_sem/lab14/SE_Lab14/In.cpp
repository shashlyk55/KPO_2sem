#include "In.h"
#include "Error.h"
#include"stdafx.h"

namespace In
{
	IN getin(wchar_t infile[])
	{
		IN in;

		in.lines = 0;
		in.size = 0;
		in.ignor = 0;
		int position = 0;

		unsigned char inText[1024] = "";
		in.text = inText;
		unsigned char inputChar = ' ';

		std::ifstream fileInput(infile);

		if (fileInput.fail())
			throw ERROR_THROW(110);
		/*if (!fileInput.is_open()) {
			throw ERROR_THROW(110);
		}*/

		inputChar = fileInput.get();

		while (in.size <= IN_MAX_LEN_TEXT)
		{
			if (fileInput.eof())
			{
				inText[in.size] = '\0';
				break;
			}

			if (inputChar =='\n' && in.code['\n'] != IN::F)
			{
				position = -1;
				in.lines++;
				/*inText[in.size] = inputChar;
				in.size++;
				inputChar = fileInput.get();
				continue;*/
			}

			switch (in.code[(unsigned char)inputChar])
			{
			case IN::T:
				position++;
				inText[in.size] = inputChar;
				in.size++;
				break;

			case IN::F:
				throw ERROR_THROW_IN(111, in.lines, position);

			case IN::I:
				in.ignor++;
				break;

			default:
				inText[in.size] = in.code[(unsigned char)inputChar];
				position++;
				in.size++;
			}

			inputChar = fileInput.get();
		}

		fileInput.close();

		return in;
		/*IN f;
		unsigned char ch = 'a';
		static unsigned char l[1024] = "";
		int line = 0, position = 0, size = 0, ignor = 0, i = 0, pr = 0;
		std::ifstream in;
		in.open(infile);
		if (in.fail() == 0)
		{
			ch = in.get();
			while (pr <= IN_MAX_LEN_TEXT)
			{
				if (in.eof())
				{
					l[i] = '\0';
					break;
				}
				if (ch == ((unsigned char)'\n'))
				{
					position = 0;
					line++;
				}
				if (f.code[(unsigned char)ch] == IN::T)
				{
					position++;
					l[i] = ch;
					i++;
				}
				else if (f.code[(unsigned char)ch] == IN::F)
				{
					throw ERROR_THROW_IN(111, line, position);
				}
				else if (f.code[(unsigned char)ch] == IN::I)
				{
					ignor++;
				}
				else
				{
					l[i] = f.code[(unsigned char)ch];
					i++;
				}

				ch = in.get();
			}

			in.close();
			f.size = i;
			f.text = l;
			f.lines = line;
			f.ignor = ignor;

		}

		else
		{
			throw ERROR_THROW(110);
		}

		return f;*/
	}
};
