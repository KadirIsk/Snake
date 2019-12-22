#pragma once
#include "Direction.h"
#include "Coordinate.h"

class CheckPoint
{
	Coordinate coordinate;
	DIRECTION direction;

public:
	DIRECTION getDirection();
	void setDirection();
	Coordinate getCoordinate();
	CheckPoint(Coordinate, DIRECTION);
	CheckPoint();
	~CheckPoint();
};

