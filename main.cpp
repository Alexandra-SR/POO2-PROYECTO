#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <fstream>
#include "CollisionSystem.h"

using namespace sf;

int main() {
    std::vector<particle*> particles;

    particle* p = new particle(0.8606383036592139,0.5005878081888459, -0.028204006855386703, -0.013196714374446417, 0.0025, 13800.0,sf::Color(0, 255, 0, 255) );
    particles.push_back(p);
    particle* p2 = new particle(0.09036563878091838, 0.8255516914111956, 0.006666296767311371, 0.007583599322049071, 0.0025, 13800.0, sf::Color(255, 0, 0, 255) );
    particles.push_back(p2);
    /*
        int n;
        std::cin>>n;
       for(int  i = 0; i < n; i++)
       {
           double rx; double ry; double vx; double vy;
           double r; double mass; sf::Color color;

       }
    */
    RenderWindow* window = new RenderWindow (VideoMode(1000,1000), "Prueba");
    window->setFramerateLimit(60);
    CollisionSystem test(particles);
    test.simulate(2000, window);
    //sleep(milliseconds(2000));
    return 0;
}