#include "PString.h"
#include <codecvt>

PString::PString()
{
	count = 0;
	string = "";
}

// Non Default
PString::PString(const char* str)
{
	count = sizeof(str);
	string = str;
}

PString::PString(const PString& rhs)
{
	count = rhs.count;
	string = rhs.string;
}

// Non default
PString::PString(const std::wstring& str)
{
	count = str.size();
	char* temp = new char[count];
	const wchar_t* wStr = str.c_str();
	size_t len = (wcslen(wStr) + 1) * sizeof(wchar_t);
	wcstombs_s(&count, temp, len, wStr, len);
	if (temp != nullptr)
	{
		string = temp;
	}
}

PString& PString::operator=(const std::wstring& str)
{
	count = str.size();
	char* temp = new char[count];
	const wchar_t* wStr = str.c_str();
	size_t len = (wcslen(wStr) + 1) * sizeof(wchar_t);
	wcstombs_s(&count, temp, len, wStr, len);
	if (temp != nullptr)
	{
		string = temp;
	}
	return *this;
}

PString& PString::operator=(const std::string& str)
{
	count = str.size();
	string = str.data();
	return *this;
}

PString::operator std::wstring()
{
	wchar_t* wstr = new wchar_t[count];
	mbstowcs_s(&count, wstr, count, string, count);
	std::wstring buf(wstr);
	return buf;
}

std::wstring& PString::operator=(const PString& str)
{
	size_t size = str.count;
	wchar_t* wstr = new wchar_t[str.count];
	mbstowcs_s (&size, wstr, size, str.string, size);
	std::wstring buf(wstr);
	return buf;
}

void PString::resize(size_t siz)
{
	count = siz;
	string = new char[siz];
}

void PString::resize(size_t siz, char c)
{
	delete string;
	count = siz;
	string += c;
}

bool PString::operator==(const PString rhs)
{
	return string == rhs.string;
}

std::ostream& operator<<(std::ostream& os, const PString& str)
{
	os << str.string;
	return os;
}

std::istream& operator>> (std::istream& is, PString& str)
{
	char* streambuf = new char[5000];
	is.get(streambuf, 5000);
	str.string = streambuf;
	return is;
}

std::istream& getline(std::istream& is, PString& str, char delim)
{
	char* streambuf = new char[5000];
	is.get(streambuf, 5000, delim);
	str.string = streambuf;
	return is;
}

PString::~PString()
{
	count = 0;
	string = "";
}
