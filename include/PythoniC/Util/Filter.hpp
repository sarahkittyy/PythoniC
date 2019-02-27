#pragma once

/**
 * @file
 * @brief Python's filter() method. 
 * 
 */
namespace py
{

/**
 * @brief A recreation of python's filter() function. Takes in a container and a predicate and returns a container with only elements that the predicate returns true.
 * 
 * @tparam IterableContainer An STL container with, at the minimum, begin(), end(), and insert(). 
 * @tparam Predicate A function that takes 1 parameter and returns bool.
 * 
 * @param pred The predicate of which to test each value on.
 * @param container The container to iterate over.
 * 
 * @return IterableContainer The filtered container.
 * 
 * @example Filter/Filter.cpp
 */
template <class IterableContainer, typename Predicate>
IterableContainer filter(Predicate pred, IterableContainer container)
{
	//Create the return container.
	IterableContainer filtered;
	//Iterate over each item.
	for (auto& item : container)
	{
		//If the predicate returns true...
		if (pred(item))
		{
			//This is the most generic way I could find of
			//appending to the back of a container.
			filtered.insert(filtered.end(), item);
		}
	}

	return filtered;
}

}