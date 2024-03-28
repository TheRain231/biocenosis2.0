//
// Created by Андрей Степанов on 28.03.2024.
//

#include "Alives.h"

Alives::Alives(): Entity() {
    currentState = eat;
}

Alives::Alives(const float x, const float y): Entity(x, y){
    currentState = eat;
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
    this->shape.move(sf::Vector2f(x, y));
}

