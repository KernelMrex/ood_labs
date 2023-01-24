#include "../../../src/lib/command/CDocumentCommandFactory.h"
#include "../document/MockDocument.cpp"
#include "../document/node/MockNode.cpp"
#include "../file/CPathMatchers.cpp"
#include "MockCommandHistory.cpp"

#include <gtest/gtest.h>

TEST(CDocumentCommandFactoryTest, CreateInsertParagraphCommandTestWithEndPosition)
{
	std::ostream nullStream(nullptr);

	auto mockDoc = std::make_shared<MockDocument>();
	EXPECT_CALL(*mockDoc, InsertParagraph("This is paragraph text", ::testing::Eq(std::nullopt))).Times(1);

	CDocumentCommandFactory commandFactory(
		mockDoc,
		nullStream,
		std::make_shared<MockCommandHistory>(),
		std::make_shared<MockCommandHistory>()
	);

	std::string commandDescription = "InsertParagraph end This is paragraph text";

	auto command = commandFactory.CreateCommand(commandDescription);
	auto pDecorator = dynamic_cast<CSaveToHistoryCommandDecorator*>(command.get());
	ASSERT_NE(pDecorator, nullptr);
	auto pInsertParagraphCommand = dynamic_cast<CInsertParagraphCommand*>(pDecorator->GetWrappee().get());
	ASSERT_NE(pInsertParagraphCommand, nullptr);
	pInsertParagraphCommand->Execute();
}

TEST(CDocumentCommandFactoryTest, CreateInsertParagraphCommandTestWithDefinedPosition)
{
	std::ostream nullStream(nullptr);

	auto mockDoc = std::make_shared<MockDocument>();
	EXPECT_CALL(*mockDoc, InsertParagraph("This is paragraph text", ::testing::Eq(4))).Times(1);

	CDocumentCommandFactory commandFactory(
		mockDoc,
		nullStream,
		std::make_shared<MockCommandHistory>(),
		std::make_shared<MockCommandHistory>()
	);

	std::string commandDescription = "InsertParagraph 4 This is paragraph text";

	auto command = commandFactory.CreateCommand(commandDescription);
	auto pDecorator = dynamic_cast<CSaveToHistoryCommandDecorator*>(command.get());
	ASSERT_NE(pDecorator, nullptr);
	auto pInsertParagraphCommand = dynamic_cast<CInsertParagraphCommand*>(pDecorator->GetWrappee().get());
	ASSERT_NE(pInsertParagraphCommand, nullptr);
	pInsertParagraphCommand->Execute();
}

TEST(CDocumentCommandFactoryTest, CreateInsertImageCommandTestWithEndPosition)
{
	std::ostream nullStream(nullptr);

	auto mockDoc = std::make_shared<MockDocument>();
	EXPECT_CALL(*mockDoc, InsertImage(CPathEq(CPath("test.dat")), 400, 300, ::testing::Eq(std::nullopt))).Times(1);

	CDocumentCommandFactory commandFactory(
		mockDoc,
		nullStream,
		std::make_shared<MockCommandHistory>(),
		std::make_shared<MockCommandHistory>()
	);

	std::string commandDescription = "InsertImage end 400 300 test.dat";

	auto command = commandFactory.CreateCommand(commandDescription);
	auto pDecorator = dynamic_cast<CSaveToHistoryCommandDecorator*>(command.get());
	ASSERT_NE(pDecorator, nullptr);
	auto pInsertImageCommand = dynamic_cast<CInsertImageCommand*>(pDecorator->GetWrappee().get());
	ASSERT_NE(pInsertImageCommand, nullptr);
	pInsertImageCommand->Execute();
}

TEST(CDocumentCommandFactoryTest, CreateInsertImageCommandTestWithDefinedPosition)
{
	std::ostream nullStream(nullptr);

	auto mockDoc = std::make_shared<MockDocument>();
	EXPECT_CALL(*mockDoc, InsertImage(CPathEq(CPath("test.dat")), 400, 300, ::testing::Eq(4))).Times(1);

	CDocumentCommandFactory commandFactory(
		mockDoc,
		nullStream,
		std::make_shared<MockCommandHistory>(),
		std::make_shared<MockCommandHistory>()
	);

	std::string commandDescription = "InsertImage 4 400 300 test.dat";

	auto command = commandFactory.CreateCommand(commandDescription);
	auto pDecorator = dynamic_cast<CSaveToHistoryCommandDecorator*>(command.get());
	ASSERT_NE(pDecorator, nullptr);
	auto pInsertImageCommand = dynamic_cast<CInsertImageCommand*>(pDecorator->GetWrappee().get());
	ASSERT_NE(pInsertImageCommand, nullptr);
	pInsertImageCommand->Execute();
}

