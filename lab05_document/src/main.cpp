#include "lib/CApp.h"
#include "lib/file/CFileSystemFileStorage.h"

#include <cstdlib>
#include <iostream>

int main()
{
	auto fileStorage = std::make_shared<CFileSystemFileStorage>(CPath("test"));

	CApp app(std::cin, std::cout, fileStorage);
	app.ListenAndServe();

	return EXIT_SUCCESS;
}