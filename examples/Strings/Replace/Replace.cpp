#include <PythoniC/PythoniC.hpp>

#include <iostream>

int main()
{
	//Declare the string.
	std::string str = "Peter Piper picked a peck of Pickled Peppers.";

	//Print out the string, but with 'p' replaced with 'b'.
	std::cout << py::string::replace(str, 'p', 'b', true) << "\n";

	//Print out the string, but replaced case-sensitively.
	std::cout << py::string::replace(str, 'p', 'b');

	return 0;
}