TEST(CDocumentCommandFactoryTest, CreateDeleteNodeCommand)
{
	std::ostream nullStream(nullptr);

	auto mockDoc = std::make_shared<MockDocument>();
	EXPECT_CALL(*mockDoc, DeleteNode(::testing::Eq(4))).Times(1);

	CDocumentCommandFactory commandFactory(
		mockDoc,
		nullStream,
		std::make_shared<MockCommandHistory>(),
		std::make_shared<MockCommandHistory>()
	);

	std::string commandDescription = "DeleteNode 4";

	auto command = commandFactory.CreateCommand(commandDescription);
	auto pDecorator = dynamic_cast<CSaveToHistoryCommandDecorator*>(command.get());
	ASSERT_NE(pDecorator, nullptr);
	auto pDeleteNodeCommand = dynamic_cast<CDeleteNodeCommand*>(pDecorator->GetWrappee().get());
	ASSERT_NE(pDeleteNodeCommand, nullptr);
	pDeleteNodeCommand->Execute();
}

TEST(CDocumentCommandFactoryTest, CreateSaveCommand)
{
	std::ostream nullStream(nullptr);

	auto mockDoc = std::make_shared<MockDocument>();
	EXPECT_CALL(*mockDoc, Save(CPathEq(CPath("test/path.txt")))).Times(1);

	CDocumentCommandFactory commandFactory(
		mockDoc,
		nullStream,
		std::make_shared<MockCommandHistory>(),
		std::make_shared<MockCommandHistory>()
	);

	std::string commandDescription = "Save test/path.txt";

	auto command = commandFactory.CreateCommand(commandDescription);
	auto pSaveCommand = dynamic_cast<CSaveCommand*>(command.get());
	ASSERT_NE(pSaveCommand, nullptr);
	pSaveCommand->Execute();
}

TEST(CDocumentCommandFactoryTest, CreateSetTitleCommand)
{
	std::ostream nullStream(nullptr);

	auto mockDoc = std::make_shared<MockDocument>();
	EXPECT_CALL(*mockDoc, SetTitle("New testing title!")).Times(1);

	CDocumentCommandFactory commandFactory(
		mockDoc,
		nullStream,
		std::make_shared<MockCommandHistory>(),
		std::make_shared<MockCommandHistory>()
	);

	std::string commandDescription = "SetTitle New testing title!";

	auto command = commandFactory.CreateCommand(commandDescription);
	auto pDecorator = dynamic_cast<CSaveToHistoryCommandDecorator*>(command.get());
	ASSERT_NE(pDecorator, nullptr);
	auto pSetTitleCommand = dynamic_cast<CSetTitleCommand*>(pDecorator->GetWrappee().get());
	ASSERT_NE(pSetTitleCommand, nullptr);
	pSetTitleCommand->Execute();
}

TEST(CDocumentCommandFactoryTest, CreateListCommand)
{
	std::ostringstream oss;

	auto mockNode = std::make_shared<MockNode>();
	EXPECT_CALL(*mockNode, Render(::testing::_)).Times(2);

	auto mockDoc = std::make_shared<MockDocument>();
	EXPECT_CALL(*mockDoc, GetTitle()).Times(1).WillOnce(::testing::Return("Test"));
	EXPECT_CALL(*mockDoc, GetNodesCount()).WillRepeatedly(::testing::Return(2));
	EXPECT_CALL(*mockDoc, GetNode(::testing::_)).WillRepeatedly(::testing::Return(mockNode));

	CDocumentCommandFactory commandFactory(
		mockDoc,
		oss,
		std::make_shared<MockCommandHistory>(),
		std::make_shared<MockCommandHistory>()
	);

	auto command = commandFactory.CreateCommand("List");
	auto pListCommand = dynamic_cast<CListCommand*>(command.get());
	ASSERT_NE(pListCommand, nullptr);
	pListCommand->Execute();
}

TEST(CDocumentCommandFactoryTest, CreateHelpCommand)
{
	std::ostringstream oss;
	auto mockDoc = std::make_shared<MockDocument>();
	CDocumentCommandFactory commandFactory(
		mockDoc,
		oss,
		std::make_shared<MockCommandHistory>(),
		std::make_shared<MockCommandHistory>()
	);

	auto command = commandFactory.CreateCommand("Help");
	auto pHelpCommand = dynamic_cast<CHelpCommand*>(command.get());
	ASSERT_NE(pHelpCommand, nullptr);
}

TEST(CDocumentCommandFactoryTest, CreateUndoCommand)
{
	std::ostream nullStream(nullptr);
	auto mockDoc = std::make_shared<MockDocument>();
	CDocumentCommandFactory commandFactory(
		mockDoc,
		nullStream,
		std::make_shared<MockCommandHistory>(),
		std::make_shared<MockCommandHistory>()
	);

	auto command = commandFactory.CreateCommand("Undo");
	auto pUndoCommand = dynamic_cast<CUndoCommand*>(command.get());
	ASSERT_NE(pUndoCommand, nullptr);
}