#include "Block.h"



Block::Block()
{
	// Default Block definition
	coordinate = Coordinate(0, 0);
	direction = DIRECTION::EAST;
}

Block::Block(Coordinate coordinate) {
	this->coordinate = coordinate;
	direction = DIRECTION::EAST;
}

Block::Block(int x, int y) {
	coordinate = Coordinate(x, y);
	direction = DIRECTION::EAST;
}

Block::~Block()
{
}

Coordinate Block::getCoordinate() {
	return this->coordinate;
}

void Block::setCoordinate(Coordinate coordinate) {
	this->coordinate = coordinate;
}

void Block::moveNextPoint() {
	switch (direction)
	{
	case DIRECTION::EAST:
		coordinate = Coordinate(coordinate.getX(), coordinate.getY() + 1);
		break;
	case DIRECTION::WEST:
		coordinate = Coordinate(coordinate.getX(), coordinate.getY() - 1);
		break;
	case DIRECTION::NORTH:
		coordinate = Coordinate(coordinate.getX() - 1, coordinate.getY());
		break;
	case DIRECTION::SOUTH:
		coordinate = Coordinate(coordinate.getX() + 1, coordinate.getY());
		break;
	}
}

void Block::setDirection(DIRECTION direction) {
	this->direction = direction;
}

Coordinate Block::getNextPosition(DIRECTION direction) {
	Coordinate coordinate;
	switch (direction) {
	case DIRECTION::EAST:
		coordinate = Coordinate(this->coordinate.getX(), this->coordinate.getY() + 1);
		break;
	case DIRECTION::WEST:
		coordinate = Coordinate(this->coordinate.getX(), this->coordinate.getY() - 1);
		break;
	case DIRECTION::NORTH:
		coordinate = Coordinate(this->coordinate.getX() - 1, this->coordinate.getY());
		break;
	case DIRECTION::SOUTH:
		coordinate = Coordinate(this->coordinate.getX() + 1, this->coordinate.getY());
		break;
	}
	return coordinate;
}

Coordinate Block::getPrevPosition(DIRECTION direction) {
	Coordinate coordinate;
	switch (direction) {
	case DIRECTION::EAST:
		coordinate = Coordinate(this->coordinate.getX(), this->coordinate.getY() - 1);
		break;
	case DIRECTION::WEST:
		coordinate = Coordinate(this->coordinate.getX(), this->coordinate.getY() + 1);
		break;
	case DIRECTION::NORTH:
		coordinate = Coordinate(this->coordinate.getX() + 1, this->coordinate.getY());
		break;
	case DIRECTION::SOUTH:
		coordinate = Coordinate(this->coordinate.getX() - 1, this->coordinate.getY());
		break;
	}
	return coordinate;
}