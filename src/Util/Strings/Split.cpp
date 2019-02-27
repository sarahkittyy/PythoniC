#include "PythoniC/Util/Strings/Split.hpp"

namespace py
{
namespace string
{

std::vector<std::string> split(std::string str, char delim)
{
	using std::string;
	using std::vector;
	//Create the return vector.
	vector<string> split_string;

	//Iterate through each character of the string.
	string current = "";   // Records characters up until the delimeter.
	for (auto &ch : str)
	{
		//If we reach the delimited, append & flush.
		if (ch == delim)
		{
			split_string.push_back(current);
			current.clear();
		}
		//Otherwise, keep appending characters.
		else
		{
			current.push_back(ch);
		}
	}
	//Append the last, dangling element.
	split_string.push_back(current);

	//Return the split string.
	return split_string;
}

}
}