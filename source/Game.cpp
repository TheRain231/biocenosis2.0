#include "Game.h"


void Game::initWindow() {
    this->window = new sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE);
    this->window->setFramerateLimit(FPS);
}

void Game::initGrasseaters() {
    for (int i = 0; i < 10; i++)
        Grasseaters::grasseaters.push_back(new Grasseaters());
}

Game::Game() {
    this->initWindow();
    this->initGrasseaters();
}

void Game::updateSFMLEvents() {
    while (this->window->pollEvent(this->sfEvent)) {
        if (this->sfEvent.type == sf::Event::Closed)
            this->window->close();
    }
}

void Game::update() {
    this->updateSFMLEvents();
}

void Game::render() {
    this->window->clear();
    this->window->draw(background);
    Grasseaters::renderVector(this->window);
    this->window->display();
}

Game::~Game() {
    delete this->window;
}

void Game::run() {

    backgroundTexture.loadFromFile("textures/background.png");
    background.setSize(sf::Vector2f(WINDOW_WIDTH, WINDOW_HEIGHT));
    background.setTexture(&backgroundTexture);

    while (this->window->isOpen()) {
        this->update();
        this->render();
    }
}