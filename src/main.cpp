#include "../include/raylib.h"
#include "../lib/flecs/flecs.h"
#include "../include/simulation.h"
#include "../include/render.h"
#include <cstdlib>

int the = 3;

int main() {
    auto e = world.entity();
    InitWindow(800, 800, "Goofball.");
    SetTargetFPS(60);
    auto map = world.entity();
    auto grid = world.entity();
    
    map.set<Map>({2});
    int color = 0;
    std::vector<flecs::entity> cellvec;
    for(int x = -20; x <= 5; x++) {
        for(int y = -3; y <= 3; y++) {
            auto e = world.entity();
            if (color == 0) {
                color = 1;
            e.set<Cell>({grid, x, y, true, RED});
            } else {
                color = 0;
                            e.set<Cell>({grid, x, y, true, BLUE});
            }

            cellvec.push_back(e);
            //std::cout << x << y << "\n";
        }
    }
    grid.set<Grid>({map,2.0, 4.0, 0.0, cellvec});
    start_render();
    
    return 0;
}