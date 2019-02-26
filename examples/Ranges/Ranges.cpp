#include <PythoniC/PythoniC.hpp>

#include <iostream>

int main()
{
	//Iterate from 0-9.
	std::cout << py::range(10);
	std::cout << "\n-----\n";
	//Iterate from -10 to 10 with an increment of 0.5.
	std::cout << py::floatrange(-10, 10, 0.5);
}