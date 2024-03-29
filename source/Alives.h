//
// Created by Андрей Степанов on 28.03.2024.
//

#ifndef BIOCENOSIS_ALIVES_H
#define BIOCENOSIS_ALIVES_H
#include "Entity.h"

class Alives: public Entity {
protected:
    enum State {
        sex, eat, dead, walk
    };
    State currentState;
    sf::Vector2f destination;
    int hunger;
    int needOfSex;
    int liveTime;

public:
    Alives();
    ~Alives();

    void update();
    void checkState();
    void findWalk();

    void setRandomDestination();
    void checkDestination();

    void move(const float x, const float y);
    void move(sf::Vector2f change);
    virtual void findFood() = 0;
    virtual void findSex() = 0;

};


#endif //BIOCENOSIS_ALIVES_H
