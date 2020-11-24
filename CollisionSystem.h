
#ifndef CLIONPROYECT_COLLISIONSYSTEM_H
#define CLIONPROYECT_COLLISIONSYSTEM_H
#include <SFML/Graphics.hpp>
#include "Particle.h"
#include "Event.h"
#include <queue>
#include <vector>
using namespace sf;
class CollisionSystem{
private:
    double time =0.0;
    double HZ = 0.5;
    std::vector<particle*> particles;
    std::priority_queue <event*, std::vector<event*>, comparetime > *pq;

public:

    friend class event;

    CollisionSystem(std::vector<particle*> particles){
        this->particles = particles;
    };


    void predict (particle *a, double limit){
        if (a == nullptr)
            return;

        for (int i = 0; i < particles.size(); i++){
            double dt = a->timeToHit(particles[i]);
            if (time +dt <= limit){
                pq->push(new event (time + dt, a, particles[i]));
                }
        }

        double dtX = a->timeToHitVerticalWall();
        double dtY = a->timeToHitHorizontalWall();
        if (time + dtX <= limit) pq->push(new event(time + dtX, a, nullptr));
        if (time + dtY <= limit) pq->push(new event(time + dtY, nullptr, a));

    };

void redraw(double limit, RenderWindow* window) {
    window->clear(sf::Color(255,255, 255, 255));
        for (int i = 0; i < particles.size(); i++) {
            particles[i]->draw(window);
        }
        window->display();

        sf::sleep(sf::Time(sf::milliseconds(1000)));
        if (time < limit) {
            pq->push(new event(time + 1.0 / HZ, nullptr, nullptr));
        }
}

void simulate (double limit, RenderWindow* window)
{
    pq = new std::priority_queue <event*, std::vector<event*>, comparetime>;
    for (int i = 0; i < particles.size(); i++)
    {
        predict(particles[i], limit);
    }
    pq->push(new event(0, nullptr, nullptr));


    while(!pq->empty()){

        event* e = pq->top();
        pq->pop();
        if (!e->isValid()) continue;
        particle* a = e->a;
        particle* b = e->b;

        for (int x= 0; x < particles.size(); ++x)
            particles[x]->move(e->event_time -time);
        time =e->event_time;

        if (a != nullptr && b != nullptr)
            a->bounceOff(b);
        else if (a != nullptr && b == nullptr)
            a->bounceOffVerticalWall();
        else if (a == nullptr && b != nullptr)
            b->bounceOffHorizontalWall();
        else if (a == nullptr && b == nullptr)
            redraw(limit,window);

        predict(a, limit);
        predict(b, limit);
    }
}














};

#endif //CLIONPROYECT_COLLISIONSYSTEM_H
