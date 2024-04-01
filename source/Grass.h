//
// Created by 1ghaw on 28.03.2024.
//

#ifndef BIOCENOSIS_GRASS_H
#define BIOCENOSIS_GRASS_H
#include "Entity.h"

class Grass: public Entity {
private:
    void update();
public:
    Grass();
    ~Grass();
    static sf::Texture texture;
    static std::vector<Grass*> grass;
    static void renderVector(sf::RenderTarget* target);

};


#endif //BIOCENOSIS_GRASS_H
