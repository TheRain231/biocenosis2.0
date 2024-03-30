//
// Created by Андрей Степанов on 28.03.2024.
//

#include "Hunter.h"

Hunter::Hunter() : Alives() {
    this->shape.setSize(sf::Vector2f(SPRITE_SIZE, SPRITE_SIZE));
    this->shape.setTexture(&texture);
}

void Hunter::findFood() {
    float localMin = 100000;
    Grasseaters *newHusband;
    bool check = false;
    for (auto &gras: Grasseaters::grasseaters) {
        float distance = sqrt((this->shape.getOrigin().x - gras->shape.getOrigin().x) *
                              (this->shape.getOrigin().x - gras->shape.getOrigin().x) +
                              (this->shape.getOrigin().y - gras->shape.getOrigin().y) *
                              (this->shape.getOrigin().y - gras->shape.getOrigin().y));
        if (distance < localMin) {
            check = true;
            localMin = distance;
            newHusband = gras;
        }
    }
    if (check) {
        this->destination.x = (this->shape.getOrigin().x + newHusband->shape.getOrigin().x) / 2;
        this->destination.y = (this->shape.getOrigin().y + newHusband->shape.getOrigin().y) / 2;
        this->currentState = eat;
    }

}

void Hunter::findSex() {
    float localMin = 100000;
    Hunter *newHusband; // new Hunter();
    bool check = false;
    for (auto & who: hunters) {
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
    newHusband->destination = this->destination;
    this->currentState = sex;
    newHusband->currentState = sex;
    }
}

void Hunter::deleteObject() {

}

void Hunter::renderVector(sf::RenderTarget* target) {
    for (auto &hunter : hunters) {
        hunter->render(target);
    }
}

sf::Texture Hunter::texture;
std::vector<Hunter*> Hunter::hunters;