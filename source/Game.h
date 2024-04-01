#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <ctime>
#include <cstdlib>

#include "defines.h"
#include "Grass.h"
#include "Grasseaters.h"
#include "Hunter.h"
#include "Rain.h"

class Game
{
private:
    sf::RectangleShape background;
    sf::Texture backgroundTexture;

    sf::RenderWindow *window;
    sf::Event sfEvent;

    long grassCounter = 0;

    void initWindow();
    void initGrass();
    void initGrasseaters();
    void initHunters();
    void initBackground();
    void initRain();
    void initDestination();
    void initMusic();

public:
    Game();
    ~Game();

    void updateSFMLEvents();
    void update();
    void render();
    void run();
    static  sf::Clock dtClock;
    static float dt;
    static void updatedt();
};
#endif