//////////////////////////
// Filename: Screen.h
// Author: Martin Almaraz
// Date: Sun Apr 19 21:00:59 PDT 2015
//////////////////////////

#ifndef SCREEN_H
#define SCREEN_H
#include "Enemy.h"
#include "Ship.h"
#include "Base.h"
#include <ncurses.h>

using namespace std;

class Screen
{
	private:
		Base *board[100][100];	
		int playerScore;
		Enemy empty;
		int ENEMIES;
		Ship player;

	public:
	    Screen();
		void playGame();
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
		void getInput();
		void moveLeft();
		void moveRight();
		void shoot();
};

#endif
