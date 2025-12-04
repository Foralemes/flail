#include "../include/raylib.h"
#include "../lib/flecs/flecs.h"
#include "../include/simulation.h"
#include "../include/render.h"

int main() {

    auto e = world.entity();


    


    InitWindow(800, 800, "Goofball.");
    SetTargetFPS(60);


    Camera3D camera = { 0 };
    camera.position = (Vector3){ 0.0f, 10.0f, 16.0f };  // Camera position
    camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };      // Camera looking at point
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };          // Camera up vector (rotation towards target)
    camera.fovy = 45.0f;                                // Camera field-of-view Y
    camera.projection = CAMERA_PERSPECTIVE;             // Camera mode type

    auto map = world.entity();
    auto grid = world.entity();

    map.set<Map>({2});
    grid.set<Grid>({map,-2.0, 0.0});

    for(int x = -5; x <= 10; x++) {
        for(int y = -5; y <= 10; y++) {
            auto e = world.entity();
            e.set<Cell>({grid, x, y, true, RED});
        }
    }

auto tile = LoadModel("assets/plane.obj");
    std::cout << IsModelValid(tile) << "\n";
    //sys.run();
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
    return 0;
}