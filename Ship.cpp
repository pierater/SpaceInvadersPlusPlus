// ****************************
// ship.cpp
// ****************************
using namespace std;

Ship::Ship()
{
    health = 3;
    position = 10; // this will be changed later to make sure that it will be at center
    ship = 'A';
    ex_ship = 'X';
}

void setHealth (int health)
{
    this->health = health;
}

void setPosition(int position_x)
{
    this->position_x = position_x;
}
