#include "app/canvas/CSvgCanvas.h"
#include "app/figure/CEllipse.h"
#include "app/figure/CFigureGroup.h"
#include <iostream>
#include <memory>

std::unique_ptr<IFigure> DrawSun()
{
	auto sun = std::make_unique<CEllipse>(CEllipse({ 50, 51 }, 40, 41));
	sun->FillStyle(CFillStyle(254, 232, 16, 1.0));
	sun->BorderStyle(CBorderStyle(235, 255, 44, 0.8, 24));
	return sun;
}

std::unique_ptr<IFigure> DrawCloud()
{
	CFigureGroup cloud;

	auto cloudPart1 = std::make_shared<CEllipse>(CEllipse({160, 100}, 55, 55));
	cloudPart1->FillStyle(CFillStyle(255, 255, 255, 0.75));
	cloud.Add(cloudPart1);

	auto cloudPart2 = std::make_shared<CEllipse>(CEllipse({125, 110}, 40, 40));
	cloudPart2->FillStyle(CFillStyle(255, 255, 255, 0.75));
	cloud.Add(cloudPart2);

	auto cloudPart3 = std::make_shared<CEllipse>(CEllipse({195, 110}, 40, 40));
	cloudPart3->FillStyle(CFillStyle(255, 255, 255, 0.75));
	cloud.Add(cloudPart3);

	auto cloudPart4 = std::make_shared<CEllipse>(CEllipse({138, 90}, 40, 40));
	cloudPart4->FillStyle(CFillStyle(255, 255, 255, 0.75));
	cloud.Add(cloudPart4);

	return std::make_unique<CFigureGroup>(cloud);
}

int main()
{
	CSvgCanvas svgCanvas(std::cout, 500, 400);
	svgCanvas.StartDraw();

	auto sun = DrawSun();
	sun->Draw(svgCanvas);

	auto cloud = DrawCloud();
	cloud->Draw(svgCanvas);

	svgCanvas.EndDraw();

	return EXIT_SUCCESS;
}