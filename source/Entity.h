//
// Created by Лаба on 27.03.2024.
//

#ifndef BIOCENOSIS_ENTITY_H
#define BIOCENOSIS_ENTITY_H

#include "defines.h"

class Entity {
protected:
    Entity* food;
public:
    sf::RectangleShape shape;
    Entity();
    Entity(const float x, const float y);
    virtual ~Entity();

    virtual void update() = 0;
    virtual void deleteObject() = 0;
    void render(sf::RenderTarget* target);
};


#endif //BIOCENOSIS_ENTITY_H
