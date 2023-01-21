#ifndef LAB05_DOCUMENT_CFILESYSTEMFILESTORAGE_H
#define LAB05_DOCUMENT_CFILESYSTEMFILESTORAGE_H

#include "IFileStorage.h"
#include <filesystem>
#include <fstream>

class CFileSystemFileStorage : public IFileStorage
{
public:
	explicit CFileSystemFileStorage(CPath dirPath)
		: m_dirPath(std::move(dirPath))
	{
		if (!std::filesystem::exists(m_dirPath.String()) && !std::filesystem::create_directory(m_dirPath.String()))
		{
			throw std::runtime_error("could not create dir at given path");
		}

		if (!std::filesystem::is_directory(m_dirPath.String()))
		{
			throw std::invalid_argument("given path to dir is not a dir");
		}
	}

	std::optional<CPath> SaveFile(const CPath& filePath, const std::string& storedFileName) override
	{
		try
		{
			CPath storedFilePath(m_dirPath.String(), storedFileName);
			std::filesystem::copy(filePath.String(), storedFilePath.String());
			return storedFilePath;
		}
		catch (std::filesystem::filesystem_error&)
		{
			return std::nullopt;
		}
	}

private:
	CPath m_dirPath;
};

#endif // LAB05_DOCUMENT_CFILESYSTEMFILESTORAGE_H
