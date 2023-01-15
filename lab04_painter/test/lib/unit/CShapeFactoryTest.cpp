#include "../../../src/lib/CShapeFactory.h"
#include "matcher/MatchersPoint2D.cpp"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

// Grammar: rectangle <double> <double> <double> <double> <string>
TEST(CShapeFactoryTest, RectangleCreationTest)
{
	CShapeFactory shapeFactory;

	ASSERT_NO_THROW({
		auto shape = shapeFactory.CreateShape("rectangle 1.0 2.0 7.0 81.12 red");

		auto pRect = dynamic_cast<CRectangle*>(shape.get());
		ASSERT_NE(pRect, nullptr);

		std::unique_ptr<CRectangle> rectangle(dynamic_cast<CRectangle*>(shape.release()));

		ASSERT_EQ(rectangle->GetColor(), Color::RED);
		ASSERT_THAT(rectangle->GetLeftTop(), XAndYAreEqual(Point2D{ 1.0, 2.0 }));
		ASSERT_THAT(rectangle->GetRightBottom(), XAndYAreEqual(Point2D{ 7.0, 81.12 }));
	});
}

// Grammar: polygon <double1> <double1> <doubleN> <doubleN> <string>
TEST(CShapeFactoryTest, PolygonCreationTest)
{
	CShapeFactory shapeFactory;

	ASSERT_NO_THROW({
		auto shape = shapeFactory.CreateShape("polygon 1.0 1.0 2.0 4.0 5.0 5.0 6.0 3.0 4.0 1.0 blue");

		auto pRect = dynamic_cast<CRegularPolygon*>(shape.get());
		ASSERT_NE(pRect, nullptr);

		std::unique_ptr<CRegularPolygon> polygon(dynamic_cast<CRegularPolygon*>(shape.release()));

		ASSERT_EQ(polygon->GetColor(), Color::BLUE);

		auto centerOfGravity = polygon->GetCenter();
		EXPECT_NEAR(centerOfGravity.x, 3.513, 0.001);
		EXPECT_NEAR(centerOfGravity.y, 2.795, 0.001);
	});
}

// Grammar: triangle <double1> <double1> <double2> <double2> <double2> <double2> <string>
TEST(CShapeFactoryTest, TriangleCreationTest)
{
	CShapeFactory shapeFactory;

	ASSERT_NO_THROW({
		auto shape = shapeFactory.CreateShape("triangle 1.0 2.0 7.0 8.0 10.0 12.0 pink");

		auto pRect = dynamic_cast<CTriangle*>(shape.get());
		ASSERT_NE(pRect, nullptr);

		std::unique_ptr<CTriangle> triangle(dynamic_cast<CTriangle*>(shape.release()));

		ASSERT_EQ(triangle->GetColor(), Color::PINK);

		ASSERT_THAT(triangle->GetVertex1(), XAndYAreEqual(Point2D{ .x = 1, .y = 2 }));
		ASSERT_THAT(triangle->GetVertex2(), XAndYAreEqual(Point2D{ .x = 7, .y = 8 }));
		ASSERT_THAT(triangle->GetVertex3(), XAndYAreEqual(Point2D{ .x = 10, .y = 12 }));
	});
}