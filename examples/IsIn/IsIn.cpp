#include <PythoniC/PythoniC.hpp>

#include <iostream>
#include <vector>

int main()
{
	//Create list of odd numbers 1 - 9
	py::intrange odd = py::filter([](int x) {
		return (bool)(x % 2);
	},
								  py::intrange(10));
	//////////////////////////

	//Check if 5 is in that list.
	if (py::isin(5, odd))
	{
		std::cout << "5 is odd.\n";
	}

	//Check if 4 is in that list.
	if (py::isin(4, odd))
	{
		std::cout << "4 is odd.\n";
	}
	else
	{
		std::cout << "4 is not odd.\n";
	}

	return 0;
}