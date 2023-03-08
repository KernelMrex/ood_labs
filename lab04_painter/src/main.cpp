#include "lib/CDesigner.h"
#include "lib/CPainter.h"
#include "lib/CShapeFactory.h"
#include "lib/ConsoleCanvas.h"

#include <cstdlib>
#include <iostream>

int main()
{
	CDesigner designer(std::make_unique<CShapeFactory>());

	auto draft = designer.CreateDraft(std::cin);
	ConsoleCanvas canvas(Color::BLACK, std::cout);

	CPainter::DrawPicture(*draft, canvas);

	return EXIT_SUCCESS;
}