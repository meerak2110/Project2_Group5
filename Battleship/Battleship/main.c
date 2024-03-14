
#include <stdio.h>
#include <stdbool.h>

#include "menu.h"

int main(void)
{
	//Create the menu
	MENU menu = CreateMenu();

	//Initialize menu items
	ITEM itemMainMenu[MAXITEMS] = { CreateItem("Start"),
									CreateItem("Highscores"),
									CreateItem("Exit") };
	
	AddFullMenu(itemMainMenu, &menu, MAXITEMS);

	int selection;
	bool Exit = true;

	while (Exit)
	{
		printf("To choose a function, enter its letter label:\n");
		DisplayMenuItems(menu);

		selection = GetCharForMenuInput();
		Exit = CheckSwitchAndExecuteFunctions((char)selection);
	}

	return 0;
}