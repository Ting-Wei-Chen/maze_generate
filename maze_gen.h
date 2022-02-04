#ifdef maze_gen_H
#define maze_gen_H

#define size 11

class maze{
    private:
        int maze_obj[size][size];
        void node_clear();
        void maze_gen(int, int);
        bool valid(int, int);
        bool boundary(int, int);
    public:
        maze();
        void reset();
        void maze_gen_top(int, int);
        void print_maze();
};

#endif