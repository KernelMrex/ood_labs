#include <gtest/gtest.h>
#include <gmock/gmock.h>

MATCHER_P(PointsAreEqual, point, "")
{
	return (arg.x == point.x && arg.y == point.y);
}

MATCHER_P(ColorsAreEqual, color, "")
{
	return arg.red == color.red
		&& arg.green == color.green
		&& arg.blue == color.blue
		&& arg.alpha == color.alpha;
}
