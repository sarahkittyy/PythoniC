#include <PythoniC/PythoniC.hpp>

#include <iostream>

/*
If you find behavior that python wouldn't emulate,
submit an issue!
*/
int main()
{
	//Create a new integer range from 0-19.
	py::intrange x(20);

	//Get elements up to elem 10 (9).
	std::cout << "1-10: " << x[":10"];

	//Reverse the integer range.
	std::cout << "\nReversed: " << x["::-1"];

	//Reverse a section of the range.
	std::cout << "\nReversed 2-8: " << x["8:2:-1"];

	return 0;
}