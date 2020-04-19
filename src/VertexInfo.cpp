//
// Created by skidr on 19/04/2020.
//

#include "VertexInfo.h"

VertexInfo::VertexInfo(int id, double x, double y) : id(id), x(x), y(y) {}

int VertexInfo::getId() const {
    return id;
}

double VertexInfo::getX() const {
    return x;
}

double VertexInfo::getY() const {
    return y;
}

bool VertexInfo::operator==(const VertexInfo &rhs) const {
    return id == rhs.id;
}

bool VertexInfo::operator!=(const VertexInfo &rhs) const {
    return !(rhs == *this);
}

VertexInfo::VertexInfo(int id) {
    this->id = id;
    this->x = 0; this->y = 0;
}
