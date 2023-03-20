#include <gtest/gtest.h>
#include "../../../../src/app/figure/CEllipse.h"
#include "../canvas/MockCanvas.cpp"
#include "../common/Matchers.cpp"

TEST(EllipseTest, MustOnlyFill)
{
	CEllipse ellipse({ 50, 51 }, 40, 41);
	ellipse.FillStyle(CFillStyle(254, 232, 16, 1.0));

	MockCanvas canvas;
	EXPECT_CALL(canvas, FillEllipse(PointsAreEqual(SPoint{50, 51}), 40, 41, ColorsAreEqual(SColor{254, 232, 16, 1.0})));
	EXPECT_CALL(canvas, DrawEllipse(::testing::_, ::testing::_, ::testing::_, ::testing::_, ::testing::_)).Times(0);

	ellipse.Draw(canvas);
}

TEST(EllipseTest, MustOnlyDraw)
{
	CEllipse ellipse({ 50, 51 }, 40, 41);
	ellipse.BorderStyle(CBorderStyle(235, 255, 44, 0.8, 24));

	MockCanvas canvas;
	EXPECT_CALL(canvas, FillEllipse(::testing::_, ::testing::_, ::testing::_, ::testing::_)).Times(0);
	EXPECT_CALL(canvas, DrawEllipse(PointsAreEqual(SPoint{50, 51}), 40, 41, ColorsAreEqual(SColor{235, 255, 44, 0.8}), 24));

	ellipse.Draw(canvas);
}

TEST(EllipseTest, MustDrawAndFillEllipse)
{
	CEllipse ellipse({ 50, 51 }, 40, 41);
	ellipse.FillStyle(CFillStyle(254, 232, 16, 1.0));
	ellipse.BorderStyle(CBorderStyle(235, 255, 44, 0.8, 24));

	MockCanvas canvas;
	EXPECT_CALL(canvas, DrawEllipse(PointsAreEqual(SPoint{50, 51}), 40, 41, ColorsAreEqual(SColor{235, 255, 44, 0.8}), 24));
	EXPECT_CALL(canvas, FillEllipse(PointsAreEqual(SPoint{50, 51}), 40, 41, ColorsAreEqual(SColor{254, 232, 16, 1.0})));

	ellipse.Draw(canvas);
}

TEST(EllipseTest, ResizingCircleTest)
{
	CEllipse ellipse({ 100, 100 }, 100, 100);
	ASSERT_THAT(ellipse.Frame()->leftTop, PointsAreEqual(SPoint{ 0, 0 }));
	ASSERT_THAT(ellipse.Frame()->rightBottom, PointsAreEqual(SPoint{ 200, 200 }));

	ellipse.Resize(250, 250);
	ASSERT_TRUE(ellipse.Frame().has_value());
	ASSERT_THAT(ellipse.Frame()->leftTop, PointsAreEqual(SPoint{ 0, 0 }));
	ASSERT_THAT(ellipse.Frame()->rightBottom, PointsAreEqual(SPoint{ 250, 250 }));
}

TEST(EllipseTest, ResizingEllipseTest)
{
	CEllipse ellipse({ 100, 200 }, 200, 100);
	ASSERT_THAT(ellipse.Frame()->leftTop, PointsAreEqual(SPoint{ 0, 0 }));
	ASSERT_THAT(ellipse.Frame()->rightBottom, PointsAreEqual(SPoint{ 200, 400 }));

	ellipse.Resize(200, 600);
	ASSERT_TRUE(ellipse.Frame().has_value());
	ASSERT_THAT(ellipse.Frame()->leftTop, PointsAreEqual(SPoint{ 0, 0 }));
	ASSERT_THAT(ellipse.Frame()->rightBottom, PointsAreEqual(SPoint{ 200, 600 }));
}