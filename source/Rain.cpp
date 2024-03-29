//
// Created by 1ghaw on 28.03.2024.
//
#include <iostream>
#include "Rain.h"

Rain::Rain(float x, float y) {
    texture.loadFromFile("textures/rain.png");
    shape.setSize(sf::Vector2f(WINDOW_WIDTH, WINDOW_HEIGHT));
    shape.setTexture(&texture);
    shape.setOrigin(x,y);
}

Rain::~Rain() {

}

void Rain::renderVector(sf::RenderTarget *target) {
    for (auto & obj:rain){
        obj->shape.setOrigin(0,obj->shape.getOrigin().y-RAIN_SPEED);
    }
    if (rain[0]->shape.getOrigin().y<-WINDOW_HEIGHT){
        rain[0]->shape.setOrigin(0,WINDOW_HEIGHT);
    }
    else if (rain[1]->shape.getOrigin().y<-WINDOW_HEIGHT){
        rain[1]->shape.setOrigin(0,WINDOW_HEIGHT);
    }
    for (auto &obj : rain) {
        obj->render(target);
    }
}

void Rain::render(sf::RenderTarget *target) {
    target->draw(this->shape);
}


std::vector<Rain*> Rain::rain;