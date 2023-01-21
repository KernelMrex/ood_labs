#include "../../../src/lib/command/CSetTitleCommand.h"
#include "../document/MockDocument.cpp"
#include "../file/CPathMatchers.cpp"

#include <gtest/gtest.h>

TEST(CSetTitleCommandTest, Execution)
{
	auto mockDocument = std::make_shared<MockDocument>();
	EXPECT_CALL(*mockDocument, SetTitle("Testing title")).Times(1);

	CSetTitleCommand command(mockDocument, "Testing title");
	command.Execute();
}