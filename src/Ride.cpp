
#include <Ride.h>

#include "Ride.h"


Ride::Ride(int origin, int destiny, Person* person) : rideStarted(false){
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

bool Ride::hasRideStarted(){
    return this->rideStarted;
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
    this->rideStarted = true;
}
