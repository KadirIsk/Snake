#include "Coordinate.h"

int Coordinate::getX() {
	return this->x;
}

void Coordinate::setX(int x) {
	this->x = x;
}

int Coordinate::getY() {
	return this->y;
}

void Coordinate::setY(int y) {
	this->y = y;
}

Coordinate::Coordinate()
{
	this->x = this->y = 0;
}

Coordinate::Coordinate(int x, int y) {
	this->x = x;
	this->y = y;
}

Coordinate::~Coordinate()
{
}

bool Coordinate::operator==(const Coordinate& other) {
	if (x == other.x && y == other.y)
		return true;
	return false;
}
