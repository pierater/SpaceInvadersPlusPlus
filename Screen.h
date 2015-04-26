//////////////////////////
// Filename: Screen.h
// Author: Martin Almaraz
// Date: Sun Apr 19 21:00:59 PDT 2015
//////////////////////////

#ifndef SCREEN_H
#define SCREEN_H
#include "Enemy.h"

using namespace std;

class Screen
{
	private:
		Enemy board[100][100];
		int playerHits;
		int playerScore;
		Enemy empty;
		int ENEMIES;

	public:
	    Screen();
		void shiftDown();
		bool checkEndGame();
		void increaseScore(int score);
		void displayScreen();
		void displayScore();
		void hitPlayer();
		bool checkCollisions();
		void endGame();
		void displayHits();
		void clearScreen();
};

#endif
