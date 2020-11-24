#ifndef CLIONPROYECT_PARTICLE_H
#define CLIONPROYECT_PARTICLE_H
#include <iostream>
#include <limits>
#include <cstdlib>
#include <ctime>
#include <math.h>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

using namespace sf;

class particle {

private:

// posición de la particula en X y en Y
    double rx_, ry_;
// velocidad de la particula en X y en Y
    double vx_, vy_;
// número de colisiones de la particula
    int count_;
//radio de la particula
    double r_;
    double mass_;
    sf::Color color_;

public:

    particle(double rx, double ry, double vx, double vy,
    int count, double r, double mass, sf::Color color):
    rx_(rx), ry_(ry), vx_(vx), vy_(vy),count_(count), r_(r),
    mass_(mass), color_(color){};

    /* particle();*/

    inline int count() { return count_;}

    void move(double dt);

    void draw(sf::RenderWindow* window);

    double timeToHit(particle* other);

    double timeToHitVerticalWall();

    double timeToHitHorizontalWall();

    void bounceOff(particle* other);

    void bounceOffVerticalWall();

    void bounceOffHorizontalWall();

    double kineticEnergy();


};

#endif //CLIONPROYECT_PARTICLE_H
