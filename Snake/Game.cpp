#include "Game.h"


Game::Game(Ssnake* snake)
{
	this->M = 20;
	this->N = 50;
	this->score = 0;
	this->lengthOfSnake = 2;
	this->scoreMultiplier = 40;
	this->hBrick = "_";
	this->vBrick = "|";
	this->chart = NULL;
	createChart();
	initializeChart();
	generatePrey(snake);
}

Game::Game(Ssnake* snake, int M, int N, string hBrick = "_", string vBrick = "|") {
	this->M = M;
	this->N = N;
	this->score = 0;
	this->lengthOfSnake = 2;
	this->scoreMultiplier = 40;
	this->hBrick = hBrick;
	this->vBrick = vBrick;
	this->chart = NULL;
	createChart();
	initializeChart();
	generatePrey(snake);
}

Game::~Game()
{
}

void Game::setChart(char** chart) {
	this->chart = chart;
}

char** Game::getChart() {
	return this->chart;
}

void Game::createChart() {
	chart = new char* [M];
	for (int i = 0; i < M; i++)
		chart[i] = new char[N];
}

void Game::initializeChart() {
	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
			chart[i][j] = ' ';
}

void Game::drawChart() {
	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
			cout << chart[i][j];
}

void Game::putSsnakeToChart(Ssnake* ssnake, Coordinate prey) {
	deque<Block> snake = ssnake->getListOfBlock();
	initializeChart();
	for (deque<Block>::iterator it = snake.begin(); it != snake.end(); ++it) {
		chart[it->getCoordinate().getX()][it->getCoordinate().getY()] = '*';
	}
	chart[prey.getX()][prey.getY()] = (char)254u;
}

void Game::drawPlay() {
	printHorizontalWall();
	cout << endl;
	for (int i = 0; i < M; i++) {
		printVBrick();
		for (int j = 0; j < N; j++)
			cout << chart[i][j];
		printVBrick();
		cout << endl;
	}
	printHorizontalWall();
	cout << endl << endl;

	cout << "SCORE : " << score << endl;
	cout << "SNAKE LENGTH : " << lengthOfSnake << endl;
}

void Game::printHorizontalWall() {
	for (int i = 0; i < N + 2; i++) {
		printHBrick();
	}
}

void Game::setPreyQueue(deque<Coordinate> preyQueue) {
	this->preyQueue = preyQueue;
	
}

void Game::generatePrey(Ssnake* snake) {
	Coordinate prey;
	bool flag = true;
	deque<Block> listOfBlock = snake->getListOfBlock();

	while (flag) {
		flag = false;
		prey.setX(rand() % M);
		prey.setY(rand() % N);

		for (deque<Block>::iterator it = listOfBlock.begin(); it != listOfBlock.end(); ++it) {
			if (it->getCoordinate() == prey) {
				flag = true;
				break;
			}
		}
	}

	preyQueue.push_back(prey);
}

void Game::computeScore(Ssnake* snake) {
	Coordinate prey = preyQueue.back();
	if (snake->getLastBlock().getCoordinate() == prey) {
		generatePrey(snake);
		deque<Block> listOfBlock = snake->getListOfBlock();
		lengthOfSnake++;
		score += (int)(log(lengthOfSnake) * scoreMultiplier);
	}
	
}

void Game::pushPrey(Coordinate coordinate) {
	this->preyQueue.push_back(coordinate);
}