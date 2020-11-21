#ifndef CLIONPROYECT_EVENT_H
#define CLIONPROYECT_EVENT_H
#include "Particle.h"

class event {
private:
    particle* a,b;
    double event_time;
    int countA, countB;


public:

    event(double event_time,particle* a, particle* b){
        if (a != nullptr);
    };
    friend class comparetime;




public:
};

struct comparetime{
    bool operator()(event* const& e1, event* const& e2){
        return  e1->event_time < e2->event_time;
    }

};
#endif //CLIONPROYECT_EVENT_H
