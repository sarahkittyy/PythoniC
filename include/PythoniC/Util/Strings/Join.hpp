#pragma once

#include <sstream>   //std::stringstream
#include <string>	//std::string

namespace py
{
namespace string
{

/**
 * @brief Attempts to convert and join each member of list into one string, 
 * 
 * @tparam IterableContainer A forward iterator, at the minimum.
 * (begin(), end(), operator++())
 * 
 * @param sep The separator between each list element.
 * @param list The list to iterate over and append.
 *  
 * @return std::string The joined string.
 * 
 * @remarks Each element in the list should be convertable to string.
 * std::ostream operator<<() is used to convert.
 * 
 * @example Strings/Join/Join.cpp
 */
template <typename IterableContainer>
std::string join(std::string sep,
				 IterableContainer list)
{
	using std::string;
	using std::stringstream;

	//Declare the return stringstream.
	stringstream ret_stream;

	//Output the first element.
	auto iter = list.begin();
	ret_stream << *iter++;

	//Iterate over eache element in the list.
	while (iter != list.end())
	{
		//Append it to the stream.
		ret_stream << sep << *iter++;
	}

	//Return the stream in string form.
	return ret_stream.str();
}

}
}