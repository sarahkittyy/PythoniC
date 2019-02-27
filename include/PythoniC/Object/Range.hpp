#pragma once

#include <algorithm>   //std::copy
#include <cmath>	   //std::round
#include <iostream>	//std::ostream
#include <stdexcept>   //std::out_of_range
#include <string>	  //std::to_string
#include <vector>	  //std::vector

namespace py
{
/**
 * @brief An iterator over a range of numbers, similar to python's range().
 * 
 * @tparam num_t The numerical type to use. (int, float, double, long)
 * 
 * @example Ranges/Ranges.cpp
 */
template <typename num_t>
class range
{
public:
	/**
	 * @brief Default Constructor.
	 * 
	 */
	range()
	{
	}
	/**
	 * @brief Construct a new range object
	 * 
	 * @param start The starting value.
	 * @param end The value to iterate to.
	 * @param inc The increment.
	 */
	range(num_t start, num_t end, num_t inc = 1)
	{
		//Initalize.
		init(start, end, inc);
	}

	/**
	 * @brief Construct a new Range object. The starting point is by default 0.
	 * 
	 * @param end The ending value.
	 */
	range(num_t end)
	{
		//Initialize.
		init(0, end, 1);
	}

	/**
	 * @brief The beginning iterator. Points to the first element in the list.
	 * 
	 * @return num_t* A pointer to the beginning of the data.
	 */
	num_t* begin()
	{
		return &*data.begin();
		//Just initialize the bare container.
	}

	/**
	 * @brief The ending iterator. Points to the end of the data.
	 * 
	 * @return num_t* A pointer to the end of the data.
	 */
	num_t* end()
	{
		return &*data.end();
	}

	/**
	 * @brief Insert an element into the data.
	 * 
	 * @param pos The iterator position at which to insert the item.
	 * @param item The item to insert.
	 */
	void insert(num_t* pos, num_t item)
	{
		data.insert(data.begin() + std::distance(begin(), pos), item);
	}

	/**
	 * @brief Get the size of the range.
	 * 
	 * @return std::size_t The size of the range.
	 */
	std::size_t size()
	{
		return data.size();
	}

	/**
	 * @brief Gets the number at the specified index.
	 * 
	 * @param index The index to retrieve the number at.
	 * @return num_t& The number.
	 */
	num_t& operator[](unsigned index)
	{
		if (index >= data.size())
		{
			throw std::out_of_range("py::range - Operator [] index too large.");
		}
		else
		{
			return data[index];
		}
	}

private:
	/**
	 * @brief Initializes the data with the given start, end, and increments.
	 * 
	 * @param start The starting position.
	 * @param end The ending position.
	 * @param inc How much to increment by per iteration.
	 */
	void init(num_t start, num_t end, num_t inc)
	{
		//Iterate over all values from start -> end and add them to the data.
		for (num_t val = start; val < end; val += inc)
		{
			// Round the number to three decimal places.
			data.push_back(std::round(val * 1000) / 1000);
		}
	}

	/**
	 * @brief The internal list of numbers to iterate over.
	 * 
	 */
	std::vector<num_t> data;
};

//Some common typedefs.
typedef range<int> intrange;
typedef range<float> floatrange;
}

/**
 * @brief std::ostream operator << overload for range<> class.
 * 
 */
template <class T>
std::ostream& operator<<(std::ostream& stream, py::range<T> range)
{
	//Output the start of the list.
	auto iter = range.begin();
	stream << "[" << *iter;

	//Iterate over the values in range.
	while (++iter != range.end())
	{
		stream << ", " << *iter;
	}

	//Output the end of the list.
	stream << "]";

	//Return the stream.
	return stream;
}