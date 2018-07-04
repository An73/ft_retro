

#include "Player.hpp"

Player::Player(int x, int y) :_x(x), _y(y) , _num_shoot(0), _life(3), _score(0){
}
Player::~Player() {

}

Player::Player(Player const &rhs) {
    *this = rhs;
}

Player    &Player::operator=(Player const &rhs)
{
    _life = rhs._life;
    _score = rhs._score;
    _num_shoot = rhs._num_shoot;
    return (*this);
}

void    Player::shoot( void ) {
    this->gun[this->_num_shoot].setX(this->_x);
    this->gun[this->_num_shoot].setY(this->_y - 1);
    if (this->_num_shoot < 150)
        this->_num_shoot++;
    else
        this->_num_shoot = 0;
}

void    Player::shoot_up( void ) {
    for (int i = 0; i < 150; i++) {
        if (gun[i].getY() > 0)
            gun[i].decr_y();
    }
}

int     Player::get(int type)
{
    if (type == 1)
        return (this->_x);
    else if (type == 2)
        return (this->_y);
    else if (type == 3)
        return (this->_life);
    else if (type == 4)
        return (this->_score);
    return false;
}

void    Player::set(int type)
{
    if (type == 1)
        this->_x++;
    else if (type == 2)
        this->_x--;
    else if (type == 3)
        this->_y++;
    else if (type == 4)
        this->_y--;
    else if (type == 5)
        this->_life--;
    else if (type == 6)
        this->_score++;
}

