//
// Created by Лаба on 27.03.2024.
//

#ifndef BIOCENOSIS_ENTITY_H
#define BIOCENOSIS_ENTITY_H

#include "defines.h"

class Entity {
protected:
    sf::Sprite sprite;
public:
    Entity();
    ~Entity();

    virtual void update();
    virtual void render(sf::RenderTarget& target);
    virtual void move(const float x, const float y);
};


#endif //BIOCENOSIS_ENTITY_H
