
#include <iostream>
#include "Enemy.hpp"
#include "Game.hpp"

Enemy::Enemy() :_y(2) {
    int n = 1 + rand() % 77;
    _y = 2 + abs((rand() % 12) % HEIGHT - 7);
    _x = n;
}
Enemy::~Enemy() {

}

Enemy::Enemy(Enemy const &rhs) {

    *this = rhs;
}

Enemy    &Enemy::operator=(Enemy const &rhs)
{
    _y = rhs._y;
    _x = rhs._x;
    return (*this);
}

void    Enemy::setXY()
{
    this->_y = 2 + abs((rand() % 12) % HEIGHT - 7);
    this->_x = 1 + rand() % 77;
}

void    Enemy::incrY()
{
    this->_y++;
}

int    Enemy::getX(void) {
    return (this->_x);
}

int    Enemy::getY(void) {
    return (this->_y);
}
