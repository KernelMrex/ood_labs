#include "../../../src/lib/file/CPath.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

TEST(CPathTest, ConstructAndProvidePath)
{
	CPath path("./test/1234.pass");
	ASSERT_EQ(path.String(), "./test/1234.pass");
}

TEST(CPathTest, ConstructWithDirnameAndFileNameAndProvidePath)
{
	CPath path1("./test", "1234.pass");
	ASSERT_EQ(path1.String(), "./test/1234.pass");

	CPath path2("./test/", "1234.pass");
	ASSERT_EQ(path2.String(), "./test/1234.pass");
}