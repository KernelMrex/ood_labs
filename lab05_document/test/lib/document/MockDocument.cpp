#include "../../../src/lib/document/IDocument.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

class MockDocument : public IDocument
{
public:
	MOCK_METHOD(void, InsertParagraph, (const std::string& text, std::optional<std::size_t> position), (override));
	MOCK_METHOD(void, InsertImage, (const CPath& path, unsigned int width, unsigned int height, std::optional<std::size_t> position), (override));
	MOCK_METHOD(std::size_t, GetNodesCount, (), (override, const));
	MOCK_METHOD(std::shared_ptr<INode>, GetNode, (std::size_t index), (override, const));
	MOCK_METHOD(void, DeleteNode, (std::size_t index), (override));
	MOCK_METHOD(void, SetTitle, (const std::string& title), (override));
	MOCK_METHOD(std::string, GetTitle, (), (override, const));
	MOCK_METHOD(void, Save, (const CPath& path), (override, const));
};
