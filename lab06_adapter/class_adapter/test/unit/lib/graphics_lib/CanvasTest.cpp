#include <gtest/gtest.h>
#include "../../../../src/lib/graphics_lib/graphics_lib.h"

TEST(CanvasTest, MovingCursor)
{
	using namespace graphics_lib;
	testing::internal::CaptureStdout();

	CCanvas canvas;
	canvas.MoveTo(20, 30);

	std::string output = testing::internal::GetCapturedStdout();
	ASSERT_EQ("MoveTo (20, 30)\n", output);
}

TEST(CanvasTest, DrawingLine)
{
	using namespace graphics_lib;
	testing::internal::CaptureStdout();

	CCanvas canvas;
	canvas.LineTo(20, 30);

	std::string output = testing::internal::GetCapturedStdout();
	ASSERT_EQ("LineTo (20, 30)\n", output);
}