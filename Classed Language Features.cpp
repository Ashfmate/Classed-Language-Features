#include <iostream>
#include <conio.h>
#include "SwitchCase.h"
#include "IfElse.h"

bool isAhmed()
{
	std::cout << "Is your name Ahmed? (y/n): ";
	char ans = _getch();
	return ans == 'y' || ans == 'Y';
}

bool isMohammed()
{
	std::cout << "Is your name Mohammed? (y/n): ";
	char ans = _getch();
	return ans == 'y' || ans == 'Y';
}

bool isAyham()
{
	std::cout << "Is your name Ayham? (y/n): ";
	char ans = _getch();
	return ans == 'y' || ans == 'Y';
}

bool isIbrahim()
{
	std::cout << "Is your name Ibrahim? (y/n): ";
	char ans = _getch();
	return ans == 'y' || ans == 'Y';
}

int main()
{
	IfElse ifelse{};

	ifelse
	.add(isAhmed,		[](){std::cout << "Welcome here brother Ahmed\n";		})
	.add(isMohammed,	[](){std::cout << "Welcome here brother Mohammed\n";	})
	.add(isAyham,		[](){std::cout << "Welcome here brother Ayham\n";		})
	.add(isIbrahim,		[](){std::cout << "Welcome here brother Ibrahim\n";		})
	([](){ std::cout << "You are not one of the brothers, please leave\n";		})
	.ifVisited([](){ std::cout << "We welcome you brothers and we want you to come back, for the motherland\n"; })
	;
	std::cin.get();
}