#include "../../../src/lib/command/CHelpCommand.h"

#include <gtest/gtest.h>

TEST(CHelpCommandTest, Execution)
{
	std::ostringstream oss;

	CHelpCommand command(oss);
	command.Execute();

	std::string expected = "InsertParagraph [<position>|end] <text>\n"
						   "InsertImage [<position>|end] <width> <height> <path>\n"
						   "SetTitle <text>\n"
						   "List\n"
						   "DeleteItem <position>\n"
						   "Help\n"
						   "Save <path>\n";

	ASSERT_EQ(oss.str(), expected);
}