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
    }
}

void Alives::move(const float x, const float y) {
    if (this->shape.getOrigin().x+x<0 && this->shape.getOrigin().y+y<0 && this->shape.getOrigin().x+x>-WINDOW_HEIGHT && this->shape.getOrigin().y+y>-WINDOW_HEIGHT)
        this->shape.move(x,y);
}

void Alives::findWalk() {
    this->move(rand()%MOVEMENT_SPEED-MOVEMENT_SPEED/2,rand()%MOVEMENT_SPEED-MOVEMENT_SPEED/2);
}

