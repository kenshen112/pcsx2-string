#include "Pcsx2String.h"
#include <codecvt>

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
	static std::wstring_convert< std::codecvt_utf8<wchar_t>, wchar_t > converter;
	string = converter.to_bytes(str);
	count = string.size();
}

Pcsx2String& Pcsx2String::operator=(const std::wstring& str)
{
	static std::wstring_convert< std::codecvt_utf8<wchar_t>, wchar_t > converter;
	string = converter.to_bytes(str);
	count = string.size();
	return *this;
}

Pcsx2String& Pcsx2String::operator=(const std::string& str)
{
	count = str.size();
	string = str.data();
	return *this;
}

Pcsx2String::operator std::wstring()
{
	std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> converter;
	return converter.from_bytes(string.c_str()).data();
}

std::wstring& Pcsx2String::operator=(const Pcsx2String& str)
{
	std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> converter;
	std::wstring type = converter.from_bytes(str.string.c_str());
	return type;
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