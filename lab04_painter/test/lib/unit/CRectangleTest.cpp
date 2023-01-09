#include "../../../src/lib/CRectangle.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

using ::testing::Eq;

class MockCanvas : public ICanvas
{
public:
	MOCK_METHOD(void, SetColor, (Color color), (override));
	MOCK_METHOD(void, Drawline, (const Point2D& from, const Point2D& to), (override));
	MOCK_METHOD(void, DrawEllipse, (const Point2D& from, int horizontalRadius, int verticalRadius), (override));
};

MATCHER_P(XAndYAreEqual, point, ""){ return (arg.x == point.x && arg.y == point.y); }

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