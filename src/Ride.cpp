
#include <Ride.h>

#include "Ride.h"


Ride::Ride(int origin, int destiny, Person* person) : started(false), finished(false){
    this->origin = origin;
    this->destiny = destiny;
    this->person = person;
}

int Ride::getOrigin() const{
    return this->origin;
}

int Ride::getDestiny() const{
    return this->destiny;
}

Person* Ride::getPerson() const{
    return this->person;
}

bool Ride::hasStarted(){
    return this->started;
}

bool Ride::hasFinished() {
    return this->finished;
}

void Ride::setOrigin(int origin){
    this->origin = origin;
}

void Ride::setDestiny(int destiny){
    this->destiny = destiny;
}

void Ride::setPerson(Person* person){
    this->person = person;
}

void Ride::startRide(){
    this->started = true;
}

void Ride::finishRide() {
    this->finished = true;
}
