#include "../../../../src/app/figure/CFigureGroup.h"
#include "../canvas/MockCanvas.cpp"
#include "./MockFigure.cpp"
#include <gtest/gtest.h>

TEST(FigureGroupTest, MustAddAndUpdateGroupFrame)
{
	using ::testing::AtLeast;
	using ::testing::Return;

	CFigureGroup figureGroup;
	ASSERT_FALSE(figureGroup.Frame().has_value());

	auto mockFigure1 = std::make_shared<MockFigure>();
	EXPECT_CALL(*mockFigure1, Frame())
		.Times(AtLeast(1))
		.WillRepeatedly(Return(SFrame{ { 20, 40 }, { 50, 60 } }));
	figureGroup.Add(mockFigure1);

	auto mockFigure2 = std::make_shared<MockFigure>();
	EXPECT_CALL(*mockFigure2, Frame())
		.Times(AtLeast(1))
		.WillRepeatedly(Return(SFrame{ { 10, 30 }, { 35, 50 } }));
	figureGroup.Add(mockFigure2);

	auto resultingFrame = figureGroup.Frame();
	ASSERT_TRUE(resultingFrame.has_value());
	ASSERT_EQ(resultingFrame->leftTop.x, 10);
	ASSERT_EQ(resultingFrame->leftTop.y, 30);
	ASSERT_EQ(resultingFrame->rightBottom.x, 50);
	ASSERT_EQ(resultingFrame->rightBottom.y, 60);
}

TEST(FigureGroupTest, MustRemoveAndUpdateGroupFrame)
{
	using ::testing::AtLeast;
	using ::testing::Return;

	CFigureGroup figureGroup;
	ASSERT_FALSE(figureGroup.Frame().has_value());

	auto mockFigure1 = std::make_shared<MockFigure>();
	EXPECT_CALL(*mockFigure1, Frame())
		.Times(AtLeast(1))
		.WillRepeatedly(Return(SFrame{ { 20, 40 }, { 50, 60 } }));
	figureGroup.Add(mockFigure1);

	auto mockFigure2 = std::make_shared<MockFigure>();
	EXPECT_CALL(*mockFigure2, Frame())
		.Times(AtLeast(1))
		.WillRepeatedly(Return(SFrame{ { 10, 30 }, { 35, 50 } }));
	figureGroup.Add(mockFigure2);

	figureGroup.Remove(mockFigure2);
	auto resultingFrame = figureGroup.Frame();
	ASSERT_EQ(resultingFrame->leftTop.x, 20);
	ASSERT_EQ(resultingFrame->leftTop.y, 40);
	ASSERT_EQ(resultingFrame->rightBottom.x, 50);
	ASSERT_EQ(resultingFrame->rightBottom.y, 60);
}

TEST(FigureGroupTest, MustCallDrawOnAllItems)
{
	using ::testing::NiceMock;
	using ::testing::Ref;
	using ::testing::Return;

	MockCanvas mockCanvas;
	CFigureGroup figureGroup;

	auto mockFigure1 = std::make_shared<NiceMock<MockFigure>>();
	EXPECT_CALL(*mockFigure1, Draw(Ref(mockCanvas))).Times(1);
	ON_CALL(*mockFigure1, Frame()).WillByDefault(Return(SFrame{ { 10, 30 }, { 35, 50 } }));
	figureGroup.Add(mockFigure1);

	auto mockFigure2 = std::make_shared<NiceMock<MockFigure>>();
	EXPECT_CALL(*mockFigure2, Draw(Ref(mockCanvas))).Times(1);
	ON_CALL(*mockFigure2, Frame()).WillByDefault(Return(SFrame{ { 10, 30 }, { 35, 50 } }));
	figureGroup.Add(mockFigure2);

	figureGroup.Draw(mockCanvas);
}
