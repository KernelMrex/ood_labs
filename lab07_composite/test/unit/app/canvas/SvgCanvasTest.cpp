#include "../../../../src/app/canvas/CSvgCanvas.h"
#include <gtest/gtest.h>

TEST(SvgCanvasTest, StartAndEndDrawing)
{
	std::ostringstream oss;

	CSvgCanvas canvas(oss, 500, 400);
	canvas.StartDraw();
	canvas.EndDraw();

	std::string expected = "<svg height=\"400\" width=\"500\">\n"
						   "</svg>\n";

	ASSERT_EQ(expected, oss.str());
}

TEST(SvgCanvasTest, EndDrawingOnDestructor)
{
	std::ostringstream oss;

	ASSERT_NO_THROW({
		CSvgCanvas canvas(oss, 500, 400);
		canvas.StartDraw();
	});

	std::string expected = "<svg height=\"400\" width=\"500\">\n"
						   "</svg>\n";

	ASSERT_EQ(expected, oss.str());
}

TEST(SvgCanvasTest, CheckEllipseDrawing)
{
	std::ostringstream oss;

	CSvgCanvas canvas(oss, 500, 400);
	canvas.StartDraw();
	canvas.DrawEllipse({ 50, 51 }, 40, 41, SColor{ 235, 255, 44, 0.8 }, 24);
	canvas.EndDraw();

	std::string expected = "<svg height=\"400\" width=\"500\">\n"
						   "  <ellipse cx=\"50\" cy=\"51\" rx=\"41\" ry=\"40\" fill-opacity=\"0\" stroke=\"rgba(235, 255, 44, 0.8)\" stroke-width=\"24\"/>\n"
						   "</svg>\n";

	ASSERT_EQ(expected, oss.str());
}

TEST(SvgCanvasTest, DrawingEllipseCauseErrorIfDrawingWasNotStarted)
{
	std::ostringstream oss;
	ASSERT_THROW({
		CSvgCanvas canvas(oss, 500, 400);
		canvas.DrawEllipse({ 50, 51 }, 40, 41, SColor{ 235, 255, 44, 0.8 }, 24);
	}, std::logic_error);

	ASSERT_EQ("", oss.str());
}

TEST(SvgCanvasTest, CheckEllipseFilling)
{
	std::ostringstream oss;

	CSvgCanvas canvas(oss, 500, 400);
	canvas.StartDraw();
	canvas.FillEllipse({ 50, 51 }, 40, 41, SColor{ 254, 232, 16, 1.0 });
	canvas.EndDraw();

	std::string expected = "<svg height=\"400\" width=\"500\">\n"
						   "  <ellipse cx=\"50\" cy=\"51\" rx=\"41\" ry=\"40\" fill=\"rgba(254, 232, 16, 1)\" stroke=\"none\"/>\n"
						   "</svg>\n";

	ASSERT_EQ(expected, oss.str());
}

TEST(SvgCanvasTest, FillingEllipseCauseErrorIfDrawingWasNotStarted)
{
	std::ostringstream oss;
	ASSERT_THROW({
		CSvgCanvas canvas(oss, 500, 400);
		canvas.FillEllipse({ 50, 51 }, 40, 41, SColor{ 254, 232, 16, 1.0 });
	}, std::logic_error);

	ASSERT_EQ("", oss.str());
}