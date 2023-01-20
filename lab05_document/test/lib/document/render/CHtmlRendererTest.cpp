#include "../../../../src/lib/document/render/CHtmlRenderer.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

TEST(CHtmlRendererTest, RenderImageNode)
{
	std::ostringstream ss;
	CHtmlRenderer renderer(ss);

	CImageNode imageNode(CPath("test/path.png"), 400, 300);
	imageNode.Render(renderer);

	ASSERT_EQ(ss.str(), "<img src=\"test/path.png\" width=\"400\" height=\"300\">");
}

TEST(CHtmlRendererTest, RenderParagraphNode)
{
	std::ostringstream ss;
	CHtmlRenderer renderer(ss);

	CParagraphNode paragraphNode("Some text and stuff");
	paragraphNode.Render(renderer);

	ASSERT_EQ(ss.str(), "<p>Some text and stuff</p>");
}