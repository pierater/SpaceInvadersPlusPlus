// *****************
// driver.cpp
// *****************

#include "Enemy.h"
#include "Ship.h"
#include "Screen.h"
#include "Base.h"
#include "Lazer.h"

#include <iostream>
#include <ncurses.h>
#include <string>


using namespace std;

int main()
{
    Screen test_game;
    test_game.runGame();
    return 0;
}
