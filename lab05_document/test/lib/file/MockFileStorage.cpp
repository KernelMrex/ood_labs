#include "../../../src/lib/file/IFileStorage.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

class MockFileStorage : public IFileStorage
{
public:
	MOCK_METHOD(std::optional<CPath>, SaveFile, (const CPath& fileToStorePath, const std::string& storedFileName), (override));
};