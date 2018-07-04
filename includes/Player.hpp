

#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <iostream>
#include "Gun.hpp"

class Player {
public:
    Player(int x, int y);
    ~Player();
    Player(const Player &rhs);
    Player  &operator=(Player const &rhs);

    Gun     gun[150];
    void    shoot( void );
    void    shoot_up( void );
    void    set (int target);
    int     get( int target);

private:
    int _x;
    int _y;
    int _num_shoot;
    int _life;
    int _score;
};


#endif