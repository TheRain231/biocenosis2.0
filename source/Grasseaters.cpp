//
// Created by Андрей Степанов on 28.03.2024.
//

#include "Grasseaters.h"

Grasseaters::Grasseaters() : Alives() {
    this->texture.loadFromFile("textures/sheep.png");
    this->shape.setSize(sf::Vector2f(SPRITE_SIZE, SPRITE_SIZE));
    this->shape.setTexture(&texture);
    for (int i = 0 ; i < 10 ; i++){
        grasseaters.push_back(Grasseaters());
    }
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
    //for (auto & entity: Grasseaters::grasseaters){
    //     entity.render(target);
    //}
}
