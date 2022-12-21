#include "Menu.h"

int AscMenuItem()
{
	int ChosenItem = 0;

	std::cout << "1 - Input by console" << std::endl;
	std::cout << "2 - Input by file" << std::endl;

	ChosenItem = CheckMenuItem(2);

	return ChosenItem;

}

int AskToQuitOrToStay()
{
	int ChosenItem = 0;

	std::cout << "1 - To end the program" << std::endl <<
		"2 - To run the program again" << std::endl;


	ChosenItem = CheckMenuItem(2);
	return ChosenItem;
}

int AskToSave()
{
	int ChosenItem = 0;

	std::cout << "1 - Save list in file" << std::endl <<
		"2 - Continue withot saving" << std::endl;


	ChosenItem = CheckMenuItem(2);
	return ChosenItem;
}
