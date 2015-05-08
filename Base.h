	//////////////////////////
// Filename: Base.h
// Author: Martin Almaraz
// Date: Fri May  8 13:49:48 PDT 2015
//////////////////////////

#ifndef BASE_H
#define BASE_H

using namespace std;

class Base
{
    private:
    public:
        Base();
		virtual void setIcon(char icon) = 0;
};

#endif
