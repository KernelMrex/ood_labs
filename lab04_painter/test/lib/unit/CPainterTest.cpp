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

	auto innerInnerShape1 = std::make_unique<MockShape>();
	EXPECT_CALL(*innerInnerShape1, Draw(::testing::_)).Times(1);
	auto innerShape1 = std::make_unique<NiceMock<MockShape>>();
	ON_CALL(*innerShape1, Clone).WillByDefault(Return(ByMove(std::move(innerInnerShape1))));
	auto shape1 = std::make_shared<NiceMock<MockShape>>();
	ON_CALL(*shape1, Clone).WillByDefault(Return(ByMove(std::move(innerShape1))));

	auto innerInnerShape2 = std::make_unique<MockShape>();
	EXPECT_CALL(*innerInnerShape2, Draw(::testing::_)).Times(1);
	auto innerShape2 = std::make_unique<NiceMock<MockShape>>();
	ON_CALL(*innerShape2, Clone).WillByDefault(Return(ByMove(std::move(innerInnerShape2))));
	auto shape2 = std::make_shared<NiceMock<MockShape>>();
	ON_CALL(*shape2, Clone).WillByDefault(Return(ByMove(std::move(innerShape2))));

	std::vector<std::shared_ptr<CShape>> shapes;

	shapes.push_back(shape1);
	shapes.push_back(shape2);

	CPictureDraft draft(shapes);

	CPainter::DrawPicture(draft, canvas);
}