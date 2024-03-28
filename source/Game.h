#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <ctime>
#include <cstdlib>

#include "defines.h"
#include "Grasseaters.h"
#include "Hunter.h"

class Game
{
private:
    sf::RectangleShape background;
    sf::Texture backgroundTexture;

    sf::RenderWindow *window;
    sf::Event sfEvent;

    void initWindow();
    void initGrasseaters();
    void initHunters();
    void initBackground();
public:
    Game();
    virtual ~Game();

    void updateSFMLEvents();
    void update();
    void render();
    void run();
};
#endif