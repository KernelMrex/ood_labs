#include "../../../src/lib/utils/Strings.h"

#include <gtest/gtest.h>

TEST(TrimTest, TrimMustReduceEmptySpaces)
{
	ASSERT_EQ(Trim("    sekrj   \tgh  sk \tjgr\t       "), "sekrj   \tgh  sk \tjgr");
}