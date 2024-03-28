//
// Created by Лаба on 27.03.2024.
//

#ifndef BIOCENOSIS_ENTITY_H
#define BIOCENOSIS_ENTITY_H

#include "defines.h"

class Entity {
public:
    sf::RectangleShape shape;
public:
    Entity();
    Entity(const float x, const float y);
    ~Entity();

    virtual void update() = 0;
    void render(sf::RenderTarget* target);
    virtual void deleteObject() = 0;
};


#endif //BIOCENOSIS_ENTITY_H
