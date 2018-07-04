
#ifndef ENEMY_HPP
#define ENEMY_HPP


#include <ostream>

class Enemy {
public:
    Enemy();
    ~Enemy();
    Enemy(const Enemy &rhs);

    Enemy  &operator=(Enemy const &rhs);
    void    setXY();
    void    incrY();

    int     getX( void );
    int     getY( void );

private:
    int    _y;
    int    _x;

};


#endif 