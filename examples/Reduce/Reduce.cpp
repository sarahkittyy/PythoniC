#include <PythoniC/PythoniC.hpp>

#include <iostream>

int main()
{
	//Declare a range of integers 0-9.
	py::intrange x(10);

	//Shift those values up by 1.
	x = py::map([](int x) { return x + 1; }, x);

	//Sum them all up.
	int sum = py::reduce([](int x, int y) { return x + y; }, x);

	//Output the sum.
	std::cout << "Sum: " << sum << "\n";   //Outputs 55.

	//Find the maximum value.
	int max = py::reduce([](int x, int y) { return (x > y) ? (x) : (y); }, x);

	//Output the maximum.
	std::cout << "Maximum: " << max << "\n";

	return 0;
}