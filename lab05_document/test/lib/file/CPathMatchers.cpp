#include <gmock/gmock.h>
#include <gtest/gtest.h>

MATCHER_P(CPathEq, path, "")
{
	return (arg.String() == path.String());
}