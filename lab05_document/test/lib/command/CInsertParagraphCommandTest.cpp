#include "../../../src/lib/command/CInsertParagraphCommand.h"
#include "../document/MockDocument.cpp"

#include <gtest/gtest.h>

TEST(CInsertParagraphCommandTest, Execution)
{
	auto mockDocument = std::make_shared<MockDocument>();
	EXPECT_CALL(*mockDocument, InsertParagraph("Testing paragraph", ::testing::Eq(1))).Times(1);

	CInsertParagraphCommand command(mockDocument, "Testing paragraph", 1);
	command.Execute();
}