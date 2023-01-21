#include "../../../src/lib/command/CInsertImageCommand.h"
#include "../document/MockDocument.cpp"
#include "../file/CPathMatchers.cpp"

#include <gtest/gtest.h>

TEST(CInsertImageCommandTest, Execution)
{
	auto mockDocument = std::make_shared<MockDocument>();
	EXPECT_CALL(*mockDocument, InsertImage(CPathEq(CPath("test.dat")), 400, 300, ::testing::Eq(1))).Times(1);

	CInsertImageCommand command(mockDocument, CPath("test.dat"), 400, 300, 1);
	command.Execute();
}