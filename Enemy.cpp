
#include "Enemy.h"
#include <cassert>

using namespace std;
Enemy::Enemy()
{
    positionX = 0;
    positionY = 0;
    icon = '*';
    award = 100;
    enemy_health = 1;
    is_dead = false;
}
void Enemy::setX(int x)
{
    positionX = x;
}
void Enemy::setY(int y)
{
    positionY = y;
}
void Enemy::setIcon(char icon)
{
    this -> icon = icon;
}
void Enemy::setAward(int award)
{
    this -> award = award;
}
void Enemy::setEnemyHealth(int enemy_health)
{
    this -> enemy_health = enemy_health;
}
void Enemy::setIsDead(bool is_dead)
{
    this -> is_dead = is_dead;
}
void Enemy::isHit()
{
    assert(enemy_health > 0);
    enemy_health--;
}
void Enemy::checkIsDead()
{
    if (enemy_health == 0)
        is_dead = true;
}
