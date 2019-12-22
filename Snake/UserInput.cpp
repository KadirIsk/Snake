#include "UserInput.h"



UserInput::UserInput()
{
	currentCheckPoint = CheckPoint(Coordinate(-1, -1), EAST);
}

UserInput::UserInput(deque<CheckPoint> listOfCheckPoint) {
	currentCheckPoint = CheckPoint(Coordinate(-1, -1), EAST);
	this->listOfCheckPoint = listOfCheckPoint;
}

UserInput::~UserInput()
{
}

void UserInput::setCurrentCheckPoint(CheckPoint currentCheckPoint) {
	this->currentCheckPoint = currentCheckPoint;
}

CheckPoint UserInput::getCurrentCheckPoint() {
	return this->currentCheckPoint;
}

void UserInput::setListOfCheckPoint(deque<CheckPoint> listOfCheckPoint) {
	this->listOfCheckPoint = listOfCheckPoint;
}

deque<CheckPoint> UserInput::getListOfCheckPoint() {
	return this->listOfCheckPoint;
}

void UserInput::pushCheckPoint(CheckPoint checkPoint) {
	if (isExist(checkPoint))
		return;
	this->listOfCheckPoint.push_back(checkPoint);
}

bool UserInput::isExist(CheckPoint checkPoint) {
	for (deque<CheckPoint>::iterator it = listOfCheckPoint.begin(); it != listOfCheckPoint.end(); ++it) {
		if (it->getCoordinate() == checkPoint.getCoordinate())
			return true;
	}
	return false;
}

void UserInput::popCheckPoint(Coordinate coordinate) {
	if (listOfCheckPoint.size() > 0) {
		CheckPoint checkPoint = listOfCheckPoint.front();
			if (checkPoint.getCoordinate() == coordinate)
				listOfCheckPoint.pop_front();
	}
	
}