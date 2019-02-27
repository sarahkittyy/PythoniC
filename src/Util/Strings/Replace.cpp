#include "PythoniC/Util/Strings/Replace.hpp"

namespace py
{
namespace string
{

std::string replace(std::string input,
					char from,
					char to,
					bool ignorecase)
{
	//Declare the return string...
	std::string return_string = input;

	//Replace the string.
	std::replace_if(return_string.begin(),
					return_string.end(),
					[=](char c) {
						if (ignorecase)
						{
							return std::tolower(c) == std::tolower(from);
						}
						else
						{
							return c == from;
						}
					},
					to);

	//Return the string.
	return return_string;
}

}
}