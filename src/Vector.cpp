#ifndef VECTORHEADER
#define VECTORHEADER
#include <iostream>
#include <math.h>
#include "Point.cpp"
#include "Vector.cpp"
/*
Classe de Vectores.

A saber que:
    - x = componente x
    - y = componente y
    - z = componente z

A classe precisa ser instanciada passando as componentes x, y e z
*/

class Vector{
    private:
    
    public:

    double x;
    double y;
    double z;
   
    //Construtores
    Vector() {}
    Vector(double x, double y, double z){
        this->x = x;
        this->y = y;
        this->z = z;
    }

    //Implemente os métodos de Vectores aqui
    
    //Soma Vector
    Vector operator+(const Vector other) const {
        // Soma componente a componente
        return Vector(this->x + other.x, this->y + other.y, this->z + other.z);
    }
    //Produto com scalar 
    Vector operator*(const double scalar) const {
        //Multiplica cada componente pelo escalar
        return Vector(this->x * scalar, this->y * scalar, this->z * scalar);
    }

    //Subtrai o Vector
    Vector operator-(const Vector other) const {
        // Subtrai componente a componente
        return Vector(this->x - other.x, this->y - other.y, this->z - other.z);
    }
    //Print do Vector no formato <x, y, z>
    void print(){
        std::cout << "<" << x << ", " << y << ", " << z << ">" << std::endl;
    }

    // Normalize the vector
    Vector normalize() const {
        double length = sqrt(x * x + y * y + z * z);
        return Vector(x / length, y / length, z / length);
    }


    //Getters
    double getX() const { return x; }
    double getY() const { return y; }
    double getZ() const { return z; }
};

#endif