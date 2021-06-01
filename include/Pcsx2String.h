#pragma once
#include <iostream>
#include <filesystem>
#include <clocale>
#include <stdlib.h>
#include <string>

class Pcsx2String
{
private:
	size_t count;
	std::basic_string<char> string;
public:
	Pcsx2String();
	// Non default constructors
	explicit Pcsx2String(const std::wstring& wString);
	Pcsx2String(const char* string);
	
	// Copy Constructor
	Pcsx2String(const Pcsx2String& rhs);

	bool operator==(const Pcsx2String rhs);
	Pcsx2String& operator=(const std::wstring&);
	Pcsx2String& operator=(const std::string&);
	std::wstring& operator=(const Pcsx2String&);

	size_t size()
	{
		return count;
	}

	const char* data();

	char operator[](int index)
	{
		return string.c_str()[index];
	}

	friend std::ostream& operator<<(std::ostream & os, const Pcsx2String& str);

	~Pcsx2String();
};

