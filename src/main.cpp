#include "../include/raylib.h"
#include "../lib/flecs/flecs.h"
#include "../include/simulation.h"
#include "../include/render.h"

int main() {
    TraceLog(LOG_INFO, "Raylib debug test: if you see this, logging works.");
    auto e = world.entity();
    InitWindow(800, 800, "Goofball.");
    SetTargetFPS(60);


    
    




    auto map = world.entity();
    auto grid = world.entity();
    
    map.set<Map>({2});
    grid.set<Grid>({map,-2.0, 0.0});

    for(int x = -5; x <= 10; x++) {
        for(int y = -5; y <= 10; y++) {
            //auto e = world.entity();
            //e.set<Cell>({grid, x, y, true, RED});
        }
    }

    start_render();
    //sys.run();
    
    return 0;
}