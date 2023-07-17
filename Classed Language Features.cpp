#include <iostream>
#include "SwitchCase.h"

void calcVertical(int top, int bottom, int height, double& res)
{
	res = ((double)top + (double)bottom) / (double)height;
}

void calcHorizontal(int left, int right, int width, double& res)
{
	res = ((double)left + (double)right) / (double)width;
}

void notFound()
{
	std::cout << "There is no calculation for that\n";
}

void Visited(double h_res, double v_res)
{
	std::cout
		<< "Thank you for using our calculation\n"
		<< "Your horizontal result is : " << h_res
		<< "\nYour vertical result is : " << v_res;
}

int main()
{
	SwitchCase<std::string> sc{};
	int width = 1000;
	int height = 600;
	int left = 60;
	int right = 100;
	int top = 100;
	int bottom = 300;
	double v_res = 0.0;
	double h_res = 0.0;
	sc
	.addCase("Vertical", std::bind(calcVertical,top,bottom,height,v_res))
	.addCase("Horizontal", std::bind(calcHorizontal,left,right,width,h_res))
	.switchOn("Horizontal").switchOn("Vertical").switchOn("None", notFound)
	.ifVisited(std::bind(Visited,h_res,v_res))
	;
	std::cin.get();
}