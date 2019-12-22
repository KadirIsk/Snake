#include "CheckPoint.h"



CheckPoint::CheckPoint()
{
	coordinate = Coordinate(-1, -1);
	direction = DIRECTION::EAST;
}

CheckPoint::CheckPoint(Coordinate coordiante, DIRECTION direction) {
	this->coordinate = coordiante;
	this->direction = direction;
}

CheckPoint::~CheckPoint()
{
}

DIRECTION CheckPoint::getDirection() {
	return this->direction;
}

Coordinate CheckPoint::getCoordinate() {
	return this->coordinate;
}