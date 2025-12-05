#ifndef RENDER_H
#define RENDER_H

#include "../lib/flecs/flecs.h"
#include "../include/raylib.h"
#include "../include/simulation.h"
#include <iostream>


Model load() {

    
    return LoadModel("assets/plane.obj");
}



#endif

int start_render() {
    auto tile = load();
    Camera3D camera = { 0 };
    camera.position = (Vector3){ 0.0f, 10.0f, 16.0f };  // Camera position
    camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };      // Camera looking at point
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };          // Camera up vector (rotation towards target)
    camera.fovy = 45.0f;                                // Camera field-of-view Y
    camera.projection = CAMERA_PERSPECTIVE;             // Camera mode type

    
    flecs::system sys2 = world.system<Cell>("Render")

    .each([tile](Cell& c) {
        

        // Each is invoked for each entity
        
        const Grid& comp = c.parentGrid.get<Grid>();
        
        //std::cout << IsModelValid(tile) << "\n";
        //DrawCube({float(c.gridX) + comp.mapX, 0.0, float(c.gridZ) + comp.mapZ}, 1.0, 1.0, 1.0, c.color);
        DrawModel(tile, {float(c.gridX) + comp.mapX, 0.0, float(c.gridZ) + comp.mapZ}, 1.0, c.color);
        
    });


    while (!WindowShouldClose()) {
        ClearBackground(RAYWHITE);
        BeginDrawing();
        BeginMode3D(camera);
        DrawGrid(10, 1.0f);
        
        sys2.run();

        EndMode3D();
        EndDrawing();
    }
    CloseWindow();
}




