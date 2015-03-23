#ifndef __P2String_H__
#define __P2String_H__

#include <stdio.h>
#include <stdarg.h>
#include <string.h>

#define TMP_STRING_SIZE 4096

class P2String
{

private:

	char*	str;
	unsigned int	size;
	void Alloc(unsigned int requiredMemory)
	{
		size = requiredMemory;
		str = new char[size];
	}

public:

	////////////////////
	// Constructors
	///////////////////

	P2String()
	{
		Alloc(1);
		Clear();

	}

	P2String(unsigned int size)
	{
		if (size > 0)
			Alloc(size);
		else
			Alloc(1);
		Clear();
	}

	P2String(const P2String &string)
	{
		Alloc(string.size);
		strcpy_s(str, size, string.str);
	}

	P2String(const char *format, ...)
	{
		static char tmp[TMP_STRING_SIZE];
		static va_list ap;

		va_start(ap, format);
		int res = vsnprintf_s(tmp, TMP_STRING_SIZE, format, ap);
		va_end(ap);

		if (res > 0)
		{
			Alloc(res + 1);
			strcpy_s(str, size, tmp);
		}
	}

	/////////////////
	// Destructor
	////////////////

	virtual ~P2String()
	{
		if (str != NULL)
			delete[] str;
	}

	////////////////
	// Operators
	///////////////

	bool operator == (P2String &string) const
	{
		return strcmp(str, string.str) == 0;
	}

	bool operator == (const char* string) const
	{
		if (string != NULL)
			return strcmp(str, string) == 0;
		return false;
	}

	bool operator != (P2String &string) const
	{
		return strcmp(str, string.str) != 0;
	}

	bool operator != (const char* string) const
	{
		if (string != NULL)
			return strcmp(str, string) != 0;
	}

	const P2String &operator = (const P2String &string)
	{
		if (string.Length() + 1 > size)
		{
			delete[] str;
			Alloc(string.Length() + 1);
		}
		else
			Clear();
		strcpy_s(str, size, string.str);
		return(*this);
	}

	const P2String &operator = (const char* string)
	{
		if (string != NULL)
		{
			if (strlen(string) + 1 > size)
			{
				Alloc(strlen(string) + 1);
			}
			else
			Clear();
			strcpy_s(str, size, string);
		}
		else
		Clear();
		return(*this);
	}

	const P2String	&operator += (const P2String &string)
	{
		unsigned int needSize = string.Length() + Length() + 1;
		if (needSize > size)
		{
			char* tmp = str;
			Alloc(needSize);
			strcpy_s(str, size, tmp);
			delete[]tmp;
		}
		strcat_s(str, size, string.str);
		return (*this);

	}

	const P2String &operator += (const char* string)
	{
		if (string != NULL)
		{
			unsigned int needSize = strlen(string) + Length() + 1;
			if (needSize > size)
			{
				char* tmp = str;
				Alloc(needSize);
				strcpy_s(str, size, tmp);
				delete[] tmp;
			}
			strcat_s(str, size, string);
		}
		return(*this);
	}


	//////////////////
	// Utils
	////////////////7

	void Clear()
	{
		str[0] = '\0';
	}

	unsigned int Length() const
	{
		return strlen(str);
	}

	const char* GetString() const
	{
		return (str);
	}
	
	unsigned int GetSize() const
	{
		return (size);
	}

};

























#endif