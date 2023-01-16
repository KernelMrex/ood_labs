#include "../../../src/lib/CPainter.h"
#include "mock/MockShape.cpp"
#include "mock/MockCanvas.cpp"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

using ::testing::Return;
using ::testing::ByMove;
using ::testing::NiceMock;

TEST(CPainterTest, EachFigureMustBeDrawnTest)
{
	MockCanvas canvas;

	auto shape1 = std::make_shared<NiceMock<MockShape>>();
	EXPECT_CALL(*shape1, Draw(::testing::_)).Times(1);
	auto shape2 = std::make_shared<NiceMock<MockShape>>();
	EXPECT_CALL(*shape2, Draw(::testing::_)).Times(1);

	std::vector<std::shared_ptr<CShape>> shapes;
	shapes.push_back(shape1);
	shapes.push_back(shape2);

	CPictureDraft draft(shapes);

	CPainter::DrawPicture(draft, canvas);
}