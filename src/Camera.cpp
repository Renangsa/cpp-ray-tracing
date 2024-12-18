#ifndef CAMERAHEADER
#define CAMERAHEADER

#include <iostream>
#include "Vector.cpp"
#include "Point.cpp"

class Camera {
private:
 

public:
    point position;
    Vector direction;
    int horizontal;
    int vertical;
    double distance;
    Vector forward = {0, 0, 1};
    Vector right = {1, 0, 0};
    Vector up = {0, 1, 0};

    Camera(){};
    Camera(double horizontal, double vertical, point position , double distance) {
        this -> horizontal = horizontal;
        this -> vertical = vertical;
        this -> position = position;
        this -> distance = distance;
    };

    };

#endif

