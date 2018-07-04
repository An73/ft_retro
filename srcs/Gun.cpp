
#include "Gun.hpp"
#include "Game.hpp"

Gun::Gun( void ) : _x(-1), _y(-1){

}
Gun::~Gun() {

}

Gun::Gun(Gun const &rhs) {
    *this = rhs;
}

Gun    &Gun::operator=(Gun const &rhs)
{
    _x = rhs._x;
    _y = rhs._y;
    _speed = rhs._speed;
    return (*this);
}

void    Gun::decr_y( void ) {
    if (_y > 1)
        this->_y--;
}


void    Gun::setX(int x) {
    this->_x = x;
}

void    Gun::setY(int y) {
    this->_y = y;
}

int    Gun::getX(void) {
    return (this->_x);
}

int    Gun::getY(void) {
    return (this->_y);
}


void    Gun::setXY()
{
    this->_y = -1;
    this->_x = -1;
}
