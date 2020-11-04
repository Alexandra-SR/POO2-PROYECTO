#include <iostream>
#include <limits>
#include <cstdlib>
#include <ctime>
#include  <math.h>
#include <SFML-2.5.1/bin/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/CircleShape.hpp>
#include <SFML/RenderWindow.hpp>


class particle {
    private:
    double rx_, ry_;
    double vx_, vy_;
    int count_;
    double r_;
    double mass_;
    sf::Color color_;
    public:
    particle(double rx, double ry, double vx, double vy, 
    int count, double r, double mass): 
    rx_(rx), ry_(ry), vx_(vx), vy_(vy),count_(count), r_(r),
    mass_(mass), color_(color){}


    particle(){
        
        rx_ = static_cast <double> (rand()) / static_cast <double> (RAND_MAX);
        ry_ = static_cast <double> (rand()) / static_cast <double> (RAND_MAX);
        vx_ = -0.005 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(0.005-(-0.005))));
        vy_ = -0.005 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(0.005-(-0.005))));
        r_ = 0.02;
        mass_ = 0.5;
        color_ = sf::Color::Green; 
     }

     int count() {
        return count_;
    }

      void move(double dt) {
        rx_ += vx_ * dt;
        ry_ += vy_ * dt;
    }

    void draw(sf::RenderWindow window){
        sf::CircleShape circle(r_);
        circle.setFillColor(color_)
        circle.setPosition(rx_, ry_)
        window.draw(circle);
    }


    double timeToHit(particle *that) {   
        if (this == that) return INFINITY;
        double dx_  = that->rx_ - this->rx_;
        double dy_  = that->ry_ - this->ry_;
        double dvx_ = that->vx_ - this->vx_;
        double dvy_ = that->vy_ - this->vy_;

        double dvdr_ = dx_*dvx_ + dy_*dvy_;
        if (dvdr_ > 0) 
            return INFINITY;

        double dvdv_ = dvx_*dvx_ + dvy_*dvy_;
        if (dvdv_ == 0) 
            return INFINITY;

        double drdr_ = dx_*dx_ + dy_*dy_;
        double sig = this->r_ + that->r_;
        double d = (dvdr_*dvdr_) - dvdv_ * (drdr_ - sig*sig);
        if (d < 0) return INFINITY;
        return - (dvdr_ + sqrt(d)) / dvdv_;
    }


        double timeToHitVerticalWall() 
        {
        if      (vx_ > 0) return (1.0 - rx_ - r_) / vx_;
        else if (vx_ < 0) return (radius - rx_) / vx_;  
        else    return INFINITY;
        }

        double timeToHitHorizontalWall() {
        if      (vy_ > 0) return (1.0 - ry_ - r_) / vy_;
        else if (vy_ < 0) return (r_ - ry_) / vy_;
        else     return INFINITY;
    }



};



