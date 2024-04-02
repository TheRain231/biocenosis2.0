#include "Game.h"

void Game::initWindow() {
    this->window = new sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE);
    this->window->setFramerateLimit(FPS);
}

void Game::initGrasseaters() {
    Grasseaters::texture.loadFromFile("textures/sheep.png");
    for (int i = 0; i < GRASSEATERS_START; i++)
        Grasseaters::grasseaters.push_back(new Grasseaters());
}

void Game::initHunters() {
    Hunter::texture.loadFromFile("textures/hunter.png");
    for (int i = 0; i < HUNTERS_START; i++)
        Hunter::hunters.push_back(new Hunter());
}

void Game::initBackground() {
    backgroundTexture.loadFromFile("textures/background.png");
    background.setSize(sf::Vector2f(WINDOW_WIDTH, WINDOW_HEIGHT));
    background.setTexture(&backgroundTexture);
}


void Game::initGrass() {
    Grass::texture.loadFromFile("textures/grass.png");
    for (int i = 0; i < GRASS_START; i++)
        Grass::grass.push_back(new Grass());
}

void Game::initRain() {
    Rain::rain.push_back(new Rain(0, 0));
    Rain::rain.push_back(new Rain(0, WINDOW_HEIGHT));
}

void Game::initDestination() {
    for (auto obj: Hunter::hunters) {
        obj->setRandomDestination();
    }
    for (auto obj: Grasseaters::grasseaters) {
        obj->setRandomDestination();
    }
}


Game::Game() {
    this->initWindow();
    this->initGrass();
    this->initGrasseaters();
    this->initHunters();
    this->initBackground();
    this->initRain();
    this->initDestination();
    Particles::initParticles();
}

void Game::updateSFMLEvents() {
    while (this->window->pollEvent(this->sfEvent)) {
        if (this->sfEvent.type == sf::Event::Closed)
            this->window->close();
    }
}

void Game::update() {
    this->updateSFMLEvents();
    const int huntersCount = Hunter::hunters.size();
    int grasseatersCount = Grasseaters::grasseaters.size();
    if (grasseatersCount < 1) {
        std::cout << "Всех съели" << '\n';
        this->window->close();
        return;
    }
    if (huntersCount < 1) {
        std::cout << "Все сдохли" << '\n';
        this->window->close();
        return;
    }
    for (int i = 0; i < huntersCount; i++) {
        Hunter::hunters[i]->update();
        Hunter::hunters[i]->findWalk();
    }
    grasseatersCount = Grasseaters::grasseaters.size();
    for (int i = 0; i < grasseatersCount; i++) {
        Grasseaters::grasseaters[i]->update();
        Grasseaters::grasseaters[i]->findWalk();
    }
    if (Rain::rain[0]->checkState()) {
        grassCounter++;
        if (grassCounter % 10 == 0)
            Grass::grass.push_back(new Grass);
    }
}

void Game::render() {
    this->window->clear();
    this->window->draw(background);
    Rain::rain[0]->checkState();
    Grass::renderVector(this->window);
    Grasseaters::renderVector(this->window);
    Hunter::renderVector(this->window);
    Rain::renderVector(this->window);
    Particles::renderVector(this->window);
    this->window->display();
}

Game::~Game() {
    delete this->window;
}

void Game::run() {
    while (this->window->isOpen()) {
        Game::updatedt();
        this->update();
        this->render();
    }
}

void Game::updatedt() {
    dt = dtClock.restart().asSeconds();
}

sf::Clock Game::dtClock;
float Game::dt;