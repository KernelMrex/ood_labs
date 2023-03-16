#include "../../../../src/lib/modern_graphics_lib/modern_graphics_lib.h"
#include <gtest/gtest.h>

TEST(CModernGraphicsRendererTest, DrawingLineThrowsIfDrawingWasNotStarted)
{
	using namespace modern_graphics_lib;

	std::ostringstream oss;

	CModernGraphicsRenderer renderer(oss);

	ASSERT_THROW({ renderer.DrawLine({ 10, 20 }, { 30, 40 }); }, std::logic_error);
}

TEST(CModernGraphicsRendererTest, DrawingLine)
{
	using namespace modern_graphics_lib;

	std::ostringstream oss;

	CModernGraphicsRenderer renderer(oss);

	ASSERT_NO_THROW({
		renderer.BeginDraw();
		renderer.DrawLine({ 10, 20 }, { 30, 40 });
		renderer.EndDraw();
	});

	std::ostringstream expected;
	expected << "<draw>" << std::endl
			 << R"(  <line fromX="10" fromY="20" toX="30" toY="40"/>)" << std::endl
			 << "</draw>" << std::endl;

	ASSERT_EQ(expected.str(), oss.str());
}
