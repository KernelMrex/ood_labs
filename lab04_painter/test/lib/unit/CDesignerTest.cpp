#include "../../../src/lib/CDesigner.h"
#include "mock/MockShapeFactory.cpp"
#include "mock/MockShape.cpp"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

using ::testing::Return;
using ::testing::InSequence;
using ::testing::ByMove;
using ::testing::NiceMock;

TEST(CDesinerTest, CreatingDraftsTest)
{
	InSequence s;

	auto mockShape1 = std::make_unique<NiceMock<MockShape>>();
	ON_CALL(*mockShape1, Clone).WillByDefault(Return(ByMove(std::make_unique<MockShape>())));

	auto mockShape2 = std::make_unique<NiceMock<MockShape>>();
	ON_CALL(*mockShape2, Clone).WillByDefault(Return(ByMove(std::make_unique<MockShape>())));

	auto mockShapeFactory = std::make_unique<MockShapeFactory>();
	EXPECT_CALL(*mockShapeFactory, CreateShape(::testing::_))
		.Times(1)
		.WillRepeatedly(Return(ByMove(std::move(mockShape1))));
	EXPECT_CALL(*mockShapeFactory, CreateShape(::testing::_))
		.Times(1)
		.WillRepeatedly(Return(ByMove(std::move(mockShape2))));

	CDesigner designer(std::move(mockShapeFactory));

	std::stringstream ss;

	ss << "some notation here 1" << std::endl
	   << "some notation here 2" << std::endl;

	auto draft = designer.CreateDraft(ss);

	ASSERT_EQ(draft->GetShapeCount(), 2);
}