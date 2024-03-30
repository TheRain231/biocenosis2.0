//
// Created by Андрей Степанов on 28.03.2024.
//

#include "Grasseaters.h"

Grasseaters::Grasseaters() : Alives() {
    this->shape.setSize(sf::Vector2f(SPRITE_SIZE, SPRITE_SIZE));
    this->shape.setTexture(&texture);
}

void Grasseaters::findFood() {
    float localMin = 100000;
    sf::Vector2f coords;
    bool check = false;
    for (auto & gras: Grass::grass) {
        float distance = sqrt((this->shape.getOrigin().x - gras->shape.getOrigin().x) * (this->shape.getOrigin().x - gras->shape.getOrigin().x) + (this->shape.getOrigin().y - gras->shape.getOrigin().y) * (this->shape.getOrigin().y - gras->shape.getOrigin().y));
        if (distance<localMin) {
            check = true;
            localMin = distance;
            coords = gras->shape.getOrigin();
        }
    }
    if (check) {
    this->destination.x = (this->shape.getOrigin().x + coords.x) / 2;
    this->destination.y = (this->shape.getOrigin().y + coords.y) / 2;
    this->currentState = eat;
    }
}

void Grasseaters::findSex() {
    float localMin = 100000;
    Grasseaters *newHusband;
    bool check = false;
    for (auto & who: grasseaters) {
        float distance = sqrt((this->shape.getOrigin().x - who->shape.getOrigin().x) * (this->shape.getOrigin().x - who->shape.getOrigin().x) + (this->shape.getOrigin().y - who->shape.getOrigin().y) * (this->shape.getOrigin().y - who->shape.getOrigin().y));
        if (distance<localMin) {
            check = true;
            localMin = distance;
            newHusband = who;
        }
    }
    if (check) {
    this->destination.x = (this->shape.getOrigin().x + newHusband->shape.getOrigin().x) / 2;
    this->destination.y = (this->shape.getOrigin().y + newHusband->shape.getOrigin().y) / 2;
    newHusband->destination = this->destination;}
    this->currentState = sex;
    newHusband->currentState = sex;
}

void Grasseaters::deleteObject() {

}

void Grasseaters::renderVector(sf::RenderTarget* target) {
    for (auto &eater : grasseaters) {
        eater->render(target);
    }
}

std::vector<Grasseaters*> Grasseaters::grasseaters;
sf::Texture Grasseaters::texture;