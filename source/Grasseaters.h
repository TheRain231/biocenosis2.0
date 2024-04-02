//
// Created by Андрей Степанов on 28.03.2024.
//

#ifndef BIOCENOSIS_GRASSEATERS_H
#define BIOCENOSIS_GRASSEATERS_H
#include "Alives.h"
#include "Grass.h"
#include "Particles.h"
class Grasseaters: public Alives {
public:
    Grasseaters();
    Grasseaters(const float x, const float y);
    ~Grasseaters();

    void findFood();
    void findSex();
    void deleteObject();

    static std::vector<Grasseaters*> grasseaters;
    static sf::Texture texture;
    static void renderVector(sf::RenderTarget* target);
};


#endif //BIOCENOSIS_GRASSEATERS_H
