#include <SFML/Graphics.hpp>
#include <iostream>
#include "CollisionSystem.h"
#include <vector>
using namespace sf;

int main() {
    RenderWindow* window = new RenderWindow (VideoMode(1000,1000), "Prueba");
    window->setFramerateLimit(60);
    std::vector<particle*> particles;
    /*input*/
    CollisionSystem test(particles);
    test.simulate(2000, window);
    sleep(milliseconds(2000));
    return 0;
}