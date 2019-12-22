#include "Ssnake.h"



Ssnake::Ssnake(int x = 0, int y = 0)
{
	this->gameIsOver = new bool(false);
	Block block(x, y);
	listOfBlock.push_back(block);
	block = Block(x, y + 1);
	listOfBlock.push_back(block);
}

Ssnake::Ssnake(deque<Block> listOfBlock) {
	this->gameIsOver = new bool(false);
	this->listOfBlock = listOfBlock;
}

Ssnake::Ssnake():Ssnake(0,0){
	this->gameIsOver = new bool(false);
}

Ssnake::~Ssnake()
{
}

Block Ssnake::getFirstBlock() {
	return this->listOfBlock.front();
}

Block Ssnake::getLastBlock() {
	return this->listOfBlock.back();
}

void Ssnake::setListOfBlock(deque<Block> listOfBlock) {
	this->listOfBlock = listOfBlock;
}

deque<Block> Ssnake::getListOfBlock() {
	return this->listOfBlock;
}

void Ssnake::pushBlock(Block block) {
	this->listOfBlock.push_back(block);
}

bool Ssnake::move(deque<CheckPoint> checkPoints, Coordinate prey) {
	for (deque<CheckPoint>::iterator check_it = checkPoints.begin(); check_it != checkPoints.end(); ++check_it) {
		for (deque<Block>::iterator block_it = listOfBlock.begin(); block_it != listOfBlock.end(); ++block_it) {
			if (check_it->getCoordinate() == block_it->getCoordinate()) {
				block_it->setDirection(check_it->getDirection());
			}
		}
	}

	for (deque<Block>::iterator it = listOfBlock.begin(); it != listOfBlock.end(); ++it)
		it->moveNextPoint();

	bool flag = addBlockToTail(prey);

	for (deque<CheckPoint>::iterator check_it = checkPoints.begin(); check_it != checkPoints.end(); ++check_it) {
		for (deque<Block>::iterator block_it = listOfBlock.begin(); block_it != listOfBlock.end(); ++block_it) {
			if (check_it->getCoordinate() == block_it->getCoordinate()) {
				block_it->setDirection(check_it->getDirection());
			}
		}
	}

	return flag;
}

bool Ssnake::breakTheWall(int M, int N) {
	Coordinate coordinate = this->getLastBlock().getCoordinate();
	if (coordinate.getX() >= M || coordinate.getY() >= N || coordinate.getX() < 0 || coordinate.getY() < 0) {
		*this->gameIsOver = true;
		return true;
	}
		
	return false;
}

bool Ssnake::hitTheTail() {
	Coordinate coordinate = getLastBlock().getCoordinate();
	int count = 0;
	for (deque<Block>::iterator block_it = listOfBlock.begin(); block_it != listOfBlock.end(); ++block_it) 
		if (coordinate == block_it->getCoordinate()) 
			count++;
			
	if (count > 1) {
		*this->gameIsOver = true;
		return true;
	}
	return false;
}

bool Ssnake::addBlockToTail(Coordinate prey) {
	Block block = listOfBlock.front();
	if (block.getPrevPosition(block.getDirection()) == prey) {
		Block newBlock(block.getPrevPosition(block.getDirection()));
		newBlock.setDirection(block.getDirection());
		listOfBlock.push_front(newBlock);
		return true;
	}
	return false;
}