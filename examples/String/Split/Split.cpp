#include <PythoniC/PythoniC.hpp>

#include <iostream>

int main()
{
	//Initialize the string.
	std::string str = "this is a string";

	//Split the string.
	auto split = py::string::split(str, ' ');

	//Iterate through each split element...
	for (auto &i : split)
	{
		//And print it, separated by a new line.
		std::cout << i << "\n";
	}
	/*
	Output:
	this
	is
	a
	string
	*/
	return 0;
}