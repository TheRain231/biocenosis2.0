//
// Created by Лаба on 27.03.2024.
//

#include "Entity.h"

Entity::Entity() {
    texture.loadFromFile("textures/face.png");
    this->shape.setSize(sf::Vector2f(SPRITE_SIZE, SPRITE_SIZE));
    this->shape.setTexture(&texture);
}

Entity::Entity(const float x, const float y) {
    this->shape.setSize(sf::Vector2f(SPRITE_SIZE, SPRITE_SIZE));
    this->shape.setFillColor(sf::Color::White);
    this->shape.setOrigin(-x, -y);
}

Entity::~Entity() {

}

void Entity::update() {

}

void Entity::render(sf::RenderTarget *target) {
    target->draw(this->shape);
}

void Entity::move(const float x, const float y) {
    this->shape.move(sf::Vector2f(x, y));
}