#include "../../../src/lib/command/CDocumentCommandFactory.h"
#include "../document/MockDocument.cpp"
#include "../file/CPathMatchers.cpp"

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

TEST(CDocumentCommandFactoryTest, CreateInsertImageCommandTestWithEndPosition)
{
	auto mockDoc = std::make_shared<MockDocument>();
	EXPECT_CALL(*mockDoc, InsertImage(CPathEq(CPath("test.dat")), 400, 300, ::testing::Eq(std::nullopt))).Times(1);

	CDocumentCommandFactory commandFactory(mockDoc);

	std::string commandDescription = "InsertImage end 400 300 test.dat";

	auto command = commandFactory.CreateCommand(commandDescription);
	auto pInsertImageCommand = dynamic_cast<CInsertImageCommand*>(command.get());
	ASSERT_NE(pInsertImageCommand, nullptr);
	pInsertImageCommand->Execute();
}

TEST(CDocumentCommandFactoryTest, CreateInsertImageCommandTestWithDefinedPosition)
{
	auto mockDoc = std::make_shared<MockDocument>();
	EXPECT_CALL(*mockDoc, InsertImage(CPathEq(CPath("test.dat")), 400, 300, ::testing::Eq(4))).Times(1);

	CDocumentCommandFactory commandFactory(mockDoc);

	std::string commandDescription = "InsertImage 4 400 300 test.dat";

	auto command = commandFactory.CreateCommand(commandDescription);
	auto pInsertImageCommand = dynamic_cast<CInsertImageCommand*>(command.get());
	ASSERT_NE(pInsertImageCommand, nullptr);
	pInsertImageCommand->Execute();
}

TEST(CDocumentCommandFactoryTest, CreateDeleteNodeCommand)
{
	auto mockDoc = std::make_shared<MockDocument>();
	EXPECT_CALL(*mockDoc, DeleteNode(::testing::Eq(4))).Times(1);

	CDocumentCommandFactory commandFactory(mockDoc);

	std::string commandDescription = "DeleteNode 4";

	auto command = commandFactory.CreateCommand(commandDescription);
	auto pDeleteNodeCommand = dynamic_cast<CDeleteNodeCommand*>(command.get());
	ASSERT_NE(pDeleteNodeCommand, nullptr);
	pDeleteNodeCommand->Execute();
}

TEST(CDocumentCommandFactoryTest, CreateSaveCommand)
{
	auto mockDoc = std::make_shared<MockDocument>();
	EXPECT_CALL(*mockDoc, Save(CPathEq(CPath("test/path.txt")))).Times(1);

	CDocumentCommandFactory commandFactory(mockDoc);

	std::string commandDescription = "Save test/path.txt";

	auto command = commandFactory.CreateCommand(commandDescription);
	auto pSaveCommand = dynamic_cast<CSaveCommand*>(command.get());
	ASSERT_NE(pSaveCommand, nullptr);
	pSaveCommand->Execute();
}