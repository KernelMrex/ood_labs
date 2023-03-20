#include <gtest/gtest.h>
#include "../../../../src/app/figure/CRectangle.h"
#include "../canvas/MockCanvas.cpp"
#include "../common/Matchers.cpp"


TEST(RectangleTest, MustOnlyFill)
{
	using ::testing::ElementsAre;
	using ::testing::_;

	CRectangle rectangle({ 50, 51 }, 40, 41);
	rectangle.FillStyle(CFillStyle(254, 232, 16, 1.0));

	MockCanvas canvas;
	EXPECT_CALL(canvas, FillPolygon(ElementsAre(
		PointsAreEqual(SPoint{ 50, 51 }),
		PointsAreEqual(SPoint{ 50 + 40, 51 }),
		PointsAreEqual(SPoint{ 50 + 40, 51 + 41 }),
		PointsAreEqual(SPoint{ 50, 51 + 41 })
	), ColorsAreEqual(SColor{254, 232, 16, 1.0}))).Times(1);
	EXPECT_CALL(canvas, DrawLine(_, _, _, _)).Times(0);

	rectangle.Draw(canvas);
}

TEST(RectangleTest, MustOnlyDrawLines)
{
	using ::testing::_;

	CRectangle rectangle({ 50, 51 }, 40, 41);
	rectangle.BorderStyle(CBorderStyle(235, 255, 44, 0.8, 24));

	MockCanvas canvas;
	EXPECT_CALL(canvas, FillPolygon(_, _)).Times(0);
	EXPECT_CALL(canvas, DrawLine(PointsAreEqual(SPoint{ 50, 51 }), PointsAreEqual(SPoint{ 50 + 40, 51 }), ColorsAreEqual(SColor{235, 255, 44, 0.8}), 24)).Times(1);
	EXPECT_CALL(canvas, DrawLine(PointsAreEqual(SPoint{ 50 + 40, 51 }), PointsAreEqual(SPoint{ 50 + 40, 51 + 41 }), ColorsAreEqual(SColor{235, 255, 44, 0.8}), 24)).Times(1);
	EXPECT_CALL(canvas, DrawLine(PointsAreEqual(SPoint{ 50 + 40, 51 + 41 }), PointsAreEqual(SPoint{ 50, 51 + 41 }), ColorsAreEqual(SColor{235, 255, 44, 0.8}), 24)).Times(1);
	EXPECT_CALL(canvas, DrawLine(PointsAreEqual(SPoint{ 50, 51 + 41 }), PointsAreEqual(SPoint{ 50, 51 }), ColorsAreEqual(SColor{235, 255, 44, 0.8}), 24)).Times(1);

	rectangle.Draw(canvas);
}

TEST(RectangleTest, MustDrawAndFillRectangle)
{
	using ::testing::ElementsAre;
	using ::testing::_;

	CRectangle rectangle({ 50, 51 }, 40, 41);
	rectangle.FillStyle(CFillStyle(254, 232, 16, 1.0));
	rectangle.BorderStyle(CBorderStyle(235, 255, 44, 0.8, 24));

	MockCanvas canvas;
	EXPECT_CALL(canvas, FillPolygon(ElementsAre(
		PointsAreEqual(SPoint{ 50, 51 }),
		PointsAreEqual(SPoint{ 50 + 40, 51 }),
		PointsAreEqual(SPoint{ 50 + 40, 51 + 41 }),
		PointsAreEqual(SPoint{ 50, 51 + 41 })
	), ColorsAreEqual(SColor{254, 232, 16, 1.0}))).Times(1);
	EXPECT_CALL(canvas, DrawLine(PointsAreEqual(SPoint{ 50, 51 }), PointsAreEqual(SPoint{ 50 + 40, 51 }), ColorsAreEqual(SColor{235, 255, 44, 0.8}), 24)).Times(1);
	EXPECT_CALL(canvas, DrawLine(PointsAreEqual(SPoint{ 50 + 40, 51 }), PointsAreEqual(SPoint{ 50 + 40, 51 + 41 }), ColorsAreEqual(SColor{235, 255, 44, 0.8}), 24)).Times(1);
	EXPECT_CALL(canvas, DrawLine(PointsAreEqual(SPoint{ 50 + 40, 51 + 41 }), PointsAreEqual(SPoint{ 50, 51 + 41 }), ColorsAreEqual(SColor{235, 255, 44, 0.8}), 24)).Times(1);
	EXPECT_CALL(canvas, DrawLine(PointsAreEqual(SPoint{ 50, 51 + 41 }), PointsAreEqual(SPoint{ 50, 51 }), ColorsAreEqual(SColor{235, 255, 44, 0.8}), 24)).Times(1);

	rectangle.Draw(canvas);
}