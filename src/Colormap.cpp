
#ifndef COLORMAPHEADER
#define COLORMAPHEADER

/*
Classe de leitura de arquivos .mtl, que guarda cores e propriedades de materiais.

A saber que:
    - kd = Difuso (Cor do objeto)
    - ks = Specular (Reflexivo)
    - ke = Emissivo 
    - ka = Ambiente
    - ns = Brilho
    - ni = Índice de refração
    - d = Opacidade

A classe precisa ser instânciada passando o caminho do arquivo .mtl correspondente
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include "Vector.cpp"

using namespace std;

struct MaterialProperties {
    Vector kd;  // Difuso
    Vector ks;  // Specular
    Vector ke;  // Emissivo
    Vector ka;  // Ambiente
    double ns; // Brilho
    double ni; // Índice de refração
    double d;  // Opacidade

    MaterialProperties() : kd(0, 0, 0), ks(0, 0, 0), ke(0, 0, 0), ka(0, 0, 0), ns(0), ni(0), d(0) {}
};

class colormap {

public:
    map<string, MaterialProperties> mp;

    //Construtor    
    colormap(){};
    colormap(string input){

        // construtor: lê arquivo cores.mtl e guarda valores RGB associados a cada nome

        std::ifstream mtlFile(input);

        if (!mtlFile.is_open()) {
            std::cerr << "erro abrindo arquivo cores.mtl\n";
        }

        string line, currentMaterial;

        while (std::getline(mtlFile, line)) {
            std::istringstream iss(line);
            std::string keyword;
            iss >> keyword;

            if (keyword == "newmtl") {
                iss >> currentMaterial;
                if (!currentMaterial.empty()) {
                    mp[currentMaterial] = MaterialProperties();
                }
            } else if (keyword == "Kd") {
                double kdR, kdG, kdB;
                iss >> kdR >> kdG >> kdB;
                if (!currentMaterial.empty()) {
                    mp[currentMaterial].kd = Vector(kdR, kdG, kdB);
                }
            } else if (keyword == "Ks") {
                double ksR, ksG, ksB;
                iss >> ksR >> ksG >> ksB;
                if (!currentMaterial.empty()) {
                    mp[currentMaterial].ks = Vector(ksR, ksG, ksB);
                }
            } else if (keyword == "Ke") {
                double keR, keG, keB;
                iss >> keR >> keG >> keB;
                if (!currentMaterial.empty()) {
                    mp[currentMaterial].ke = Vector(keR, keG, keB);
                }
            } else if (keyword == "Ka") {
                double kaR, kaG, kaB;
                iss >> kaR >> kaG >> kaB;
                if (!currentMaterial.empty()) {
                    mp[currentMaterial].ka = Vector(kaR, kaG, kaB);
                }
            } else if (keyword == "Ns") {
                iss >> mp[currentMaterial].ns;
            } else if (keyword == "Ni") {
                iss >> mp[currentMaterial].ni;
            } else if (keyword == "d") {
                iss >> mp[currentMaterial].d;
            }
        }

        mtlFile.close();
    }

    Vector getColor(string& s){
        if (mp.find(s) != mp.end()) {
            return mp[s].kd;
        } else {
            cerr << "Error: cor " << s << " indefinida no arquivo .mtl\n";
            return Vector(0,0,0);
        }
    }

    MaterialProperties getMaterialProperties(string& s){
        if (mp.find(s) != mp.end()) {
            return mp[s];
        } else {
            cerr << "Error: Cor " << s << " indefinida no arquivo .mtl\n";
            return MaterialProperties();
        }
    }

};

#endif
