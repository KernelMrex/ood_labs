#include "../../../src/lib/command/CDocumentCommandFactory.h"
#include "../document/MockDocument.cpp"

#include <gtest/gtest.h>

TEST(CDocumentCommandFactoryTest, CreateInsertParagraphCommandTestWithEndPosition)
{
	auto mockDoc = std::make_shared<MockDocument>();
	EXPECT_CALL(*mockDoc, InsertParagraph("This is paragraph text", ::testing::Eq(std::nullopt))).Times(1);

	CDocumentCommandFactory commandFactory(mockDoc);

	std::string commandDescription = "InsertParagraph end This is paragraph text";

	auto command = commandFactory.CreateCommand(commandDescription);
	auto pInsertParagraphCommand = dynamic_cast<CInsertParagraphCommand*>(command.get());
	ASSERT_NE(pInsertParagraphCommand, nullptr);
	pInsertParagraphCommand->Execute();
}

TEST(CDocumentCommandFactoryTest, CreateInsertParagraphCommandTestWithDefinedPosition)
{
	auto mockDoc = std::make_shared<MockDocument>();
	EXPECT_CALL(*mockDoc, InsertParagraph("This is paragraph text", ::testing::Eq(4))).Times(1);

	CDocumentCommandFactory commandFactory(mockDoc);

	std::string commandDescription = "InsertParagraph 4 This is paragraph text";

	auto command = commandFactory.CreateCommand(commandDescription);
	auto pInsertParagraphCommand = dynamic_cast<CInsertParagraphCommand*>(command.get());
	ASSERT_NE(pInsertParagraphCommand, nullptr);
	pInsertParagraphCommand->Execute();
}