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
using namespace std;

Screen::Screen()
{
	playerScore = 0;
	ENEMIES = 10;
	
	
	
	for(int i = 0; i < 100; i++)
	{
		for(int j = 0; j < 100; j++)
		{
			board[i][j] = new Enemy();
			board[i][j]->setIcon(' ');
		}
	}
	delete board[50][100];
	board[50][100] = new Ship();
	board[50][100]->setIcon('A');
		
}

bool Screen::checkEndGame()
{
	if(player.getHealth() <= 0)
		endGame();
	//Other endgame things go here

}

void Screen::shiftDown()
{
	Base *temp[100][100];
	for(int i = 0; i < 100; i++)
		for(int j = 0; j < 100; j++)
			temp[i][j] = board[i][j];
		
	for(int i = 0; i < 100; i++)
	{
		for(int j = 0; j < 100; j++)
		{
			if(temp[i][j]->getIcon() != 'A' && temp[i][j + 1]->getIcon() != '|')
				board[i+1][j] = temp[i][j];
			else if(temp[i][j]->getIcon() == '|')
				board[i][j] = temp[i][j];
			
		}
	}
			





	/*
	Enemy temp[100][100];
	for (int i = 0; i < 100; i++)
		for(int j = 0; j < 100; j++)
			temp[i][j] = board[i][j]; 
		// Copies board to a temp file
	
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
	for(int i = 0; i < 100; i++)
	{
		for(int j = 0; j < 100; j++)
			cout << board[i][j]->getIcon();
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
	{
		for(int j = 0; j < 100; j++)
		{
			if(board[i][j]->getIcon() == '*' && board[i + 1][j]->getIcon() == '|')
			{
				playerScore += board[i][j]->getAward();
				board[i][j]->setIcon(' ');
			}
			else if(board[i][j]->getIcon() == '*' && board[i][j + 1]->getIcon() == 'A')
			{
				// player hits - 1, spaceship is no longer there
			}
		}
	}
				
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
	if(player.getX() - 1 >= 0)
		player.setPosition(player.getX() - 1);
	else
		player.setPosition(player.getX());
}

void Screen::moveRight()
{
	if(player.getX() + 1 < 100)
		player.setPosition(player.getX() + 1);
	else
		player.setPosition(player.getX());


}

void Screen::shoot()
{
	cout << "shoot\n";

}








