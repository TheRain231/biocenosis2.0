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

Grasseaters::~Grasseaters(){

}

void Grasseaters::renderGrasseaters(sf::RenderTarget *target) {
    for (auto & entity: eaters){
         entity->render(target);
    }
}

void Grasseaters::setTexture() {
    texture.loadFromFile("textures/sheep.png");
}

std::vector<Grasseaters*> Grasseaters::eaters = {new Grasseaters(), new Grasseaters(), new Grasseaters(), new Grasseaters()};