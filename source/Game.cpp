#include "Game.h"

void Game::initWindow() {
    this->window = new sf::RenderWindow(sf::VideoMode(800, 600), "biocenosis");
    this->window->setFramerateLimit(100);
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
    for (Entity& entity: entities){
        entity.move(1, 1);
        entity.render(this->window);
    }
    this->window->display();
}

Game::~Game() {
    delete this->window;
}

void Game::run() {
    entities.push_back(Entity());
    entities.push_back(Entity(100, 100));

    while (this->window->isOpen()) {
        this->update();
        this->render();
    }
}