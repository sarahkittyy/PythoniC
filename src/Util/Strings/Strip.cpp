#include "PythoniC/Util/Strings/Strip.hpp"

namespace py
{
namespace string
{

std::string lstrip(std::string input)
{
	using std::regex;
	using std::regex_replace;

	//Capture all text after leading whitespace in a capture group.
	regex leftwsmatch(R"(^\s*(.*)$)");

	//Return the replaced string.
	return regex_replace(input, leftwsmatch, "$1");
}

std::string rstrip(std::string input)
{
	using std::regex;
	using std::regex_replace;

	//Capture all text before trailing whitespace in a capture group.
	regex rightwsmatch(R"(^(.*?)\s*$)");

	//Return the replaced string.
	return regex_replace(input, rightwsmatch, "$1");
}

std::string strip(std::string input)
{
	//...
	return lstrip(rstrip(input));
}

}
}