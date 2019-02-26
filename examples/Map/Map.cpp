#include <PythoniC/PythoniC.hpp>

#include <iostream>

int main()
{
	//Create a range of 0-49
	py::intrange x(50);

	//Map each value to itself * 2.
	x = py::map([](int v) { return v * 2; }, x);

	//Iterate over the values & print them
	for (auto &i : x)
	{
		std::cout << i << " ";
	}   //Output: 0 2 4 6 8 10 12 .... 98
}