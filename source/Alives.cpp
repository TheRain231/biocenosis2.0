//
// Created by Андрей Степанов on 28.03.2024.
//

#include "Alives.h"
#include <iostream>
#include "Game.h"
#include <typeinfo>

Alives::~Alives() {

}

Alives::Alives(): Entity() {
    this->shape.setSize(sf::Vector2f(SPRITE_SIZE, SPRITE_SIZE));
    currentState = walk;
}

Alives::Alives(const float x, const float y) : Entity(x, y) {
    this->shape.setSize(sf::Vector2f(SPRITE_SIZE, SPRITE_SIZE));
    currentState = walk;
}


void Alives::update() {
    this->hunger += 1;
    this->liveTime += 1;
    this->needOfSex += 1;
//    if (liveTime > LIFE_TIME){
//        currentState = dead;
//    }
    //else if (hunger > HUNGER_DEATH){
        //currentState = dead;
        //deleteObject();
    //}
    if (hunger > HUNGER && (this->currentState == walk || (this->currentState == eat && this->name == "hunter"))){
        findFood();
    }
    else if (needOfSex > SEX && this->currentState == walk){
        findSex();
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

void Alives::changeStateAfterSex() {
    this->needOfSex = 0;
    this->currentState = walk;
}

void Alives::changeStateAfterEat() {
    this->hunger = 0;
    this->currentState = walk;
}

void Alives::checkDestination(){
    if (abs(this->shape.getPosition().x - this->destination.x) < 5 && abs(this->shape.getPosition().y - this->destination.y) < 5) {
        if (this->currentState == sex){
            this->changeStateAfterSex();
            this->target->changeStateAfterSex();
            if (this->name == "hunter"){
                Hunter::hunters.push_back(new Hunter(this->shape.getPosition().x, this->shape.getPosition().y));
            }
            if (this->name == "grasseater"){
                Grasseaters::grasseaters.push_back(new Grasseaters(this->shape.getPosition().x, this->shape.getPosition().y));
            }
            std::cout << "Произошла ебля" << '\n';
        }
        if (this->currentState == eat){
            this->changeStateAfterEat();
            this->food->deleteObject();
            std::cout << "Произошел ужин" << '\n';
        }
        setRandomDestination();
    }
}

