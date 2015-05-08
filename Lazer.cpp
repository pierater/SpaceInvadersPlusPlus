//////////////////////////
// Filename: Lazer.cpp
// Author: Martin Almaraz
// Date: Fri May  8 13:50:16 PDT 2015
//////////////////////////


#include "Lazer.h"
using namespace std;

Lazer::Lazer()
{
	icon = "|";

}

void Lazer::setIcon(char icon)
{
	this->icon = icon;
}

void Lazer::setX(int x)
{
	this->x = x;
}

void Lazer::setY(int y)
{
	this->y = y;
}
