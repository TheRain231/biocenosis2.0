//
// Created by Лаба on 27.03.2024.
//

#ifndef BIOCENOSIS_ENTITY_H
#define BIOCENOSIS_ENTITY_H

#include "defines.h"

class Entity {
protected:
    sf::Texture texture;
    sf::RectangleShape shape;
public:
    Entity();
    Entity(const float x, const float y);
    ~Entity();

    virtual void update();
    virtual void render(sf::RenderTarget* target);

};


#endif //BIOCENOSIS_ENTITY_H
