#ifndef CELL_H
#define CELL_H
#include "../lib/flecs/flecs.h"
#include "../include/central.h"
#include "../include/raylib.h"
#include <vector>


struct Map {
    int id;
};

struct Grid {
    flecs::entity parentMap;
    float mapX;
    float mapZ;
    float rotation;
    std::vector<flecs::entity> cells;
};

struct Cell {
    flecs::entity parentGrid;
    int gridX;
    int gridZ;
    bool passable;
    Color color;
};

struct GasMixture { //Default for reference; 101.3 kPA, 294K, 78, 21, 0,0,0......
    float pressure; //in Kilopascals
    float temperature; //in Kelvin
    int composition[3]; //Nitrogen, Oxygen, CO2
};




#endif