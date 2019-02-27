#pragma once

#include <regex>	//std::regex_replace, std::regex
#include <string>   //std::string

namespace py
{
namespace string
{

/**
 * @brief Strips all leading whitepsace off a string.
 * 
 * @param input The string to strip.
 * @return std::string The stripped string.
 * 
 * @example Strings/Strip/Strip.cpp
 */
std::string lstrip(std::string input);

/**
 * @brief Strips all trailing whitespace.
 * 
 * @param input The string to strip.
 * @return std::string The stripped string.
 * 
 * @example Strings/Strip/Strip.cpp
 */
std::string rstrip(std::string input);

/**
 * @brief Strips all leading and trailing whitespace.
 * 
 * @param input The string to strip.
 * @return std::string The stripped string.
 * 
 * @example Strings/Strip/Strip.cpp
 */
std::string strip(std::string input);

}
}