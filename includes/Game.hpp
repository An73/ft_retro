

#ifndef GAME_HPP
#define GAME_HPP
#include "Enemy.hpp"
#include "Player.hpp"
#include "Star.hpp"
#include <ncurses.h>
#include <zconf.h>
#define WIDTH 80
#define HEIGHT 55
#define BORDER 1
#define D 100
#define S 115
#define A 97
#define W 119
#define SPACE 32
#define ASTEROIDS 20
#define GUNS 150
#define MINUS_NUM_PAD 45
#define PLUS_NUM_PAD 43

class Game {
public:
    Game();
    ~Game();
    Game(const Game &rhs);
    Game  &operator=(Game const &rhs);
    void    run( void );
    Enemy enemy[20];
    Star    star[100];

private:
    int  _timer_e;
    useconds_t _speed;
    WINDOW  *_win;

};

#endif
