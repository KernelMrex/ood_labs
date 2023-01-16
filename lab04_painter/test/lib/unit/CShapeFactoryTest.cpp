#include "../../../src/lib/CShapeFactory.h"
#include "matcher/MatchersPoint2D.cpp"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

// Grammar: rectangle <color> <p1.x> <p1.y> <p2.x> <p2.y>
TEST(CShapeFactoryTest, RectangleCreationTest)
{
	CShapeFactory shapeFactory;

	ASSERT_NO_THROW({
		auto shape = shapeFactory.CreateShape("rectangle red 1.0 2.0 7.0 81.12");

		auto pRect = dynamic_cast<CRectangle*>(shape.get());
		ASSERT_NE(pRect, nullptr);

		std::unique_ptr<CRectangle> rectangle(dynamic_cast<CRectangle*>(shape.release()));

		ASSERT_EQ(rectangle->GetColor(), Color::RED);
		ASSERT_THAT(rectangle->GetLeftTop(), XAndYAreEqual(Point2D{ 1.0, 2.0 }));
		ASSERT_THAT(rectangle->GetRightBottom(), XAndYAreEqual(Point2D{ 7.0, 81.12 }));
	});
}

// Grammar: polygon <color> <p1.x> <p1.y> ... <pN.x> <pN.y>
TEST(CShapeFactoryTest, PolygonCreationTest)
{
	CShapeFactory shapeFactory;

	ASSERT_NO_THROW({
		auto shape = shapeFactory.CreateShape("polygon blue 1.0 1.0 2.0 4.0 5.0 5.0 6.0 3.0 4.0 1.0");

		auto pRect = dynamic_cast<CRegularPolygon*>(shape.get());
		ASSERT_NE(pRect, nullptr);

		std::unique_ptr<CRegularPolygon> polygon(dynamic_cast<CRegularPolygon*>(shape.release()));

		ASSERT_EQ(polygon->GetColor(), Color::BLUE);

		auto centerOfGravity = polygon->GetCenter();
		EXPECT_NEAR(centerOfGravity.x, 3.513, 0.001);
		EXPECT_NEAR(centerOfGravity.y, 2.795, 0.001);
	});
}

// Grammar: triangle <color> <p1.x> <p1.y> <p2.x> <p2.y> <p3.x> <p3.y>
TEST(CShapeFactoryTest, TriangleCreationTest)
{
	CShapeFactory shapeFactory;

	ASSERT_NO_THROW({
		auto shape = shapeFactory.CreateShape("triangle pink 1.0 2.0 7.0 8.0 10.0 12.0");

		auto pRect = dynamic_cast<CTriangle*>(shape.get());
		ASSERT_NE(pRect, nullptr);

		std::unique_ptr<CTriangle> triangle(dynamic_cast<CTriangle*>(shape.release()));

		ASSERT_EQ(triangle->GetColor(), Color::PINK);

		ASSERT_THAT(triangle->GetVertex1(), XAndYAreEqual(Point2D{ .x = 1, .y = 2 }));
		ASSERT_THAT(triangle->GetVertex2(), XAndYAreEqual(Point2D{ .x = 7, .y = 8 }));
		ASSERT_THAT(triangle->GetVertex3(), XAndYAreEqual(Point2D{ .x = 10, .y = 12 }));
	});
}

// Grammar: ellipse <color> <center.x> <center.y> <vr> <hr>
TEST(CShapeFactoryTest, EllipseCreationTest)
{
	CShapeFactory shapeFactory;

	ASSERT_NO_THROW({
		auto shape = shapeFactory.CreateShape("ellipse green 1.0 2.0 7.0 8.0");

		auto pRect = dynamic_cast<CEllipse*>(shape.get());
		ASSERT_NE(pRect, nullptr);

		std::unique_ptr<CEllipse> ellipse(dynamic_cast<CEllipse*>(shape.release()));

		ASSERT_EQ(ellipse->GetColor(), Color::GREEN);

		ASSERT_THAT(ellipse->GetCenter(), XAndYAreEqual(Point2D{ .x = 1, .y = 2 }));
		ASSERT_EQ(ellipse->GetVerticalRadius(), 7.0);
		ASSERT_EQ(ellipse->GetHorizontalRadius(), 8.0);
	});
}