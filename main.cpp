#include <iostream>
#include "src/ObjReader.cpp"
#include "src/Camera.cpp"



int main(){

    objReader obj("inputs/cubo.obj");

    obj.print_faces();

    const int horizontal = 512;
    const int vertical = 512;
    const double distance = 1.0;



    Camera camera = Camera(horizontal, vertical, point(0,1,-10),distance);


   
    return 0;
}