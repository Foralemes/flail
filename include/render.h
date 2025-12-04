#ifndef RENDER_H
#define RENDER_H

#include "../lib/flecs/flecs.h"
#include "../include/raylib.h"
#include "../include/simulation.h"

#include <iostream>
auto tile = LoadModel("assets/plane.obj");
flecs::system sys2 = world.system<Cell>("Render")
    .each([](Cell& c) {
        // Each is invoked for each entity
        
        const Grid& comp = c.parentGrid.get<Grid>();
        
        //DrawCube({float(c.gridX) + comp.mapX, 0.0, float(c.gridZ) + comp.mapZ}, 1.0, 1.0, 1.0, c.color);
        //DrawModel(tile, {float(c.gridX) + comp.mapX, 0.0, float(c.gridZ) + comp.mapZ}, 1.0, c.color);
        
    });

#endif