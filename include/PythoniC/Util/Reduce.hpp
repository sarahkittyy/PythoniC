#pragma once

/**
 * @file
 * @brief Python's reduce() method. 
 * 
 */
namespace py
{

/**
 * @brief A recreation of python's functools.reduce() function.
 * Runs func() on the first two values of the container and pops them, 
 * putting the result back in. It repeats this with it's previous result & the next element. It will continue to loop until all elements have reduced to a single value.
 * 
 * @tparam IterableContainer An STL container with, at the minimum, begin(), end(), and insert(). 
 * @tparam Function A lambda.
 * 
 * @param func The function to apply to every two values in the container
 * @param container The container to iterate over.
 * 
 * @return The final reduced item.
 * 
 * @example Reduce/Reduce.cpp
 */
template <typename IterableContainer, typename Function>
auto reduce(Function func, IterableContainer& container)
{
	//Get the first element.
	auto first_elem = *container.begin();

	//Iterate over all but the first element.
	for (auto item = container.begin() + 1; item != container.end(); item++)
	{
		//Apply the func onto first_elem & item and put the result back into first_elem.
		first_elem = func(first_elem, *item);
	}

	//Return the reduced element.
	return first_elem;
}

}