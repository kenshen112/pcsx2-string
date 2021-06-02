#include <iostream>
#include "PString.h"

int main(int argc, char* argv)
{
	PString string = "Hello there";
	PString wString(L"Wello There");
	PString InString;
	std::cin >> InString;
	std::wstring toPrint = wString;
	std::cout << string << std::endl;
	std::cout << "A char: " << string[0] << std::endl;
	std::wcout << toPrint << std::endl;
	std::cout << InString << std::endl;
	return 0;
}