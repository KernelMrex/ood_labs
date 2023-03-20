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

TEST(SvgCanvasTest, CheckLineDrawing)
{
	std::ostringstream oss;

	CSvgCanvas canvas(oss, 500, 400);
	canvas.StartDraw();
	canvas.DrawLine({ 0, 1 }, { 2, 3 }, SColor{ 12, 34, 56, 1.0 }, 4);
	canvas.EndDraw();

	std::string expected = "<svg height=\"400\" width=\"500\">\n"
						   "  <line x1=\"0\" y1=\"1\" x2=\"2\" y2=\"3\" stroke=\"rgba(12, 34, 56, 1)\" stroke-width=\"4\"/>\n"
						   "</svg>\n";

	ASSERT_EQ(expected, oss.str());
}

TEST(SvgCanvasTest, LineDrawingCauseErrorIfDrawingWasNotStarted)
{
	std::ostringstream oss;
	ASSERT_THROW({
		CSvgCanvas canvas(oss, 500, 400);
		canvas.DrawLine({ 0, 1 }, { 2, 3 }, SColor{ 12, 34, 56, 1.0 }, 4);;
	}, std::logic_error);

	ASSERT_EQ("", oss.str());
}

TEST(SvgCanvasTest, CheckPolygonFilling)
{
	std::ostringstream oss;

	CSvgCanvas canvas(oss, 500, 400);
	canvas.StartDraw();

	canvas.FillPolygon(std::vector<SPoint>{ { 10, 20 }, { 15, 25 }, { 25, 40 } }, SColor{ 12, 34, 56, 1.0 });

	canvas.EndDraw();

	std::string expected = "<svg height=\"400\" width=\"500\">\n"
						   "  <polygon points=\"10,20 15,25 25,40\" fill=\"rgba(12, 34, 56, 1)\" stroke=\"none\"/>\n"
						   "</svg>\n";

	ASSERT_EQ(expected, oss.str());
}

TEST(SvgCanvasTest, PolygonFillingCauseErrorIfDrawingWasNotStarted)
{
	std::ostringstream oss;
	ASSERT_THROW({
		CSvgCanvas canvas(oss, 500, 400);
		canvas.FillPolygon(std::vector<SPoint>{ { 10, 20 }, { 15, 25 }, { 25, 40 } }, SColor{ 12, 34, 56, 1.0 });
	}, std::logic_error);

	ASSERT_EQ("", oss.str());
}

TEST(SvgCanvasTest, PolygonFillingCauseErrorIfProvidedLessThan3Vertices)
{
	std::ostringstream oss;
	ASSERT_THROW({
		CSvgCanvas canvas(oss, 500, 400);
		canvas.FillPolygon(std::vector<SPoint>{ { 10, 20 }, { 15, 25 } }, SColor{ 12, 34, 56, 1.0 });
	}, std::logic_error);

	ASSERT_EQ("", oss.str());
}