//
// Created by Андрей Степанов on 27.03.2024.
//

#include "Entity.h"

Entity::Entity() {
    this->sprite.setScale(sf::Vector2f(SPRITE_SIZE, SPRITE_SIZE));
    this->sprite.setColor(sf::Color::White);
}

Entity::~Entity() {

}

void Entity::update() {

}

void Entity::render(sf::RenderTarget &target) {

}

void Entity::move(const float x, const float y) {
    this->sprite.move(sf::Vector2f(x, y));
}