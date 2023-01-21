#ifndef LAB05_DOCUMENT_STRINGS_H
#define LAB05_DOCUMENT_STRINGS_H

#include <string>

static std::string Trim(const std::string& str, const std::string& whitespace = " \t")
{
	const auto strBegin = str.find_first_not_of(whitespace);
	if (strBegin == std::string::npos)
	{
		return "";
	}

	const auto strEnd = str.find_last_not_of(whitespace);
	const auto strRange = strEnd - strBegin + 1;

	return str.substr(strBegin, strRange);
}

#endif // LAB05_DOCUMENT_STRINGS_H
