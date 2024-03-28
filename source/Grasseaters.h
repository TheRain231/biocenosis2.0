//
// Created by Андрей Степанов on 28.03.2024.
//

#ifndef BIOCENOSIS_GRASSEATERS_H
#define BIOCENOSIS_GRASSEATERS_H
#include "Alives.h"

class Grasseaters: public Alives {
public:
    Grasseaters();
    ~Grasseaters();
    void findFood();
    void findSex();
    void deleteObject();

    static sf::Texture texture;
    static void setTexture();
    static std::vector<Grasseaters*> eaters;
    static void renderGrasseaters(sf::RenderTarget *target);
};


#endif //BIOCENOSIS_GRASSEATERS_H
