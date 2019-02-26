#include "Range.h"

#include <iostream>

int main()
{
	//Iterate from 0-9.
	for (auto i : Range(10))
	{
		std::cout << i << " ";
	}
	std::cout << "\n-----\n";
	//Iterate from -10 to 10 with an increment of 0.5.
	for (auto i : RangeFloat(-10, 10, 0.5))
	{
		std::cout << i << " ";
	}
}