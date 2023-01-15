#include "../../../src/lib/CEllipse.h"
#include "mock/MockCanvas.cpp"
#include "matcher/MatchersPoint2D.cpp"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

using ::testing::Eq;

TEST(CEllipseTest, ConstructingTest)
{
	CEllipse ellipse(Color::PINK, { .x = 1.0, .y = 2.5 }, 2.0, 0.5);

	MockCanvas canvas;
	ASSERT_EQ(ellipse.GetColor(), Color::PINK);

	ASSERT_THAT(ellipse.GetCenter(), XAndYAreEqual(Point2D{ .x = 1.0, .y = 2.5 }));
	ASSERT_EQ(ellipse.GetVerticalRadius(), 2.0);
	ASSERT_EQ(ellipse.GetHorizontalRadius(), 0.5);
}

TEST(CEllipseTest, DrawTest)
{
	CEllipse ellipse(Color::PINK, { .x = 1.0, .y = 2.5 }, 2.0, 0.5);

	MockCanvas canvas;
	EXPECT_CALL(canvas, SetColor(Eq(Color::PINK))).Times(1);
	EXPECT_CALL(canvas, DrawEllipse(XAndYAreEqual(Point2D{ .x = 1, .y = 2.5 }), Eq(2.0), Eq(0.5))).Times(1);

	ellipse.Draw(canvas);
}