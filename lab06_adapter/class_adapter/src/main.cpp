#include "app/app.h"

int main()
{
	std::cout << "Should we use new API (y/n)? ";
	std::string userInput;
	if (getline(std::cin, userInput) && (userInput == "y" || userInput == "Y"))
	{
		app::PaintPictureOnModernGraphicsRenderer();
	}
	else
	{
		app::PaintPictureOnCanvas();
	}

	return EXIT_SUCCESS;
}