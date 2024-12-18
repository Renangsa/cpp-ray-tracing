#include <iostream>
#include "src/ObjReader.cpp"
#include "src/Camera.cpp"



int main(){

   // objReader obj("inputs/cubo.obj");

    //obj.print_faces();

    const int horizontal = 512;
    const int vertical = 512;
    const double distance = 1.0;
    Camera camera = Camera(horizontal, vertical, point(0,1,-10),distance);
   
   
    Vector PlanoProjecao = camera.forward * camera.distance; 
    Vector position = {PlanoProjecao.x + camera.position.getX(), PlanoProjecao.y + camera.position.getY(), PlanoProjecao.z + camera.position.getZ()};

    for (int x = 0; x < horizontal; x++) {
        for (int y = 0; y < vertical; y++) {

            Vector pixel =  position - (camera.up *(x-(vertical/2))) + (camera.right * (y-(horizontal/2))); 
            
            Vector PositionCamera = {camera.position.getX(), camera.position.getY(), camera.position.getZ()};

            Vector V = (pixel - PositionCamera ).normalize(); // cria um vetor da câmera para o pixel

            // Raio 
            point origem = camera.position;
            Vector direcao = V;
            
            



        }
    }   
   
    return 0;
}