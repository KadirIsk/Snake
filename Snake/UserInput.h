#pragma once
#include <deque>
#include "CheckPoint.h"
using namespace std;
class UserInput
{
	deque<CheckPoint> listOfCheckPoint;
	CheckPoint currentCheckPoint;

public:
	void setCurrentCheckPoint(CheckPoint);
	CheckPoint getCurrentCheckPoint();
	void setListOfCheckPoint(deque<CheckPoint>);
	deque<CheckPoint> getListOfCheckPoint();
	void pushCheckPoint(CheckPoint);
	void popCheckPoint(Coordinate);
	bool isExist(CheckPoint);
	UserInput(deque<CheckPoint>);
	UserInput();
	~UserInput();
};

