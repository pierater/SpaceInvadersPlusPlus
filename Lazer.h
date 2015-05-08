//////////////////////////
// Filename: Lazer.h
// Author: Martin Almaraz
// Date: Fri May  8 13:50:16 PDT 2015
//////////////////////////

#ifndef LAZER_H
#define LAZER_H
#include "Base.h"
using namespace std;

class Lazer: public Base
{
    private:
		char icon;
		int x;
		int y;
    public:
        Lazer();
		char getIcon() const {return icon;}
		int getx() const {return x;}
		int gety() const {return y;}
		
		void setIcon(char icon);
		void setX(int x);
		void setY(int y);
		
};

#endif
