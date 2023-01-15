#include "../../../src/lib/CPictureDraft.h"
#include "matcher/MatchersPoint2D.cpp"
#include "mock/MockShape.cpp"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

using ::testing::Return;
using ::testing::ByMove;

TEST(CPictureDraftTest, StoringValuesTest)
{
//  TODO: fix
//	std::vector<std::shared_ptr<CShape>> shapes;
//
//	std::shared_ptr<MockShape> shape1;
//	ON_CALL(*shape1, Clone()).WillByDefault(Return(ByMove(std::make_unique<MockShape>())));
//	EXPECT_CALL(*shape1, Clone()).Times(1);

//	std::shared_ptr<MockShape> shape2;
//	EXPECT_CALL((*shape2), Clone())
//		.WillRepeatedly(Return(ByMove(std::make_unique<MockShape>())))
//		.Times(1);
//
//	std::shared_ptr<MockShape> shape3;
//	EXPECT_CALL((*shape3), Clone())
//		.WillRepeatedly(Return(ByMove(std::make_unique<MockShape>())))
//		.Times(1);
//
//	shapes.push_back(shape1);
//	shapes.push_back(shape2);
//	shapes.push_back(shape3);
//
//	CPictureDraft draft(shapes);
//
//	ASSERT_EQ(draft.GetShapeCount(), 3);
//	ASSERT_NE(draft.GetShape(1).get(), shape1.get());
//	ASSERT_NE(draft.GetShape(2).get(), shape2.get());
//	ASSERT_NE(draft.GetShape(3).get(), shape2.get());
}