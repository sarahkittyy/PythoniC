#include <PythoniC/PythoniC.hpp>

#include <iostream>

int main()
{
	//Initialize the string.
	std::string str = "    this is a string   ";

	//Strip leading whitespace.
	std::cout << "LStrip : '" << py::string::lstrip(str) << "'";

	//Strip trailing whitespace.
	std::cout << "\nRStrip : '"
			  << py::string::rstrip(str) << "'";

	//Strip all leading & trailing whitespace.
	std::cout << "\nStrip : '"
			  << py::string::strip(str) << "'";

	/*
	Output:
	LStrip : 'this is a string   '
	RStrip : '    this is a string'
	Strip : 'this is a string'
	*/

	return 0;
}