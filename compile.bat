g++ -c maze_gen.cpp
g++ -c main.cpp

g++ maze_gen.o main.o -o run

del main.o
del maze_gen.o
