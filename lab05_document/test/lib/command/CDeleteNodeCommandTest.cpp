#include "../../../src/lib/command/CDeleteNodeCommand.h"
#include "../document/MockDocument.cpp"
#include "../file/CPathMatchers.cpp"

#include <gtest/gtest.h>

TEST(CDeleteNodeCommandTest, Execution)
{
	auto mockDocument = std::make_shared<MockDocument>();
	EXPECT_CALL(*mockDocument, DeleteNode(::testing::Eq(4))).Times(1);

	CDeleteNodeCommand command(mockDocument, 4);
	command.Execute();
}