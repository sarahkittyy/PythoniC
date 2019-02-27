#include <PythoniC/PythoniC.hpp>

#include <iostream>

int main()
{
	//Declare a range of integers.
	py::intrange x(10);

	//Join each element, separated by a > character.
	auto joint = py::string::join(">", x);

	//Print the newly formed string.
	std::cout << joint;
	//Output: 0>1>2>3...>9

	return 0;
}