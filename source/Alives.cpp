//
// Created by Андрей Степанов on 28.03.2024.
//

#include "Alives.h"
#include <iostream>
#include "Game.h"

Alives::~Alives() {

}

Alives::Alives(): Entity() {
    currentState = walk;
}

void Alives::update() {
    this->hunger += 1;
    this->liveTime += 1;
    this->needOfSex += 1;
    if (liveTime > LIFE_TIME){
        currentState = dead;
    }
    else if (hunger > HUNGER_DEATH){
        currentState = dead;
    }
    else if (hunger > HUNGER){
        findFood();

    }
    else if (needOfSex > SEX){
        findSex();
    }
    else {
        currentState = walk;
    }
    checkState();


}

void Alives::checkState(){
    switch (currentState) {
        case dead:
            deleteObject();
            break;
        case eat:
            findFood();
            break;
        case sex:
            findSex();
            break;
        case walk:
            break;
    }
}

void Alives::move(const float x, const float y) {
    if (this->shape.getPosition().x+x>0 && this->shape.getPosition().y+y>0 || this->shape.getPosition().x+x<WINDOW_HEIGHT-SPRITE_SIZE && this->shape.getPosition().y+y<WINDOW_HEIGHT-SPRITE_SIZE)
        this->shape.move(x, y);
}

void Alives::move(sf::Vector2f change) {
    if (this->shape.getPosition().x+change.x>0 && this->shape.getPosition().y+change.y>0 || this->shape.getPosition().x+change.x<WINDOW_HEIGHT-SPRITE_SIZE && this->shape.getPosition().y+change.y<WINDOW_HEIGHT-SPRITE_SIZE)
        this->shape.move(change);
}

void Alives::findWalk() {
    sf::Vector2f direction = this->destination - this->shape.getPosition();
    float lenght = sqrt(direction.x * direction.x + direction.y * direction.y);
    sf::Vector2f normalized = direction / lenght * float(MOVEMENT_SPEED) * Game::dt;
    this->move(normalized.x - (normalized.x > 0 ? remainderf(normalized.x, 1.0) : -(remainderf(normalized.x, 1.0) + 1)), normalized.y - (normalized.y > 0 ? remainderf(normalized.y, 1.0) : -(remainderf(normalized.y, 1.0) + 1)));
    checkDestination();
}


void Alives::setRandomDestination() {
    this->destination = sf::Vector2f(rand() % (WINDOW_WIDTH - SPRITE_SIZE), rand() % (WINDOW_HEIGHT - SPRITE_SIZE));
}

void Alives::checkDestination(){
    if (abs(this->shape.getPosition().x - this->destination.x) < 5 && abs(this->shape.getPosition().y - this->destination.y) < 5) {
        if (this->currentState == sex){
            this->needOfSex = 0;
            this->update();
        }
        setRandomDestination();
    }
}