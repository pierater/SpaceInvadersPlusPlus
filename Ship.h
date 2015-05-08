// ***********************************************************************
// File: Ship.h
// Author: Juan Eduardo Garcia
// Description: This file constains the functions and variables related to
// the ship. These include health, position, movement(), lose_health(),
// getX
// ***********************************************************************

#ifndef SHIP_H
#define SHIP_H
#include "Base.h"

using namespace std;

class Ship: public Base
{
    private:
        int health;
        int position_x;
        char ship;
        char ex_ship;

    public:
        // accessors
		Ship();
        int getHealth()const{return health;}
        int getX()const{return position_x;}
        char getShip()const{return ship;}
        char getExShip()const{return ex_ship;}

        // mutators
        void setHealth (int health);
        void setPosition (int position_x);
		void setIcon(char icon);
};
#endif // SHIP ends here
