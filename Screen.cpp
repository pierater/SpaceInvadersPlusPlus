//////////////////////////
// Filename: Screen.cpp
// Author: Martin Almaraz
// Date: Sun Apr 19 21:00:59 PDT 2015
//////////////////////////


#include "Screen.h"
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <ncurses>
#include <iostream>
using namespace std;

Screen::Screen()
{
	playerScore = 0;
	ENEMIES = 10;
	
	for(int i = 0; i < 100; i++)
		for(int j = 0; j < 100; j++)
			board[i][j].setIcon(' ');
		
}

bool Screen::checkEndGame()
{
	if(player.health <= 0)
		endGame();
	//Other endgame things go here

}

void Screen::shiftDown()
{
	Enemy temp[100][100];
	for (int i = 0; i < 100; i++)
		for(int j = 0; j < 100; j++)
			temp[i][j] = board[i][j];
	
	for(int i = 1; i < 100; i++)
	{
		int k = 0;
		for(int j = 0; j < 100; j++)
		{
			if(j != player x && i != playery)
				board[i][j] = temp[k][j];	
		}
	}

	for(int i = 0; i < 100; i++)
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
	
}


void Screen::increaseScore(int score)
{
	playerScore += score;	
}

void Screen::displayScore()
{
	cout << "Score: " << score;
}

void Screen::hitPlayer()
{
	playerHits++;
}

void Screen::displayHits()
{
	cout << "Hits: " << playerHits;
}

void Screen::displayScreen()
{
	for(int i = 0; i < 100; i++)
	{
		for(int j = 0; j < 100; j++)
			cout << board.getIcon();
		cout << endl;
	}
	cout << "\t\t\t";
	displayHits();
	displayScore();
}

void Screen::clearScreen()
{
	for(int i = 0; i < 100; i++)
		cout << "\n";
}

bool Screen::checkCollisions()
{
	for(int i = 0; i < 100; i++)
		if(board[0][i].isEnemy() && playery == i)
			playerHits++;
}

void Screen::playGame()
{
	
}

void Screen::getInput()
{
	char input;
	input = getch();
	cbreak();
	
	if(input == 'a')
		moveLeft();
	else if(input == 'd')
		moveRight();
	else if(input == ' ')
		shoot();
	return;	
	

}

void Screen::moveLeft()
{
	if(player.getx() - 1 >= 0)
		player.setPosition(player.getx() - 1);
	else
		player.setPosition(player.getx());
}

void Screen::moveRight()
{
	if(player.getx() + 1 < 100)
		player.setPosition(player.getx() + 1)
	else
		player.setPosition(player.getx());


}

void Screen::shoot()
{
	cout << "shoot\n";

}








