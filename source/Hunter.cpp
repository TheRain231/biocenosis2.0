//
// Created by Андрей Степанов on 28.03.2024.
//

#include "Hunter.h"
#include <iostream>

Hunter::Hunter() : Alives() {
    name = "hunter";
    this->shape.setTexture(&texture);
}

Hunter::Hunter(const float x, const float y) : Alives(x, y) {
    name = "hunter";
    this->shape.setTexture(&texture);
}



void Hunter::findFood() {
    float localMin = 100000;
    Grasseaters *newHusband;
    bool check = false;
    for (auto &gras: Grasseaters::grasseaters) {
        float distance = sqrt((this->shape.getPosition().x - gras->shape.getPosition().x) *
                              (this->shape.getPosition().x - gras->shape.getPosition().x) +
                              (this->shape.getPosition().y - gras->shape.getPosition().y) *
                              (this->shape.getPosition().y - gras->shape.getPosition().y));
        if (distance < localMin) {
            check = true;
            localMin = distance;
            newHusband = gras;
        }
    }
    if (check) {
        this->destination.x = newHusband->shape.getPosition().x;
        this->destination.y = newHusband->shape.getPosition().y;
        this->food = newHusband;
        this->currentState = eat;
    }

}

void Hunter::findSex() {
    float localMin = 100000;
    Hunter *newHusband; // new Hunter();
    bool check = false;
    for (auto &who: hunters) {
        float distance = sqrt((this->shape.getPosition().x - who->shape.getPosition().x) *
                              (this->shape.getPosition().x - who->shape.getPosition().x) +
                              (this->shape.getPosition().y - who->shape.getPosition().y) *
                              (this->shape.getPosition().y - who->shape.getPosition().y));
        if (distance < localMin && who->currentState == walk && this!= who && who->needOfSex > SEX) {
            check = true;
            localMin = distance;
            newHusband = who;
        }
    }
    if (check) {
        this->destination.x = (this->shape.getPosition().x + newHusband->shape.getPosition().x) / 2;
        this->destination.y = (this->shape.getPosition().y + newHusband->shape.getPosition().y) / 2;
        newHusband->destination = this->destination;
        this->currentState = sex;
        newHusband->currentState = sex;
        this->target = newHusband;
        newHusband->target = this;
    }
}

void Hunter::deleteObject() {

}

void Hunter::renderVector(sf::RenderTarget *target) {
    for (auto &hunter: hunters) {
        hunter->render(target);
    }
}

Hunter::~Hunter() {
    const int len = Hunter::hunters.size();
    int i=0;
    for (i=0; i<len; i++) {
        if (Hunter::hunters[i] == this) {
            break;
        }
    }
    Hunter::hunters.erase(Hunter::hunters.begin()+i);
}

sf::Texture Hunter::texture;
std::vector<Hunter *> Hunter::hunters;