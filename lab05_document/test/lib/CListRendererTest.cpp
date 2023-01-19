#include "../../src/lib/CListRenderer.h"
#include <gmock/gmock.h>
#include <gtest/gtest.h>

TEST(CListRendererTest, RenderImageNode)
{
	std::ostringstream ss;
	CListRenderer renderer(ss);

	CImageNode imageNode(CPath("test/path.png"), 400, 300);
	imageNode.Render(renderer);

	ASSERT_EQ(ss.str(), "Image: 400 300 test/path.png");
}