#include "../../../src/lib/CDesigner.h"
#include "mock/MockShapeFactory.cpp"
#include "mock/MockShape.cpp"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

using ::testing::Return;
using ::testing::InSequence;
using ::testing::ByMove;

TEST(CDesinerTest, CreatingDraftsTest)
{
	InSequence s;

	auto mockShapeFactory = std::make_unique<MockShapeFactory>();
	EXPECT_CALL(*mockShapeFactory, CreateShape("some notation here 1"))
		.Times(1)
		.WillRepeatedly(Return(ByMove(std::make_unique<MockShape>())));
	EXPECT_CALL(*mockShapeFactory, CreateShape("some notation here 2"))
		.Times(1)
		.WillRepeatedly(Return(ByMove(std::make_unique<MockShape>())));

	CDesigner designer(std::move(mockShapeFactory));

	std::stringstream ss;

	ss << "some notation here 1" << std::endl
	   << "some notation here 2" << std::endl;

	auto draft = designer.CreateDraft(ss);

	ASSERT_EQ(draft->GetShapeCount(), 2);
}