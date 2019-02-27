#pragma once

#include <array>	//std::array
#include <cctype>   //std::isspace
#include <regex>	//std::regex, std::regex_search, etc...
#include <string>   //std::string
#include <vector>   //std::vector

namespace py
{

/**
 * @brief A replication of python's intuitive list-splicing syntax- i.e. list[1:4:-1]. The syntax is emulated by passing a string.
 * Many iterable PythoniC classes will call this in their operator[] overload.
 * 
 * @see https://www.pythoncentral.io/how-to-slice-listsarrays-and-tuples-in-python/
 * @see range::operator[]
 * 
 * @tparam IterableContainer A container with support for random-access iteration (operator[], begin(), end(), insert(), size())
 * Ex: std::vector, py::range
 * 
 * @param container The container to splice.
 * @param index A string representing the splice.
 * @return IterableContainer A spliced version of the container.
 */
template <typename IterableContainer>
IterableContainer splice(IterableContainer& container,
						 std::string index)
{
	using std::array;
	using std::regex;
	using std::regex_search;
	using std::smatch;
	using std::string;
	using std::vector;
	//First, validate the index.
	regex index_validator(R"(-?\d*(:-?\d*){0,2})");
	smatch _;   //Unnecessary variable
	if (!regex_search(index, _, index_validator))
	{
		throw std::out_of_range("py::splice() - Invalid splice \"" + index + "\".");
	}

	//Next, retrieve each splice index.
	array<string, 3> splices;
	int current_splice = 0;
	for (auto& i : index)   // For every character in the string..
	{
		//If it's a colon..
		if (i == ':')
		{
			//Increment the current splice.
			current_splice++;
		}
		//Otherwise (as long as it's not whitespace..)
		else if (!std::isspace(i))
		{
			//Append the current character to the current splice.
			splices[current_splice].push_back(i);
		}
	}

	//Check each splice index, and convert to an integer if possible.
	vector<int> int_splices;
	const int splice_defaults[3] = {0, (int)container.size(), 1};   //Default splice values.

	//Iterate over each splice
	for (unsigned i = 0; i < splices.size(); ++i)
	{
		//If the splice is empty...
		if (splices[i].size() == 0)
		{
			//Append the default value.
			int_splices.push_back(splice_defaults[i]);
		}
		else
		{
			//Append the splice, converted to an integer.
			int_splices.push_back(std::stoi(splices[i]));
		}
	}
	//Grab the start, end, and inc values finally.
	int start = std::min(int_splices[0], int_splices[1]);
	int end   = std::max(int_splices[0], int_splices[1]);
	int inc   = int_splices[2];

	//If the inc is less than 0, swap start & end.
	if (inc < 0)
	{
		int tmp = start;
		start   = end;
		//Inc/dec to account for endpoint in/exclusion
		if (start == (int)container.size())
		{
			start--;
		}
		end = tmp - 1;
	}

	//Check to make sure the start and end aren't negative, and that inc isn't 0.
	if (start < 0 || end < 0)
	{
		throw std::out_of_range("py::splice - Invalid splice start/end values, must be >= 0");
	}
	if (inc == 0)
	{
		throw std::out_of_range("py::splice - Splice increment cannot be 0.");
	}

	//Declare the container we will return.
	IterableContainer return_container;

	/*
	Some operation examples: List: [1, 2, 3, 4, 5]
	[2:4] -> [3, 4]
	[2:3] -> [3]
	[2:2] -> []
	[::-1] -> [5, 4, 3, 2, 1]
	[::-2] -> [5, 3, 1]
	[::-3] -> [5, 2]
	[5:0:-1] -> [5, 4, 3, 2]
	[5::-1] -> [5, 4, 3, 2, 1]
	[4::-1] -> [5, 4, 3, 2, 1]
	[3::-1] -> [4, 3, 2, 1]
	*/

	//Iterate over the original container.
	//The for-loop condition is so that if we're iterating backwards,
	//we still stop at the correct point
	for (int i = start; (inc < 0) ? (i > end) : (i < end); i += inc)
	{
		//Append the items.
		return_container.insert(return_container.end(), container[i]);
	}

	//Return the container!
	return return_container;
}

}