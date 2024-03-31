//
// Created by Андрей Степанов on 28.03.2024.
//

#ifndef BIOCENOSIS_ALIVES_H
#define BIOCENOSIS_ALIVES_H
#include "Entity.h"

class Alives: public Entity {
protected:
    Entity* food;
    Alives* target;
    enum State {
        sex, eat, dead, walk
    };
    State currentState;
    sf::Vector2f destination;
    int hunger;
    int needOfSex;
    int liveTime;
    std::string name;

public:
    Alives();
    Alives(const float x, const float y);
    virtual ~Alives();

    void update();
    void checkState();
    void findWalk();

    void setRandomDestination();
    void checkDestination();

    void move(const float x, const float y);
    void move(sf::Vector2f change);
    virtual void findFood() = 0;
    virtual void findSex() = 0;
    void changeStateAfterSex();
    void changeStateAfterEat();
};


#endif //BIOCENOSIS_ALIVES_H
