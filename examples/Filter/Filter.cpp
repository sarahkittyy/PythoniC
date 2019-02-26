#include <PythoniC/PythoniC.hpp>

#include <iostream>

int main()
{
	//Create a new integer range from 0-49.
	py::intrange x(50);

	//Display those numbers.
	for (auto& i : x)
	{
		std::cout << i << " ";
	}
	//Output: 0 1 2 3 4 5 .... 49

	std::cout << "\n--filtered--\n";

	//Now filter through the numbers, pulling only even ones.
	for (auto& i : py::filter(
			 [](int& r) {
				 return (r % 2 == 0);
			 },
			 x))
	{
		//Print out each number.
		std::cout << i << " ";
	}
	//Output: 0 2 4 6 8 .... 48

	return 0;
}