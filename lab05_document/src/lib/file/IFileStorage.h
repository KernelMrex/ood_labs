#ifndef LAB05_DOCUMENT_IFILESTORAGE_H
#define LAB05_DOCUMENT_IFILESTORAGE_H

#include "CPath.h"
#include <optional>

class IFileStorage
{
public:
	virtual std::optional<CPath> SaveFile(const CPath& fileToStorePath, const std::string& storedFileName) = 0;

	virtual ~IFileStorage() = default;
};

#endif // LAB05_DOCUMENT_IFILESTORAGE_H
