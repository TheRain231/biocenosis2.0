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
    //std::cout<<Game::dt<<std::endl;
    if (this->shape.getPosition().x+x>0 && this->shape.getPosition().y+y>0 && this->shape.getPosition().x+x<WINDOW_HEIGHT-SPRITE_SIZE && this->shape.getPosition().y+y<WINDOW_HEIGHT-SPRITE_SIZE)
        this->shape.move(x*Game::dt, y*Game::dt);
}

void Alives::findWalk() {
    this->move(fmodf(destination.x - this->shape.getPosition().x, MOVEMENT_SPEED), fmodf(destination.y - this->shape.getPosition().y, MOVEMENT_SPEED));
}

void Alives::setRandomDestination() {
    this->destination = sf::Vector2f(rand() % WINDOW_WIDTH, rand() % WINDOW_HEIGHT);
}

void Alives::checkDestination(){
    if (abs(this->shape.getPosition().x - this->destination.x) < 5 && abs(this->shape.getPosition().y - this->destination.y) < 5) {
        setRandomDestination();
    }
}