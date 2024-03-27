#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <ctime>
#include <cstdlib>

#include "defines.h"
#include "Entity.h"

class Game
{
private:
    std::vector<Entity> entities;
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