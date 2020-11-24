#ifndef CLIONPROYECT_EVENT_H
#define CLIONPROYECT_EVENT_H
#include "Particle.h"

class event {
private:
    particle* a;
    particle* b;
    double event_time;
    int countA;
    int countB;
public:
    friend class CollisionSystem;
    friend class comparetime;
    event(double event_time, particle* a, particle* b){
        this->event_time = event_time;
        this->a =a;
        this->b =b;
        if(a != nullptr)
            {
                countA = a->count();
            }
        else countA = -1;

        if(b != nullptr)
            {
            countB = b->count();
            }
        else countB = -1;
    }

    //fix
    int compareTo(event* other)
    {
        return (this->event_time > other->event_time);
    }

    bool isValid()
    {
        if (a!= nullptr && a->count()!= countA)
            return  0;
        if (b!= nullptr && b->count()!= countB)
            return  0;
        return  1;

    }





};

struct comparetime {
    bool operator()(event* const& e1, event* const& e2){
        return  e1->event_time < e2->event_time;
    }

};
#endif //CLIONPROYECT_EVENT_H
