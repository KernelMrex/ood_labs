#include "../../../../src/app/graphics/CModernGraphicsRendererAdapter.h"
#include <gtest/gtest.h>

TEST(ModernGraphicsAdapterTest, CheckDrawing)
{
	std::ostringstream oss;

	app::CModernGraphicsRendererAdapter adapter(oss);

	adapter.BeginDraw();
	adapter.MoveTo(10, 20);
	adapter.LineTo(20, 30);
	adapter.LineTo(5, 15);
	adapter.EndDraw();

	std::string expected = "<draw>\n"
						   "  <line fromX=\"10\" fromY=\"20\" toX=\"20\" toY=\"30\"/>\n"
						   "  <line fromX=\"10\" fromY=\"20\" toX=\"5\" toY=\"15\"/>\n"
						   "</draw>\n";

	ASSERT_EQ(expected, oss.str());
}