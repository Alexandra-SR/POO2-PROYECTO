#include "Particle.h"

particle::particle(){
    rx_ = static_cast <double> (rand()) / static_cast <double> (RAND_MAX);
    ry_ = static_cast <double> (rand()) / static_cast <double> (RAND_MAX);
    vx_ = -0.005 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(0.005-(-0.005))));
    vy_ = -0.005 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(0.005-(-0.005))));
    r_ = 0.02;
    mass_ = 0.5;
    color_ = sf::Color::Green;
}

void particle::move(double dt) {
    rx_ += vx_ * dt;
    ry_ += vy_ * dt;
}

void particle::draw(sf::RenderWindow *window){
    //prueba tamaño radio
    sf::CircleShape circle(r_*1000);
    circle.setFillColor(color_);
    circle.setPosition(rx_*window->getSize().x, ry_*window->getSize().y);
    window->draw(circle);
}

//Colisión entre dos particulas
/*En esta función se determinará si estas dos particulas
chocaran y cuando lo harán*/
double particle::timeToHit(particle *other) {
    if (this == other)
        return INFINITY;
// dx_= distancia entre las dos particulas en el eje x
    double dx_  = other->rx_ - this->rx_;
// dx_= distancia entre las dos particulas en el eje y
    double dy_  = other->ry_ - this->ry_;

    double dvx_ = other->vx_ - this->vx_;
    double dvy_ = other->vy_ - this->vy_;

    double dvdr_ = dx_*dvx_ + dy_*dvy_;
    if (dvdr_ > 0)
        return INFINITY;

    double dvdv_ = dvx_*dvx_ + dvy_*dvy_;
    if (dvdv_ == 0)
        return INFINITY;

    double drdr_ = dx_*dx_ + dy_*dy_;
    double sig = this->r_ + other->r_;
    double d = (dvdr_*dvdr_) - dvdv_ * (drdr_ - sig*sig);
    if (d < 0)
        return INFINITY;
    return - (dvdr_ + sqrt(d)) / dvdv_;
}

/*Esta función nos permite determinar cuando una particula
entrará en contacto con una pared vertical */
//como las coordenadas están entre 0 y 1
double particle::timeToHitVerticalWall(){
    if (vx_ > 0)
        return (1.0 - rx_ - r_) / vx_;

    else if (vx_ < 0)
        return (r_ - rx_) / vx_;

    else
        return INFINITY;
}

/*Esta función nos permite determinar cuando una particula
entrará en contacto con una pared horizontal */
double particle::timeToHitHorizontalWall() {
    if (vy_ > 0)
        return (1.0 - r_ - ry_) / vy_;

    else if (vy_ < 0)
        return (r_ - ry_) / vy_;

    else
        return INFINITY;
}
