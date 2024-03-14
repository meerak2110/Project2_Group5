//Name:		Lexie Haveman
//Date:		Nov 9 2023
//Class:	Programming Principles
//Title:	Item and Menu structures
//Purpose:	Defines the Item and Menu structure as well as prototypes

#pragma once

#include <stdio.h>
#include <stdbool.h>

#define MAXCHAR_MENU 80
#define MAXITEMS 3
#define MAXCHAR_INPUT 3

typedef struct item
{
	char itemName[MAXCHAR_MENU];
} ITEM;

typedef struct menu
{
	int counter;
	ITEM menuItem[MAXITEMS];
} MENU;

//Create
ITEM CreateItem(char* Item);
MENU CreateMenu();

//Read
bool GetItem(ITEM Item, char* c);
int GetCountMenu(MENU m);
bool GetMenuItemAtOrdinal(MENU m, ITEM Item, int ordinal);
bool CopyItem(ITEM* dest, ITEM src);
int GetCharForMenuInput(void);
void GetStringFromUser(char str[]);

bool CheckSwitchAndExecuteFunctions(char c);

//Update
int IncrementCounter(MENU* m);
bool ChangeItemName(ITEM* Item, char* Name);
bool AddItemToMenu(ITEM Item, MENU* m);
void DisplayMenuItems(MENU m);
void AddFullMenu(ITEM Item[], MENU* m, int MenuMax);

//Options
void OptionA(void);
void OptionB(void);
void OptionC(void);

//Destroy
void DestroyItem(ITEM Item);
void DestroyMenu(MENU m);