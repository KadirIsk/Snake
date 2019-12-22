// Main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <conio.h>
#include <thread> 
#include <Windows.h>
#include "UserInput.h"
#include "Game.h"
#include "Ssnake.h"
#include "Block.h"
using namespace std;

void clearScreen()
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD Position;
	Position.X = 0;
	Position.Y = 0;
	SetConsoleCursorPosition(hOut, Position);
}

void cursorHide(bool visible) {
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = visible;
	SetConsoleCursorInfo(out, &cursorInfo);
}

void thread_keyboard_listener(UserInput* userInput, Ssnake* snake) {
	char key;
	while (1) {
		key = _getch();

		if (*snake->getGameIsOver())
			break;

		switch (key)
		{
		case 72:
			switch (userInput->getCurrentCheckPoint().getDirection()) {
			case DIRECTION::WEST:
			case DIRECTION::EAST:
				Coordinate coordinate(
					snake->getLastBlock().getCoordinate().getX(),
					snake->getLastBlock().getCoordinate().getY()
					);

				CheckPoint currentCheckPoint(coordinate, DIRECTION::NORTH);
				userInput->setCurrentCheckPoint(currentCheckPoint);
				userInput->pushCheckPoint(currentCheckPoint);
				break;
			}
			break;
		case 80:
			switch (userInput->getCurrentCheckPoint().getDirection()) {
			case DIRECTION::WEST:
			case DIRECTION::EAST:
				Coordinate coordinate(
					snake->getLastBlock().getCoordinate().getX(),
					snake->getLastBlock().getCoordinate().getY()
					);

				CheckPoint currentCheckPoint(coordinate, DIRECTION::SOUTH);
				userInput->setCurrentCheckPoint(currentCheckPoint);
				userInput->pushCheckPoint(currentCheckPoint);
				break;
			}
			break;
		case 75:
			switch (userInput->getCurrentCheckPoint().getDirection()) {
			case DIRECTION::NORTH:
			case DIRECTION::SOUTH:
				Coordinate coordinate(
					snake->getLastBlock().getCoordinate().getX(),
					snake->getLastBlock().getCoordinate().getY()
					);

				CheckPoint currentCheckPoint(coordinate, DIRECTION::WEST);
				userInput->setCurrentCheckPoint(currentCheckPoint);
				userInput->pushCheckPoint(currentCheckPoint);
				break;
			}
			break;
		case 77:
			switch (userInput->getCurrentCheckPoint().getDirection()) {
			case DIRECTION::NORTH:
			case DIRECTION::SOUTH:
				Coordinate coordinate(
					snake->getLastBlock().getCoordinate().getX(),
					snake->getLastBlock().getCoordinate().getY()
					);

				CheckPoint currentCheckPoint(coordinate, DIRECTION::EAST);
				userInput->setCurrentCheckPoint(currentCheckPoint);
				userInput->pushCheckPoint(currentCheckPoint);
				break;
			}
			break;
		default:
			break;
		}
		
	}
}

void thread_draw_chart(Game* p, Ssnake* snake, UserInput* u) {
	while (1) {
		clearScreen();
		if (snake->move(u->getListOfCheckPoint(), p->getPreyQueue().front()))
			p->popPrey();
		p->computeScore(snake);
		u->popCheckPoint(snake->getFirstBlock().getCoordinate());
		if (snake->breakTheWall(p->getM(), p->getN()) || snake->hitTheTail()) {
			system("cls");
			cout << "Game is over!!!" << endl << endl;
			cout << "YOUR SCORE IS : " << p->getScore() << endl;
			break;
		}
		p->putSsnakeToChart(snake, p->getPreyQueue().back());
		p->drawPlay();
		this_thread::sleep_for(chrono::milliseconds(50));
		
		
	}
	
}

int main()
{
	SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, 0);
	srand(time(NULL));
	cursorHide(false);

	Ssnake* snake = new Ssnake();
	Game* game = new Game(snake, 20, 50, "#", "#");
	UserInput* userInput = new UserInput();

	thread keyboardThread(thread_keyboard_listener, userInput, snake);
	thread playThread(thread_draw_chart, game, snake, userInput);

	keyboardThread.join();
	playThread.join();
}

