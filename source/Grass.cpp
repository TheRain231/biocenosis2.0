//
// Created by 1ghaw on 28.03.2024.
//

#include "Grass.h"

Grass::Grass() : Entity() {
    this->shape.setSize(sf::Vector2f(SPRITE_SIZE, SPRITE_SIZE));
    this->shape.setTexture(&texture);
}


void Grass::deleteObject() {

}

void Grass::renderVector(sf::RenderTarget* target) {
    for (auto &grasses : grass) {
        grasses->render(target);
    }
}

void Grass::update() {

}

sf::Texture Grass::texture;
std::vector<Grass*> Grass::grass;