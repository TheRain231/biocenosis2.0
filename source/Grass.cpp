//
// Created by 1ghaw on 28.03.2024.
//

#include "Grass.h"

Grass::Grass() : Entity() {
    sf::Vector2f pos(rand() % 20 * SPRITE_SIZE, rand() % 20 * SPRITE_SIZE);
    const int grassCount = grass.size();
    bool hasEnded = false;
    bool smallHasEnded = true;
    while (!hasEnded && grass.size() < (WINDOW_WIDTH / SPRITE_SIZE)) {
        for (int i = 0; i < grassCount; i++) {
            if (pos == grass[i]->shape.getPosition()) {
                pos = sf::Vector2f(rand() % 20 * SPRITE_SIZE, rand() % 20 * SPRITE_SIZE);
                smallHasEnded = false;
                break;
            }
        }
        if (smallHasEnded) {
            hasEnded = true;
            break;
        }
        smallHasEnded = true;
    }
    this->shape.setPosition(pos);
    this->shape.setSize(sf::Vector2f(SPRITE_SIZE, SPRITE_SIZE));
    this->shape.setTexture(&texture);
}

void Grass::renderVector(sf::RenderTarget *target) {
    for (auto &grasses: grass) {
        grasses->render(target);
    }
}

Grass::~Grass() {
    const int len = Grass::grass.size();
    int i;
    for (i = 0; i < len; i++) {
        if (Grass::grass[i] == this) {
            break;
        }
    }
    Grass::grass.erase(Grass::grass.begin() + i);
}

void Grass::initGrass() {
    Grass::texture.loadFromFile("textures/grass.png");
    for (int i = 0; i < GRASS_START; i++)
        Grass::grass.push_back(new Grass());
}

sf::Texture Grass::texture;
std::vector<Grass *> Grass::grass;