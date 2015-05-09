//////////////////////////
// Filename: Screen.cpp
// Author: Martin Almaraz
// Date: Sun Apr 19 21:00:59 PDT 2015
//////////////////////////


#include "Screen.h"
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <ncurses.h>
#include <iostream>
#include <stdio.h>
#include <pthread.h>

using namespace std;

Screen::Screen()
{
	//keypad(stdscr, TRUE);
	srand(time(NULL));
	playerScore = 0;
	ENEMIES = 10;
	XSIZE = 50;
	YSIZE = 50;
	int random;



	for(int i = 0; i < XSIZE; i++)
	{
		for(int j = 0; j < XSIZE; j++)
		{
			board[i][j] = new Enemy();
			board[i][j]->setIcon('~');
		}
	}
	
	for(int i = 0; i < ENEMIES; i++)
	{
		random = rand() % XSIZE;
		board[0][random]->setIcon('V');
	}
	delete board[50][XSIZE];
	board[50][XSIZE] = new Ship();
	board[50][XSIZE]->setIcon('A');

}

bool Screen::checkEndGame()
{
	if(player.getHealth() <= 0)
		return true;
	return true;
	//Other endgame things go here

}

void Screen::shiftDown()
{
	Base *temp[XSIZE][XSIZE];
	for(int i = 0; i < XSIZE; i++)
		for(int j = 0; j < XSIZE; j++)
			temp[i][j] = board[i][j];

	for(int i = 0; i < XSIZE; i++)
	{
		for(int j = 0; j < XSIZE; j++)
		{
		    if(i == 49)
                board[i][j]->setIcon('~');
			else if(temp[i][j]->getIcon() != 'A' && temp[i][j + 1]->getIcon() != '|')
				board[i+1][j] = temp[i][j];
			else if(temp[i][j]->getIcon() == '|')
				board[i][j] = temp[i][j];

		}
	}






	/*
	Enemy temp[XSIZE][XSIZE];
	for (int i = 0; i < XSIZE; i++)
		for(int j = 0; j < XSIZE; j++)
			temp[i][j] = board[i][j];
		// Copies board to a temp file

	for(int i = 1; i < XSIZE; i++)
	{
		int k = 0;
		for(int j = 0; j < XSIZE; j++)
		{
			if(j != player x && i != playery)
				board[i][j] = temp[k][j];
		}
	}

	for(int i = 0; i < XSIZE; i++)
	{
		board[i][0] = empty;
	}

	int random;
	srand(time(NULL));
	random = rand() % ENEMIES + 1;
	for(int i = 0; i < random; i++)
	{
		Enemy newEnemy("rand");
		random = rand() % 101;
		board[random][i] = newEnemy;
	}
*/

}


void Screen::increaseScore(int score)
{
	playerScore += score;
}

void Screen::displayScore()
{
	cout << "Score: " << playerScore;
}

void Screen::hitPlayer()
{
	player.setHealth(player.getHealth() - 1);
}

void Screen::displayHits()
{
	cout << "Hits: " << 3 - player.getHealth() << endl;
}

void Screen::displayScreen()
{
	for(int i = 0; i < XSIZE; i++)
	{
		for(int j = 0; j < XSIZE; j++)
			cout << board[i][j]->getIcon();
		cout << endl;
	}
	cout << "\t\t\t\t\t\t\t";
	displayHits();
	displayScore();
}

void Screen::clearScreen()
{
	for(int i = 0; i < XSIZE; i++)
		cout << "\n";
}

bool Screen::checkCollisions()
{
	for(int i = 0; i < XSIZE; i++)
	{
		for(int j = 0; j < XSIZE; j++)
		{
			if(board[i][j]->getIcon() == '*' && board[i + 1][j]->getIcon() == '|')
			{
				playerScore += board[i][j]->getAward();
				board[i][j]->setIcon('~');
			}
			else if(board[i][j]->getIcon() == 'V' && board[i][j + 1]->getIcon() == 'A')
			{
				// player hits - 1, spaceship is no longer there
			}
		}
	}

}

void Screen::playGame()
{

	do
	{
		
		displayScreen();
		getInput();
		checkCollisions();
		clearScreen();
		sleep(1);
		//shiftDown();


	}while(checkEndGame());
}

void Screen::getInput()
{
	int input;
	input = getch();
	cbreak();

	if(input == 97)
		moveLeft();
	else if(input == 100)
		moveRight();
	else if(input == 109)
		shoot();
	return;


}

void Screen::moveLeft()
{
	if(player.getX() - 1 >= 0)
		player.setPosition(player.getX() - 1);
	else
		player.setPosition(player.getX());
}

void Screen::moveRight()
{
	if(player.getX() + 1 < XSIZE)
		player.setPosition(player.getX() + 1);
	else
		player.setPosition(player.getX());


}

void Screen::shoot()
{
	cout << "SHOOOOOOOOTTT\n";

}

Screen::~Screen()
{
	for(int i = 0; i < XSIZE; i++)
		for(int j = 0; j < XSIZE; j++)
			delete board[i][j];
}

void Screen::endGame()
{
	for(int i = 0; i < XSIZE; i++)
		cout << endl;

	cout << "\t\t\tSCORE: " << playerScore << endl;
	cout << "\t\t\tGAME OVER\n\n\n";

}

void Screen::sleep(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}






