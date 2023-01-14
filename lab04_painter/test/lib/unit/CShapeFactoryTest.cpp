#include "../../../src/lib/CShapeFactory.h"
#include "matcher/MatchersPoint2D.cpp"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

// Grammar: rectangle <double> <double> <double> <double> <string>
TEST(CShapeFactoryTest, RectangleCreationTest)
{
	CShapeFactory shapeFactory;

	ASSERT_NO_THROW({
		auto shape = shapeFactory.CreateShape("rectangle 1.0 2.0 7.0 8.0 red");

		auto pRect = dynamic_cast<CRectangle*>(shape.get());
		ASSERT_NE(pRect, nullptr);

		std::unique_ptr<CRectangle> rectangle(dynamic_cast<CRectangle*>(shape.release()));

		ASSERT_THAT(rectangle->GetLeftTop(), XAndYAreEqual(Point2D{1.0, 2.0}));
		ASSERT_THAT(rectangle->GetRightBottom(), XAndYAreEqual(Point2D{7.0, 8.0}));
	});
}