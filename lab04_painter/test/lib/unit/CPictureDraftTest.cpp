#include "../../../src/lib/CPictureDraft.h"
#include "matcher/MatchersPoint2D.cpp"
#include "mock/MockShape.cpp"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

using ::testing::Return;
using ::testing::ByMove;

TEST(CPictureDraftTest, StoringValuesTest)
{
	std::vector<std::shared_ptr<CShape>> shapes;

	std::shared_ptr<MockShape> shape1;
	std::shared_ptr<MockShape> shape2;
	std::shared_ptr<MockShape> shape3;

	shapes.push_back(shape1);
	shapes.push_back(shape2);
	shapes.push_back(shape3);

	CPictureDraft draft(shapes);

	ASSERT_EQ(draft.GetShapeCount(), 3);
}