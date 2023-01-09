#include "../../../src/lib/ConsoleCanvas.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

TEST(ConsoleCanvas, DrawingWorksFine)
{
	std::stringstream ss;

	ConsoleCanvas consoleCanvas(Color::BLACK, ss);

	consoleCanvas.Drawline({ .x = 1, .y = 2 }, { .x = 3, .y = 4 });
	consoleCanvas.DrawEllipse({ .x = 6, .y = 8 }, 100, 200);

	consoleCanvas.SetColor(Color::RED);

	consoleCanvas.Drawline({ .x = 100, .y = 200 }, { .x = 300, .y = 400 });
	consoleCanvas.DrawEllipse({ .x = 600, .y = 800 }, 10, 20);

	std::string expected = "line from (1, 2) to (3, 4) with #000000\n"
						   "ellipse center (6, 8) with hr: 100, vr: 200 with #000000\n"
						   "line from (100, 200) to (300, 400) with #ff5733\n"
						   "ellipse center (600, 800) with hr: 10, vr: 20 with #ff5733\n";

	ASSERT_EQ(ss.str(), expected);
}