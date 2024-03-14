//Name:		Lexie Haveman
//Date:		March 14 2024
//Title:	Board Struct
//Purpose:	This is the data structure that is used in the Game Board struct as an array. 
//It tracks whether the spot is in its initialized state or is a hit/miss, 
//and the ship that is attached to it

#include <stdio.h>

#include "board.h"

//create board
Board createBoard(void)
{
	Board b;

	b.status = DEFAULT;
	b.ship = NULL;

	return b;
}

//get the ship that is in the board slot
Battleship* getShip(Board b)
{
	return b.ship;
}

//get the status of the board slot
enum Status getStatus(Board b)
{
	return b.status;
}

//set the board status ie. hit, miss, default
void setStatus(Board b, enum Status s)
{
	b.status = s;
}

//set the ship of the board slot
void setShip(Board b, Battleship* s)
{
	b.ship = s;
}