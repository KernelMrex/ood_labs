#include "app/canvas/CSvgCanvas.h"
#include "app/figure/CEllipse.h"
#include <iostream>
#include <memory>

std::unique_ptr<IFigure> DrawSun()
{
	auto sun = std::make_unique<CEllipse>(CEllipse({ 50, 51 }, 40, 41));
	sun->FillStyle(CFillStyle(254, 232, 16, 1.0));
	sun->BorderStyle(CBorderStyle(235, 255, 44, 0.8, 24));
	return sun;
}

int main()
{
	CSvgCanvas svgCanvas(std::cout, 500, 400);
	svgCanvas.StartDraw();

	auto sun = DrawSun();
	sun->Draw(svgCanvas);

	svgCanvas.EndDraw();

	return EXIT_SUCCESS;
}