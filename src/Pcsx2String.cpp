#ifdef _WIN32 
#include <Windows.h>
#endif

#include "Pcsx2String.h"
#include <stringapiset.h>

Pcsx2String::Pcsx2String()
{
	count = 0;
	string = "";
}

// Non Default
Pcsx2String::Pcsx2String(const char* str)
{
	count = sizeof(str);
	string = str;
}

// Non default
Pcsx2String::Pcsx2String(const std::wstring& str)
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

Pcsx2String& Pcsx2String::operator=(const std::wstring& str)
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

Pcsx2String& Pcsx2String::operator=(const std::string& str)
{
	count = str.size();
	string = str.data();
	return *this;
}

std::wstring& Pcsx2String::operator=(const Pcsx2String& str)
{
	auto const size =
		MultiByteToWideChar(CP_UTF8, 0, str.string.data(), str.string.size(), nullptr, 0);

	std::wstring output(size, '\0');

	if (size == 0 ||
		size != MultiByteToWideChar(CP_UTF8, 0, str.string.data(), str.string.size(),
			&output[0], output.size()))
	{
		output.clear();
	}

	return output;
}

const char* Pcsx2String::data()
{
	return string.data();
}

bool Pcsx2String::operator==(const Pcsx2String rhs)
{
	return string == rhs.string;
}

Pcsx2String::~Pcsx2String()
{
	count = 0;
	string.clear();
}

std::ostream& operator<<(std::ostream& os, const Pcsx2String& str)
{
	os << str.string.data();
	return os;
}