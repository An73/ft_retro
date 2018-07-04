
#include "Game.hpp"

Game::Game() : _timer_e(0), _speed(25000) {
}
Game::~Game() {

}

Game::Game(Game const &rhs) {
    *this = rhs;
}

Game    &Game::operator=(Game const &rhs)
{
    _timer_e = rhs._timer_e;
    _speed = rhs._speed;
    return (*this);
}


void    Game::run( void ) {
    setlocale(LC_ALL, "");
    int  c = 0;

    initscr();
    cbreak();
    noecho();
    curs_set(0);
    nodelay (stdscr, TRUE);
    keypad(stdscr, TRUE);
    start_color();
    init_pair(1,COLOR_WHITE, COLOR_BLACK);
    init_pair(2,COLOR_RED, COLOR_BLACK);
    init_pair(3,COLOR_YELLOW, COLOR_BLACK);

    Player *player = new Player(30,34);
    WINDOW * win_info = newwin(50, WIDTH, 0, 5);
    this->_win = newwin(HEIGHT, WIDTH , 0, 0);
    box(_win, 0, 0);
    wbkgd(_win, COLOR_PAIR(1));
    mvwprintw(_win, 49, 1, "------------------------------------------------------------------------------");
    mvwprintw(_win, 51, 4, "lives: ");
    mvwprintw(_win, 52, 4, "score: ");
    mvwprintw(_win, 51, 24, "speed: ");
    refresh();
    wrefresh(_win);

    while (c != 27 && player->get(3) > 0 ) {
        mvwprintw(_win, 51, 11, "❤ >> %d << ❤",  player->get(3));
        mvwprintw(_win, 52, 11, "★ >> %d << ★",  player->get(4));
        mvwprintw(_win, 51, 31, ">> %d <<", _speed);
        mvwprintw(_win, player->get(2),  player->get(1), " ");


        for (int i = 0; i < 150; i++) {
            mvwaddch(_win,  player->gun[i].getY() + 1,  player->gun[i].getX(), ' ');
            if (_timer_e > 10 && _timer_e % 5 == 0)
                mvwaddch(_win, this->enemy[i].getY() - 1, this->enemy[i].getX(), ' ');
        }
        for (int i = 0; i < 100; i++) {
            if (_timer_e % 2 == 0) {
                mvwaddch(_win, this->star[i].getY(), this->star[i].getX(), ' ');
            }

        }
        if ((c == D || c == KEY_RIGHT) &&  player->get(1) < WIDTH - 2)
            player->set(1);
        else if ((c == S || c == KEY_DOWN) &&  player->get(2) < HEIGHT - 7)
            player->set(3);
        else if ((c == A || c == KEY_LEFT) &&  player->get(1) > BORDER)
            player->set(2);
        else if ((c == W || c == KEY_UP) &&  player->get(2) > BORDER)
            player->set(4);
        else if (c == SPACE) {
            system("afplay -t 0.5 hit.mp3 > /dev/null &");
            player->shoot();
        }

        else if (c == PLUS_NUM_PAD) {
            if (this->_speed >= 5000)
                this->_speed -= 500;
        }
        else if (c == MINUS_NUM_PAD) {
            if (this->_speed < 25000)
                this->_speed += 500;
        }
        for (int i = 0; i < 100; i++) {
            if (this->star[i].getY() == HEIGHT - 7) {
                mvwprintw(_win, this->star[i].getY(), this->star[i].getX(), " ");
                this->star[i].setXY();
            }
        }
        for (int i = 0; i < 100; i++) {
            if (_timer_e % 2 == 0) {
                star[i].incrY();
                for (int k = 0; k < 20; k++) {
                    if (abs(enemy[k].getY() - star[i].getY()) > 2 && enemy[k].getX() == star[i].getX())
                        this->star[i].setXY();
                }
                mvwprintw(_win, this->star[i].getY(), this->star[i].getX(), ".");
            }

        }
        for (int i = 0; i < ASTEROIDS; i++) {
            if (this->enemy[i].getY() == HEIGHT - 7) {
                mvwprintw(_win, this->enemy[i].getY() - 1, this->enemy[i].getX(), " ");
                this->enemy[i].setXY();
            }
            else if (_timer_e > 10 && _timer_e % 5 == 0) {

                wattron(_win, COLOR_PAIR(2));
                mvwprintw(_win, this->enemy[i].getY(), this->enemy[i].getX(), "❽");
                wattroff(_win, COLOR_PAIR(2));
                this->enemy[i].incrY();
            }
            if (player->get(2) == this->enemy[i].getY() - 2 &&  player->get(1) == this->enemy[i].getX()) {
                mvwprintw(_win, this->enemy[i].getY() - 1, this->enemy[i].getX(), " ");
                this->enemy[i].setXY();
                player->set(5);
            }
        }
        for (int i = 0; i < GUNS; i++) {
            if ( player->gun[i].getY() != 1) {
                wattron(_win, COLOR_PAIR(3));
                mvwprintw(_win,  player->gun[i].getY(),  player->gun[i].getX(), "⁂");
                wattroff(_win, COLOR_PAIR(3));
            }
            for (int j = 0; j < ASTEROIDS; j++) {
                if (abs( player->gun[i].getY() - this->enemy[j].getY()) < 2 &&  player->gun[i].getX() == this->enemy[j].getX()){
                    mvwaddch(_win, this->enemy[j].getY(), this->enemy[j].getX(), ' ');
                    this->enemy[j].setXY();
                     player->set(6);
                }
            }
            if (player->gun[i].getY() == 1)
                player->gun[i].setXY();
        }
        attron(COLOR_PAIR(1));
        mvwprintw(_win,  player->get(2),  player->get(1), "ൠ");
        wrefresh(_win);
        c = getch();
        player->shoot_up();
        usleep(_speed);
        _timer_e++;
    }
    clear();
    while (c != 27) {
        c = getch();
        mvwprintw(win_info, 27, 0, "    ★★★★★★★★★★★★★★★★★★★★★★★★★★★  YOUR  SCORE %d    ★★★★★★★★★★★★★★★★★★★★★★★★★★    ",  player->get(4));
        mvwprintw(win_info, 28, 0, "                                  Press \"Esc\"                                ");
        wrefresh(win_info);
        if (c == 32)
            break;

    }
    clear();
    getch();
    endwin();
    delete(player);
}
