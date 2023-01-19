#ifndef LAB05_DOCUMENT_RANDOM_H
#define LAB05_DOCUMENT_RANDOM_H

#include <string>

inline std::string RandomString(int length)
{
	std::string res(length, 0);
	for (char& re : res)
	{
		re = 'a' + (std::rand() % ('z' - 'a'));
	}
	return res;
}

#endif // LAB05_DOCUMENT_RANDOM_H
