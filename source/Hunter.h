//
// Created by Андрей Степанов on 28.03.2024.
//

#ifndef BIOCENOSIS_HUNTER_H
#define BIOCENOSIS_HUNTER_H
#include "Alives.h"

class Hunter: public Alives {
public:
    Hunter();
    ~Hunter();

    void findFood();
    void findSex();
    void deleteObject();

    static sf::Texture texture;
    static void setTexture();
};


#endif //BIOCENOSIS_HUNTER_H
