//
// Created by Андрей Степанов on 28.03.2024.
//

#ifndef BIOCENOSIS_ALIVES_H
#define BIOCENOSIS_ALIVES_H
#include "Entity.h"

class Alives: Entity {
protected:
    enum State {
        sex, eat, dead
    };
    State currentState;
    std::pair<float, float> destination;
    int hunger;
    int needOfSex;
    int liveTime;
public:
    Alives();
    Alives(const float x, const float y);
    ~Alives();

    void update();
    void checkState();

    virtual void move(const float x, const float y);
    virtual void findFood();
    virtual void findSex();
    virtual void deleteObject();

};


#endif //BIOCENOSIS_ALIVES_H
