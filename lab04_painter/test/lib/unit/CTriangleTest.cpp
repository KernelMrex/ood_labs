#include "../../../src/lib/CTriangle.h"
#include "mock/MockCanvas.cpp"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

using ::testing::Eq;

TEST(CTriangleTest, ConstructingTest)
{
	CTriangle triangle(Color::BLUE, { .x = 1, .y = 2 }, { .x = 7, .y = 8 }, { .x = 10, .y = 12 });

	MockCanvas canvas;

	ASSERT_EQ(triangle.GetColor(), Color::BLUE);
	ASSERT_THAT(triangle.GetVertex1(), XAndYAreEqual(Point2D{ .x = 1, .y = 2 }));
	ASSERT_THAT(triangle.GetVertex2(), XAndYAreEqual(Point2D{ .x = 7, .y = 8 }));
	ASSERT_THAT(triangle.GetVertex3(), XAndYAreEqual(Point2D{ .x = 10, .y = 12 }));

}

TEST(CTriangleTest, DrawTest)
{
	CTriangle triangle(Color::BLUE, { .x = 1, .y = 2 }, { .x = 7, .y = 8 }, { .x = 10, .y = 12 });

	MockCanvas canvas;
	EXPECT_CALL(canvas, SetColor(Eq(triangle.GetColor()))).Times(1);
	EXPECT_CALL(canvas, Drawline(XAndYAreEqual(Point2D{ .x = 1, .y = 2 }), XAndYAreEqual(Point2D{ .x = 7, .y = 8 }))).Times(1);
	EXPECT_CALL(canvas, Drawline(XAndYAreEqual(Point2D{ .x = 7, .y = 8 }), XAndYAreEqual(Point2D{ .x = 10, .y = 12 }))).Times(1);
	EXPECT_CALL(canvas, Drawline(XAndYAreEqual(Point2D{ .x = 10, .y = 12 }), XAndYAreEqual(Point2D{ .x = 1, .y = 2 }))).Times(1);

	triangle.Draw(canvas);
}