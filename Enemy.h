#ifndef ENEMY_H_INCLUDED
#define ENEMY_H_INCLUDED




class Enemy : public Base
{
    private:
        int enemy_health;
        char icon;
        int award;
        int positionY;
        int positionX;
        bool is_dead;
    public:
        Enemy();
        int getX()const {return positionX;}
        int getY()const {return positionY;}
        int getAward() const {return award;}
        int getEnemyHealth()const {return enemy_health;}
        char getIcon()const {return icon;}
        bool getIsDead()const {return is_dead;}
        void setX(int x);
        void setY(int y);
        void setIcon(char icon);
        void setAward(int award);
        void setEnemyhealth(int enemy_health);
        void setIsDead(bool is_dead);
        void isHit();
        void checkIsDead();

};

#endif // ENEMY_H_INCLUDED
