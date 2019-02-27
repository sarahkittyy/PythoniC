#pragma once

#include <algorithm>   //std::replace
#include <cctype>	  //std::tolower
#include <string>	  //std::string

/**
 * @file
 * @brief Python's str.replace() method. 
 * 
 */
namespace py
{
namespace string
{

/**
 * @brief Replace every instance of one character with another.
 * 
 * @param input The string to iterate over.
 * @param from The character to replace.
 * @param to The character to replace it with.
 * @param ignorecase Whether or not to ignore capital/lowercase letters.
 * 
 * @return std::string The replaced string.
 * 
 * @example Strings/Replace/Replace.cpp
 */
std::string replace(std::string input,
					char from,
					char to,
					bool ignorecase = false);

}
}