#include "../../../src/lib/command/CSaveCommand.h"
#include "../document/MockDocument.cpp"
#include "../file/CPathMatchers.cpp"

#include <gtest/gtest.h>

TEST(CSaveCommandTest, Execution)
{
	auto mockDocument = std::make_shared<MockDocument>();
	EXPECT_CALL(*mockDocument, Save(CPathEq(CPath("test/path.txt")))).Times(1);

	CSaveCommand command(mockDocument, CPath("test/path.txt"));
	command.Execute();
}