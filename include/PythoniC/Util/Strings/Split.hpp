#pragma once

#include <string>
#include <vector>

/**
 * @file
 * @brief Python's str.split() method.
 * 
 */
namespace py
{
namespace string
{

/**
 * @brief Python's string.split(delim) method. Splits a string at each delim instance.
 * Ex: delim = ',' - Splitting "Hello , World" would return ["Hello ", "World"]
 * 
 * @param str The string to split. 
 * @param delim The delimiter between items.
 * @return std::vector<std::string> A vector of split string items.
 * 
 * @example Strings/Split/Split.cpp
 */
std::vector<std::string> split(std::string str, char delim);

}
}