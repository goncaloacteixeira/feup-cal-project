//
// Created by skidr on 19/04/2020.
//

#ifndef FEUP_CAL_PROJECT_VERTEXINFO_H
#define FEUP_CAL_PROJECT_VERTEXINFO_H


class VertexInfo {
    int id;
    double x;
    double y;

public:
    VertexInfo(int id, double x, double y);

    VertexInfo(int id);

    int getId() const;

    double getX() const;

    double getY() const;

    bool operator==(const VertexInfo &rhs) const;

    bool operator!=(const VertexInfo &rhs) const;
};


#endif //FEUP_CAL_PROJECT_VERTEXINFO_H
