#ifndef STAR_HPP
#define STAR_HPP

#include <ostream>

class Star {
public:
    Star();
    ~Star();
    Star(const Star &rhs);

    Star  &operator=(Star const &rhs);
    void    setXY();
    void    incrY();

    void    setX(int x);
    void    setY(int y);

    int     getX( void );
    int     getY( void );

private:
    int    _y;
    int    _x;

};


#endif 