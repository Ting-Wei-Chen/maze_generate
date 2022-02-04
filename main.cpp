#define maze_gen_H
#include <iostream>
#include "maze_gen.h"

using namespace std;

int main(){
    maze m0;
    m0= maze();

    m0.maze_gen_top(1, 1);
    m0.print_maze();

    return 0;
}