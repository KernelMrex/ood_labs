#include "../../../src/lib/CRegularPolygon.h"
#include "mock/MockCanvas.cpp"
#include "matcher/MatchersPoint2D.cpp"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

using ::testing::Eq;

TEST(CRegularPolygonTest, ConstructingTest)
{
	CRegularPolygon polygon(Color::YELLOW, { { 1, 1 }, { 2, 4 }, { 5, 5 }, { 6, 3 }, { 1, 1 } });

	ASSERT_EQ(polygon.GetColor(), Color::YELLOW);
	ASSERT_EQ(polygon.GetVertexCount(), 5);
}

TEST(CRegularPolygonTest, DrawTest)
{
	CRegularPolygon polygon(Color::YELLOW, { { 1, 1 }, { 2, 4 }, { 5, 5 }, { 6, 3 }, { 4, 1 } });

	MockCanvas canvas;
	EXPECT_CALL(canvas, SetColor(Eq(polygon.GetColor()))).Times(1);
	EXPECT_CALL(canvas, Drawline(XAndYAreEqual(Point2D{ 1, 1 }), XAndYAreEqual(Point2D{ 2, 4 }))).Times(1);
	EXPECT_CALL(canvas, Drawline(XAndYAreEqual(Point2D{ 2, 4 }), XAndYAreEqual(Point2D{ 5, 5 }))).Times(1);
	EXPECT_CALL(canvas, Drawline(XAndYAreEqual(Point2D{ 5, 5 }), XAndYAreEqual(Point2D{ 6, 3 }))).Times(1);
	EXPECT_CALL(canvas, Drawline(XAndYAreEqual(Point2D{ 6, 3 }), XAndYAreEqual(Point2D{ 4, 1 }))).Times(1);
	EXPECT_CALL(canvas, Drawline(XAndYAreEqual(Point2D{ 4, 1 }), XAndYAreEqual(Point2D{ 1, 1 }))).Times(1);

	polygon.Draw(canvas);
}

TEST(CRegularPolygonTest, GetCenterOfGravity)
{
	CRegularPolygon polygon(Color::YELLOW, { { 1, 1 }, { 2, 4 }, { 5, 5 }, { 6, 3 }, { 4, 1 } });

	auto centerOfGravity = polygon.GetCenter();
	EXPECT_NEAR(centerOfGravity.x, 3.513, 0.001);
	EXPECT_NEAR(centerOfGravity.y, 2.795, 0.001);
}