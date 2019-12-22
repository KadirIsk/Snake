#pragma once
#include "Coordinate.h"
#include "Direction.h"
class Block
{
	Coordinate coordinate;
	DIRECTION direction;
public:
	void moveNextPoint();
	Coordinate getCoordinate();
	void setCoordinate(Coordinate);
	void setDirection(DIRECTION);
	Coordinate getNextPosition(DIRECTION);
	Coordinate getPrevPosition(DIRECTION);
	DIRECTION getDirection() { return direction; }
	Block();
	Block(Coordinate);
	Block(int, int);
	~Block();
};

