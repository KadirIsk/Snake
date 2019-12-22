#pragma once
#ifndef SSNAKE_H
#define SSNAKE_H

#include <deque>
#include "CheckPoint.h"
#include "Block.h"
using namespace std;

class Ssnake
{
	deque<Block> listOfBlock;
	bool* gameIsOver;
public:
	void setGemeIsOver(bool gameIsOver) { *this->gameIsOver = gameIsOver; }
	bool* getGameIsOver() { return this->gameIsOver; }
	bool move(deque<CheckPoint>, Coordinate);
	Block getLastBlock();
	Block getFirstBlock();
	void setListOfBlock(deque<Block>);
	void pushBlock(Block);
	bool addBlockToTail(Coordinate);
	deque<Block> getListOfBlock();
	bool breakTheWall(int, int);
	bool hitTheTail();
	Ssnake();
	Ssnake(deque<Block>);
	Ssnake(int, int);
	~Ssnake();
};
#endif
