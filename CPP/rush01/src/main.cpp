#include "Hostname.hpp"
#include "TextMode.hpp"
#include "GraphicalMode.hpp"

int main(int argc, char **argv)
{
	TextMode textmode;
	GraphicalMode graphicalMode;

	if (argc < 2)
		std::cout << "Display form dosen't choosen (1 - graphicalMode; 2 - textMode)" << std::endl;
	else if (argc > 3)
		std::cout << "Too many parameters" << std::endl;
	else if (strcmp(argv[1], "1") == 0)
		graphicalMode.display();
	else if (strcmp(argv[1], "2") == 0)
		textmode.display();
	else
		std::cout << "Wrong format" << std::endl;	
	return (0);
}
