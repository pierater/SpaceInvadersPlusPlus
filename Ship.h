// ***********************************************************************
// File: Ship.h
// Author: Juan Eduardo Garcia
// Description: This file constains the functions and variables related to
// the ship. These include health, position, movement(), lose_health(),
// getX
// ***********************************************************************

#ifndef SHIP_H
#define SHIP_H

using namespace std;

class Ship
{
    private:
        int health;
        int position_x;
        char ship;
        char ex_ship;

    public:
        // accessors
        int getHealth()const{return health;}
        int getX()const{return position_x;}
        char getShip()const{return ship;}
        char getExShip()const{return ex_ship;}

        // mutators
        void setHealth (int health);
        void setPosition (int position_x);
};
#endif // SHIP ends here