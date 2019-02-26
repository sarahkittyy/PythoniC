#include <PythoniC/PythoniC.hpp>

#include <iostream>

int main()
{
	//Create a range of 0-49
	py::intrange x(50);

	//Map each value to itself * 2.
	x = py::map([](int v) { return v * 2; }, x);

	//Print the new mapped values.
	std::cout << x;   //Output.. [0, 2, 4, 6, 8..]
}