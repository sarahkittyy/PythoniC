#pragma once

/**
 * @file
 * @brief Python's in condition. 
 * 
 */
namespace py
{

/**
 * @brief Python's conditional in operator. Checks if an element
 * is inside a container.
 * 
 * @tparam IterableContainer A forward iterable container. 
 * @tparam Item An item inside the container, or comparable to the
 * container's items via ==
 *  
 * @param item The item to search for.
 * @param container The container to search through.
 * 
 * @return true If the item was found.
 * @return false If the item wasn't found.
 * 
 * @example IsIn/IsIn.cpp 
 */
template <typename IterableContainer, typename Item>
bool isin(Item item, IterableContainer container)
{
	//Iterate through each item.
	for (auto &i : container)
	{
		//If it was found...
		if (i == item)
		{
			//Retrun true.
			return true;
		}
	}

	//...It wasn't found, return false.
	return false;
}

}