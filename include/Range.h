#include <cmath>   //std::ceil, std::round

/**
 * @brief An iterator over a range of numbers, similar to python's range().
 * 
 * @tparam num_t The numerical type to use. (int, float, double, long)
 * 
 * @example Ranges/Ranges.cpp
 */
template <typename num_t>
class Range
{
public:
	/**
	 * @brief Construct a new Range object
	 * 
	 * @param start The starting value.
	 * @param end The value to iterate to.
	 * @param inc The increment.
	 */
	Range(num_t start, num_t end, num_t inc = 1)
	{
		//Initalize.
		init(start, end, inc);
	}

	/**
	 * @brief Construct a new Range object. The starting point is by default 0.
	 * 
	 * @param end The ending value.
	 */
	Range(num_t end)
	{
		//Initialize.
		init(0, end, 1);
	}

	/**
	 * @brief Delete the Range object.
	 * 
	 */
	~Range()
	{
		//Free resources.
		delete[] data;
	}

	/**
	 * @brief The beginning iterator. Points to the first element in the list.
	 * 
	 * @return num_t* A pointer to the beginning of the data.
	 */
	num_t* begin()
	{
		return &data[0];
	}

	/**
	 * @brief The ending iterator. Points to the end of the data.
	 * 
	 * @return num_t* A pointer to the end of the data.
	 */
	num_t* end()
	{
		return &data[size];
	}

	/**
	 * @brief The increment operator.
	 * 
	 * @return num_t& A reference to the incremented value.
	 */
	num_t&
	operator++()
	{
		//Increment the iterator.
		iter++;

		//Return this.
		return *this;
	}

	/**
	 * @brief The post-increment operator.
	 * 
	 * @return num_t The value before incrementing.
	 */
	num_t
	operator++(int)
	{
		//Copy the iterator.
		num_t temp(*iter);

		//Increment the iterator.
		operator++();

		//Return our original copy.
		return temp;
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
		//Get the length of the range data.
		size = std::ceil((end - start) / inc);
		//Allocate the values.
		data = new num_t[size];
		//Set the iterator to the beginning.
		iter = data;

		//Iterate over all values from start -> end and add them to the data.
		for (num_t val   = start,
				   index = 0;
			 val < end;
			 val += inc,
				   index++)
		{
			// Round the number to three decimal places.
			data[(int)index] = std::round(val * 1000) / 1000;
		}
	}

	/**
	 * @brief The internal list of numbers to iterate over.
	 * 
	 */
	num_t* data;

	/**
	 * @brief The length of the data.
	 * 
	 */
	std::size_t size;

	/**
	 * @brief The iterator pointing to the current element in data.
	 * 
	 */
	num_t* iter;
};

//Some common typedefs.
typedef Range<int> RangeInt;
typedef Range<float> RangeFloat;