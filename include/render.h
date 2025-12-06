#ifndef RENDER_H
#define RENDER_H

#include "../lib/flecs/flecs.h"
#include "../include/raylib.h"
#include "../include/simulation.h"
#include <iostream>
#include <cmath>


/*
I cheated in precalculus. It just works, man. I just plugged random shit in until it did. 
Anyways, this file handles the window and rendering. All of it hopefully. Fuck.
Theres some things you can uncomment for debug purposes if you really need it, but I don't expect to modify this code outside of optimizations. 
Todo, after a debug menu is added, put those things in.
Todo, make an asset loader and get it out of here.
Todo, make a real camera and put it in a different header.
*/


Model load() {

    
    return LoadModel("assets/plane.glb");
}



#endif


Vector2 pivotCell(float x, float z, float cx, float cz, double c, double s)
{

    x-=cx;
    z-=cz;

    x *= 1;
    z *= 1;


    float outx;
    float outz;
    outx = x * c - z * s;
    outz = x * s + z * c;

    return {outx +cx, outz +cz};
}


int start_render() {
    auto tile = load();
    Camera3D camera = { 0 };
    camera.position = (Vector3){ 0.0f, 5.0f, 16.0f };  
    camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };      
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };          
    camera.fovy = 45.0f;                        
    camera.projection = CAMERA_PERSPECTIVE;             
    DisableCursor();
    
    flecs::system renderGridsSystem = world.system<Grid>("RenderGrid")

    .each([tile](Grid& gridcomp) {
        //Uncomment to rotate all grids by tick.
        //gridcomp.rotation += .005;
        double si = sinf(gridcomp.rotation);
        double co = cosf(gridcomp.rotation);  
        double sumX = 0, sumZ = 0;

        for (const flecs::entity& c : gridcomp.cells) {
            const Cell& cellcomp = c.get<Cell>();
            sumX += cellcomp.gridX;
            sumZ += cellcomp.gridZ;
        }

        float centerX = sumX / gridcomp.cells.size();
        float centerZ = sumZ / gridcomp.cells.size();
        //Uncomment to draw center of grid.
        //DrawCube({ gridcomp.mapX+centerX, 1.0,  gridcomp.mapZ+centerZ}, 0.2, 1.0, 0.2, BLUE);

        for (const flecs::entity& c : gridcomp.cells) {
            const Cell& cellcomp = c.get<Cell>();
            Vector2 adjusted = pivotCell(cellcomp.gridX, cellcomp.gridZ, centerX, centerZ, co,si);
            DrawModelEx(tile, {adjusted.x + gridcomp.mapX, 0.0, adjusted.y + gridcomp.mapZ}, (Vector3){0.0, 1.0, 0.0}, -gridcomp.rotation*RAD2DEG, {0.5,1.0,0.5}, cellcomp.color);
        }
    });
    while (!WindowShouldClose()) {
        ClearBackground(RAYWHITE);
        UpdateCamera(&camera, CAMERA_FREE);
        BeginDrawing();
        BeginMode3D(camera);
        DrawGrid(10, 1.0f);
        
        renderGridsSystem.run();
        EndMode3D();
        EndDrawing();
    }
    CloseWindow();
}




