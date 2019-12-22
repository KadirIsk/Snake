#pragma once
class Coordinate
{
private:
	int x;
	int y;
public:
	void setX(int);
	int getX();
	void setY(int);
	int getY();
	bool operator ==(const Coordinate&);

	Coordinate();
	Coordinate(int, int);
	~Coordinate();
};

