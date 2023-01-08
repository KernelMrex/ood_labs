#define CATCH_CONFIG_MAIN
#include "../../../../catch.hpp"
#include "../../../src/lib/ConsoleCanvas.h"

TEST_CASE("ConsoleCanvas unit tests", "[console_canvas]")
{
	SECTION("Constructing and drawing works fine")
	{
		std::stringstream ss;

		ConsoleCanvas consoleCanvas(Color::BLACK, ss);

		consoleCanvas.Drawline({ .x = 1, .y = 2 }, { .x = 3, .y = 4 });
		consoleCanvas.DrawEllipse({ .x = 6, .y = 8 }, 100, 200);

		consoleCanvas.SetColor(Color::RED);

		consoleCanvas.Drawline({ .x = 100, .y = 200 }, { .x = 300, .y = 400 });
		consoleCanvas.DrawEllipse({ .x = 600, .y = 800 }, 10, 20);

		auto expected = R"XXXXX(
ellipse center (6, 8) with hr: 100, vr: 200 with #000000
line from (100, 200) to (300, 400) with #ff5733
ellipse center (600, 800) with hr: 10, vr: 20 with #ff5733
)XXXXX";

		REQUIRE(ss.str() == expected);
	}
}