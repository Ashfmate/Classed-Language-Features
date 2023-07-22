#include <iostream>
#include "SwitchCase.h"
#include "IfElse.h"

int main()
{
	SwitchCase<std::string> cs{};
	IfElse ie{};
	std::string res;
	cs
		.add("A", [&res]{ std::cout << "Case A has been hit\n"; res = "A"; })
		.add("B", [&res]{ std::cout << "Case B has been hit\n"; res = "B"; })
		.add("C", [&res]{ std::cout << "Case C has been hit\n"; res = "C"; })
		("B")
	;
	ie
		.add([&res]{ return res == "A"; }, [&res]{ std::cout << "Result is " << res << "\n"; })
		.add([&res]{ return res == "B"; }, [&res]{ std::cout << "Result is " << res << "\n"; })
		.add([&res]{ return res == "C"; }, [&res]{ std::cout << "Result is " << res << "\n"; })
		([] { std::cout << "result is not A or B or C\n"; })
	;
	std::cin.get();
}