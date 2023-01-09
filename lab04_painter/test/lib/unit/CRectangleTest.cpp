#include "../../../src/lib/CRectangle.h"
#include "mock/MockCanvas.cpp"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

using ::testing::Eq;

TEST(CRectangleTest, ConstructingTest)
{
	CRectangle rect(Color::RED, { .x = 1, .y = 2 }, { .x = 7, .y = 8 });

	MockCanvas canvas;

	ASSERT_EQ(rect.GetColor(), Color::RED);
	ASSERT_THAT(rect.GetLeftTop(), XAndYAreEqual(Point2D{ .x = 1, .y = 2 }));
	ASSERT_THAT(rect.GetRightBottom(), XAndYAreEqual(Point2D{ .x = 7, .y = 8 }));
}

TEST(CRectangleTest, DrawTest)
{
	CRectangle rect(Color::RED, { .x = 1, .y = 2 }, { .x = 7, .y = 8 });

	MockCanvas canvas;
	EXPECT_CALL(canvas, SetColor(Eq(rect.GetColor()))).Times(1);
	EXPECT_CALL(canvas, Drawline(XAndYAreEqual(Point2D{ .x = 1, .y = 2 }), XAndYAreEqual(Point2D{ .x = 7, .y = 2 }))).Times(1);
	EXPECT_CALL(canvas, Drawline(XAndYAreEqual(Point2D{ .x = 7, .y = 8 }), XAndYAreEqual(Point2D{ .x = 1, .y = 8 }))).Times(1);
	EXPECT_CALL(canvas, Drawline(XAndYAreEqual(Point2D{ .x = 7, .y = 2 }), XAndYAreEqual(Point2D{ .x = 7, .y = 8 }))).Times(1);
	EXPECT_CALL(canvas, Drawline(XAndYAreEqual(Point2D{ .x = 1, .y = 8 }), XAndYAreEqual(Point2D{ .x = 1, .y = 2 }))).Times(1);

	rect.Draw(canvas);
}