#include <iostream>
#include "Star.hpp"
#include "Game.hpp"

Star::Star() :_y(2) {
    int n = 1 + rand() % 77;
    _y = 2 + abs((rand() % 50) % HEIGHT - 7);
    _x = n;
}
Star::~Star() {

}

Star::Star(Star const &rhs) {

    *this = rhs;
}

Star    &Star::operator=(Star const &rhs) {
    _y = rhs._y;
    _x = rhs._x;
    return (*this);
}

int     Star::getY( void ) {
    return(this->_y);
}

int     Star::getX( void ) {
    return(this->_x);
}

void    Star::incrY( void ) {
    this->_y++;
}

void    Star::setXY( void ) {
    this->_y = 2 + abs((rand() % 50) % HEIGHT - 7);
    this->_x = 1 + rand() % 77;
}