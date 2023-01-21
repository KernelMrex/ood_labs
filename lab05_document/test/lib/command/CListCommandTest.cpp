#include "../../../src/lib/command/CListCommand.h"
#include "../document/MockDocument.cpp"
#include "../document/node/MockNode.cpp"
#include "../file/CPathMatchers.cpp"

#include <gtest/gtest.h>
#include <sstream>

using ::testing::ByMove;
using ::testing::Return;

TEST(CListCommandTest, Execution)
{
	auto mockNode1 = std::make_shared<MockNode>();
	EXPECT_CALL(*mockNode1, Render(::testing::_)).Times(1);
	auto mockNode2 = std::make_shared<MockNode>();
	EXPECT_CALL(*mockNode2, Render(::testing::_)).Times(1);

	auto mockDocument = std::make_shared<MockDocument>();
	EXPECT_CALL(*mockDocument, GetTitle()).WillOnce(Return("Testing title"));
	EXPECT_CALL(*mockDocument, GetNodesCount()).WillRepeatedly(Return(2));
	EXPECT_CALL(*mockDocument, GetNode(0)).WillOnce(Return(mockNode1));
	EXPECT_CALL(*mockDocument, GetNode(1)).WillOnce(Return(mockNode2));

	std::ostringstream oss;

	CListCommand command(mockDocument, oss);
	command.Execute();

	ASSERT_EQ(oss.str(), "Title: Testing title\n\n\n");
}