#ifndef CELL_H
#define CELL_H
#include "../lib/flecs/flecs.h"
#include "../include/central.h"
#include "../include/raylib.h"



struct Map {
    int id;
};

struct Grid {
    flecs::entity parentMap;
    float mapX;
    float mapZ;
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


flecs::system sys = world.system<Cell>("Color")
    .each([](Cell& c) {
        // Each is invoked for each entity
        c.color = BLUE;
    });


#endif