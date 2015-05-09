// ****************************
// ship.cpp
// ****************************
#include "Ship.h"
#include "Base.h"
using namespace std;

Ship::Ship()
{
    health = 3;
    position_x = 25; // this will be changed later to make sure that it will be at center
    ship = 'A';
    ex_ship = 'X';
}

void Ship::setHealth (int health)
{
    this->health = health;
}

void Ship::setPosition(int position_x)
{
    this->position_x = position_x;
}

void Ship::setIcon(char icon)
{
	ship = icon;
}

int Ship::getAward()
{

}

