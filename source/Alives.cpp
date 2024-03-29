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
        currentState = eat;
    }
    else if (needOfSex > SEX){
        currentState = sex;
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
    if (this->shape.getPosition().x + x > 0 && this->shape.getPosition().x + x < WINDOW_HEIGHT - SPRITE_SIZE)
        this->shape.move(x * Game::dt, 0);
    if (this->shape.getPosition().y + y > 0 && this->shape.getPosition().y + y < WINDOW_HEIGHT - SPRITE_SIZE)
        this->shape.move(0, y*Game::dt);
}
void Alives::findWalk() {
    float dx = fmodf(destination.x - this->shape.getPosition().x, MOVEMENT_SPEED);
    float dy = fmodf(destination.y - this->shape.getPosition().y, MOVEMENT_SPEED);
    this->move(dx > 0 ? fmax(dx,2) : fmin (dx,-2),dy > 0 ? fmax(dy,2) : fmin (dy,-2));
}

void Alives::setRandomDestination() {
    this->destination = sf::Vector2f(rand() % (WINDOW_WIDTH-SPRITE_SIZE), rand() % (WINDOW_HEIGHT-SPRITE_SIZE));
}

void Alives::checkDestination(){
    if (abs(this->shape.getPosition().x - this->destination.x) < 5 && abs(this->shape.getPosition().y - this->destination.y) < 5) {
        setRandomDestination();
    }
}