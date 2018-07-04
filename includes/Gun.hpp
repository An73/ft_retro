

#ifndef RUSH00_GUN_HPP
#define RUSH00_GUN_HPP


class Gun {
public:
    Gun( void );
    ~Gun();
    Gun(Gun const &rhs);
    Gun &operator=(Gun const &rhs);

    void    decr_y( void );
    void    setX(int x);
    void    setY(int y);

    int     getX( void );
    int     getY( void );
    void    setXY();

private:
    int _x;
    int _y;
    int _speed;
};


#endif
