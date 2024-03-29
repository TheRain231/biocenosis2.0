//
// Created by Лаба on 27.03.2024.
//

#include "Entity.h"

Entity::Entity() {
    this->shape.setOrigin((-rand() % (WINDOW_WIDTH - SPRITE_SIZE)), -(rand() % (WINDOW_HEIGHT - SPRITE_SIZE)));
}

Entity::Entity(const float x, const float y) {
//    this->shape.setSize(sf::Vector2f(SPRITE_SIZE, SPRITE_SIZE));
//    this->shape.setFillColor(sf::Color::White);
    this->shape.setOrigin(-x, -y);
}

Entity::~Entity() = default;

void Entity::update() {

}

void Entity::render(sf::RenderTarget *target) {
    target->draw(this->shape);
}

