#pragma once

namespace py
{

/**
 * @brief A recreation of python's map() function. Runs the function func upon every value in the container, returning the now mapped container.
 * 
 * @tparam IterableContainer An STL container with, at the minimum, begin(), end(), and insert(). 
 * @tparam Function A lambda.
 * 
 * @param func The function to apply over each element in container.
 * @param container The container to iterate over.
 * 
 * @return IterableContainer The mapped container.
 * 
 * @example Map/Map.cpp
 */
template <typename IterableContainer, typename Function>
IterableContainer map(Function func, IterableContainer& container)
{
	//Create the new container.
	IterableContainer filtered;

	//For every item...
	for (auto& item : container)
	{
		//Insert the changed item.
		filtered.insert(filtered.end(), func(item));
	}

	//Return the new container.
	return filtered;
}

}