#include <iostream>
#include "Pcsx2String.h"

int main(int argc, char* argv)
{
	Pcsx2String string = "Hello there";
	Pcsx2String wString(L"Wello There");
	std::wstring toPrint = wString;
	std::cout << string << std::endl;
	std::cout << "A char: " << string[0] << std::endl;
	std::wcout << toPrint << std::endl;
	return 0;
}