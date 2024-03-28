//
// Created by Андрей Степанов on 28.03.2024.
//

#include "Hunter.h"

Hunter::Hunter() : Alives() {
    this->shape.setSize(sf::Vector2f(SPRITE_SIZE, SPRITE_SIZE));
    this->shape.setTexture(&texture);
}

void Hunter::findFood() {

}

void Hunter::findSex() {

}

void Hunter::deleteObject() {

}

void Hunter::setTexture() {
    texture.loadFromFile("textures/sheep.png");
}