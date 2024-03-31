//
// Created by Андрей Степанов on 28.03.2024.
//

#ifndef BIOCENOSIS_HUNTER_H
#define BIOCENOSIS_HUNTER_H
#include "Alives.h"
#include "Grasseaters.h"

class Hunter: public Alives {
public:
    Hunter();
    Hunter(const float x, const float y);
    ~Hunter(){}

    void findFood();
    void findSex();
    void deleteObject();
    void changeStateAfterSex();

    static sf::Texture texture;
    static std::vector<Hunter*> hunters;
    static void renderVector(sf::RenderTarget* target);
};


#endif //BIOCENOSIS_HUNTER_H
