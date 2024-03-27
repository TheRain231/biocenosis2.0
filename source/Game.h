#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <ctime>
#include <cstdlib>

#include "defines.h"

class Game
{
private:
    sf::RenderWindow *window;
    sf::Event sfEvent;
    void initWindow();
public:
    Game();
    virtual ~Game();

    //funcs

    void updateSFMLEvents();
    void update();
    void render();
    void run();
};
#endif