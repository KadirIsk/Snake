#pragma once
#ifndef GAME_H
#define GAME_h

#include<iostream>
#include<string>
#include<math.h>
#include "Ssnake.h"
using namespace std;

class Game
{
	char** chart;
	int M;
	int N;
	string vBrick;
	string hBrick;
	deque<Coordinate> preyQueue;
	int score;
	int scoreMultiplier;
	int lengthOfSnake;
public:
	int getM() { return M; }
	void setM(int M) { this->M = M; }
	int getN() { return N; }
	void setN(int N) { this->N = N; }
	int getScore() { return this->score; }
	void setPreyQueue(deque<Coordinate>);
	deque<Coordinate> getPreyQueue() { return this->preyQueue; }
	void pushPrey(Coordinate);
	void popPrey() { preyQueue.pop_front(); }
	void generatePrey(Ssnake*);
	void computeScore(Ssnake*);
	void setChart(char**);
	char** getChart();
	void createChart();
	void initializeChart();
	void drawChart();
	void drawPlay();
	void printVBrick() { cout << vBrick; }
	void printHBrick() { cout << hBrick; }
	void printHorizontalWall();
	void putSsnakeToChart(Ssnake*, Coordinate);
	Game(Ssnake*, int, int, string, string);
	Game(Ssnake*);
	~Game();
};
#endif
