//Name:		Lexie Haveman
//Date:		March 14 2024
//Title:	Board Header
//Purpose:	This holds the function prototypes for the struct board

#pragma once

#include <stdio.h>
#include "battleship.h"

enum Status { DEFAULT = 0, HIT, MISS };

typedef struct board
{
	//status of the board ie. default/unknown, hit, miss
	enum Status status;
	//pointer to a battleship
	Battleship* ship;

} Board;

//create board
Board createBoard(void);

//get the ship that is in the board slot
Battleship* getShip(Board b);
//get the status of the board slot
enum Status getStatus(Board b);

//set the board status ie. hit, miss, default
void setStatus(Board b, enum Status s);
//set the ship of the board slot
void setShip(Board b, Battleship* s);