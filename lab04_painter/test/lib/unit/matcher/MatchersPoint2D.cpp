#include <gmock/gmock.h>
#include <gtest/gtest.h>

MATCHER_P(XAndYAreEqual, point, "")
{
	return (arg.x == point.x && arg.y == point.y);
}