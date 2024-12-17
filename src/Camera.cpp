#ifndef CAMERAHEADER
#define CAMERAHEADER

#include <iostream>
#include "Vector.cpp"
#include "Point.cpp"

class Camera {
private:
    point position;
    vetor direction;
    vetor up;
    int horizontal;
    int vertical;
    double distance;

public:
    Camera(double horizontal, double vertical, point position , double distance) {
        this -> horizontal = horizontal;
        this -> vertical = vertical;
        this -> position = position;
        this -> distance = distance;
    };

    };

#endif

