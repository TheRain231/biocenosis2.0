#include "Game.h"

void Game::initWindow() {
    this->window = new sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE);
    this->window->setFramerateLimit(FPS);
}

Game::Game() {
    this->initWindow();
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

    Grasseaters::renderGrasseaters(this->window);

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