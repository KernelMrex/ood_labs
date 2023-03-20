#include "app/canvas/CSvgCanvas.h"
#include "app/figure/CEllipse.h"
#include "app/figure/CFigureGroup.h"
#include "app/figure/CRectangle.h"
#include <iostream>
#include <memory>

std::unique_ptr<IFigure> GetSun()
{
	auto sun = std::make_unique<CEllipse>(CEllipse({ 50, 51 }, 40, 41));
	sun->FillStyle(CFillStyle(254, 232, 16, 1.0));
	sun->BorderStyle(CBorderStyle(235, 255, 44, 0.8, 24));
	return sun;
}

std::unique_ptr<IFigure> GetCloud()
{
	CFigureGroup cloud;

	auto cloudPart1 = std::make_shared<CEllipse>(SPoint{ 160, 100 }, 55, 55);
	cloudPart1->FillStyle(CFillStyle(255, 255, 255, 0.75));
	cloud.Add(cloudPart1);

	auto cloudPart2 = std::make_shared<CEllipse>(SPoint{ 125, 110 }, 40, 40);
	cloudPart2->FillStyle(CFillStyle(255, 255, 255, 0.75));
	cloud.Add(cloudPart2);

	auto cloudPart3 = std::make_shared<CEllipse>(SPoint{ 195, 110 }, 40, 40);
	cloudPart3->FillStyle(CFillStyle(255, 255, 255, 0.75));
	cloud.Add(cloudPart3);

	auto cloudPart4 = std::make_shared<CEllipse>(SPoint{ 138, 90 }, 40, 40);
	cloudPart4->FillStyle(CFillStyle(255, 255, 255, 0.75));
	cloud.Add(cloudPart4);

	return std::make_unique<CFigureGroup>(cloud);
}

std::unique_ptr<IFigure> GetGrass()
{
	auto grass = std::make_unique<CRectangle>(SPoint{ 0, 300 }, 500, 100);
	grass->FillStyle(CFillStyle(55, 217, 56, 1));
	return grass;
}

std::unique_ptr<IFigure> GetSky()
{
	auto sky = std::make_unique<CRectangle>(SPoint{ 0, 000 }, 500, 300);
	sky->FillStyle(CFillStyle(99, 188, 255, 1));
	return sky;
}

std::unique_ptr<IFigure> GetBackground()
{
	auto background = std::make_unique<CFigureGroup>();
	background->Add(GetGrass());
	background->Add(GetSky());
	return background;
}

int main()
{
	CSvgCanvas svgCanvas(std::cout, 500, 400);
	svgCanvas.StartDraw();

	auto background = GetBackground();
	background->Draw(svgCanvas);

	auto sun = GetSun();
	sun->Draw(svgCanvas);

	auto cloud = GetCloud();
	cloud->Draw(svgCanvas);

	svgCanvas.EndDraw();

	return EXIT_SUCCESS;
}