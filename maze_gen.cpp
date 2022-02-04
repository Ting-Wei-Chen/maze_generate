#define maze_gen_H

#include <iostream>
#include <stack>
//#include <random>
#include "maze_gen.h"

using namespace std;

#define size 11

bool maze::boundary(int x_pos, int y_pos){
    if(x_pos==0)return 1;
    if(x_pos== size-1)return 1;
    if(y_pos== 0)return 1;
    if(y_pos== size-1)return 1;
    return 0;
}

maze::maze(){
    for(int i=0; i<size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if(boundary(i, j))maze_obj[i][j]= 1;

            if((i%2== 1 && j%2== 1))maze_obj[i][j]= 0;
            else maze_obj[i][j]= 1;        
        }
        
    }
}

void maze::reset(){
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if(boundary(i, j))maze_obj[i][j]= 1;

            if((i%2== 1 && j%2== 1))maze_obj[i][j]= 0;
            else maze_obj[i][j]= 1;    
        }        
    }
}

void maze::node_clear(){
    for(int i=1; i< size ;i=i+2){
        for(int j=1; j< size; j=j+2){
            maze_obj[i][j]=0;
        }
    }
}

void maze::print_maze(){
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if(maze_obj[i][j]==1)cout<<"@@";
            else cout<<"  ";
        }
        cout<<"\n";
    }
}

bool maze::valid(int x_pos, int y_pos){
    if(x_pos>0 && x_pos< size-1 && y_pos> 0 && y_pos< size-1){
        if(x_pos %2== 1 && y_pos%2 ==1){
            if(maze_obj[x_pos][y_pos]== 0)return 1;
            else return 0;
        }
        else{
            return 0;
        }
    }

    return 0;
}

void maze::maze_gen(int x_pos, int y_pos){
    stack<int> x_set;
    stack<int> y_set;

    int x_temp, y_temp;

    bool x_p=0;
    bool x_s=0;
    bool y_p=0;
    bool y_s=0;

    x_temp= ((x_pos+ y_pos)/2)*7313;

    while(!(x_p && x_s && y_p && y_s)){
        switch((x_temp++)%4 ){
            case 0:
                if(! x_p){
                    x_set.push(x_pos+ 2);
                    y_set.push(y_pos);
                    x_p= 1;
                }
                else continue;
            case 1:
                if(! x_s){
                    x_set.push(x_pos-2);
                    y_set.push(y_pos);
                    x_s= 1;
                }
                else continue;
            case 2:
                if(! y_p){
                    x_set.push(x_pos);
                    y_set.push(y_pos+ 2);
                    y_p= 1;
                }
                else continue;
            default:
                if(!y_s){
                    x_set.push(x_pos);
                    y_set.push(y_pos- 2);
                    y_s=1;
                }
                else continue;
        }
    }

    while(!x_set.empty()){
        x_temp= x_set.top();
        y_temp= y_set.top();

        x_set.pop();
        y_set.pop();

        if(valid(x_temp, y_temp)){
            maze_obj[(x_pos+ x_temp)/2][(y_pos+ y_temp)/2]=0;
            maze_obj[x_temp][y_temp]=1;
            maze_gen(x_temp, y_temp);
        }
    }
}

void maze::maze_gen_top(int x_pos, int y_pos){
    maze_obj[x_pos][y_pos]=1;
    maze_gen(x_pos, y_pos);
    node_clear();
}