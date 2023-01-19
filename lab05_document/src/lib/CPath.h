#ifndef LAB05_DOCUMENT_CPATH_H
#define LAB05_DOCUMENT_CPATH_H

#include <string>
#include <utility>

class CPath
{
public:
	explicit CPath(std::string str)
		: m_path(std::move(str))
	{
	}

	[[nodiscard]]
	std::string String() const
	{
		return m_path;
	}

private:
	std::string m_path;
};

#endif // LAB05_DOCUMENT_CPATH_H
