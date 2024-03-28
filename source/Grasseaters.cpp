//
// Created by Андрей Степанов on 28.03.2024.
//

#include "Grasseaters.h"

Grasseaters::Grasseaters() : Alives() {
    this->shape.setSize(sf::Vector2f(SPRITE_SIZE, SPRITE_SIZE));
    this->shape.setTexture(&texture);
}

void Grasseaters::findFood() {

}

void Grasseaters::findSex() {

}

void Grasseaters::deleteObject() {

}

void Grasseaters::renderVector(sf::RenderTarget* target) {
    for (auto &eater : grasseaters) {
        eater->render(target);
    }
}

std::vector<Grasseaters*> Grasseaters::grasseaters;
sf::Texture Grasseaters::texture;