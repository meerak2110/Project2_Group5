//Name:		Lexie Haveman
//Date:		Nov 9 2023
//Class:	Programming Principles
//Title:	Menu structure
//Purpose:	Manages menu options and navigation

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "menu.h"

//Create
ITEM CreateItem(char* Item)
{
	ITEM t;
	strcpy(t.itemName, Item);

	printf("item created\n");
	return t;
}
MENU CreateMenu()
{
	MENU m;
	m.counter = 0;

	printf("menu created\n");

	return m;
}

//Read
bool GetItem(ITEM Item, char* c)
{
	if (&Item == NULL)
	{
		return false;
	}

	strcpy(c, Item.itemName);
	return true;
}
int GetCountMenu(MENU m)
{
	return m.counter;
}

//TODO: Work in progress
bool GetMenuItemAtOrdinal(MENU m, ITEM Item, int ordinal)
{
	return true;
}

bool CopyItem(ITEM* dest, ITEM src)
{
	if (&src == NULL)
	{
		return false;
	}

	else
	{
		strcpy(dest->itemName, src.itemName);
		return true;
	}
}

int GetCharForMenuInput(void)
{
	//character
	int c;
	c = _fgetchar();
	while ((char)c == '\n')
	{
		c = _fgetchar();
	}
	return c;
}

void GetStringFromUser(char str[])
{
	//string
	char buff[MAXCHAR_INPUT];

	//Get input
	fgets(buff, MAXCHAR_INPUT, stdin);
	while ((char)buff[0] == '\n')
	{
		fgets(buff, MAXCHAR_INPUT, stdin);
	}

	//remove the new line
	buff[strcspn(buff, "\n")] = 0;
	strcpy(str, buff);
}

bool CheckSwitchAndExecuteFunctions(char c)
{
	//make the character lower case
	c = tolower(c);
	
	switch (c)
	{
	default:
		break;
	case '1':
		OptionA();
		break;
	case '2':
		OptionB();
		break;
	case '3':
		OptionC();
		return false;
		break;
	}

	return true;
}

//Update
bool ChangeItemName(ITEM* Item, char* Name)
{
	if (&Item == NULL)
	{
		return false;
	}
	if (Name == NULL)
	{
		return false;
	}
	strcpy(Item->itemName, Name);
	return true;
}

int IncrementCounter(MENU* m)
{
	return m->counter++;
}

bool AddItemToMenu(ITEM Item, MENU* m)
{
	if (&Item == NULL)
	{
		return false;
	}
	if (m == NULL)
	{
		return false;
	}

	else
	{
		if (m->counter == 0)
		{
			CopyItem(&m->menuItem[0], Item);
			IncrementCounter(m);
			return true;
		}
		else
		{
			CopyItem(&m->menuItem[GetCountMenu(*m)], Item);
			IncrementCounter(m);
			return true;
		}
	}
}

void DisplayMenuItems(MENU m)
{
	//integer value of character 1
	char prefix = 49;
	for (int i = 0; i < m.counter; i++)
	{
		printf("%c) %s\n", prefix + i, m.menuItem[i].itemName);
	}
}

void AddFullMenu(ITEM Item[], MENU* m, int MenuMax)
{
	for (int i = 0; i < MenuMax; i++)
	{
		AddItemToMenu(Item[i], m);
	}

}

//
void OptionA()
{
	printf("Option A\n");
}

//
void OptionB()
{
	printf("Option B\n");
}

//
void OptionC()
{
	printf("Option C\n");
}

//Destroy
void DestroyItem(ITEM Item)
{

}

void DestroyMenu(MENU m)
{

}