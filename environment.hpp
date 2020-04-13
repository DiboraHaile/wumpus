#pragma once
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h> 
#include <stack>
using namespace std;

struct position{
    int x;
    int y;
};

struct pos_arr{
    position arr[5];
};


class environment{
    public:
    string grid[4][4];
    char ele[5] = {'G','W','P','P','P'};
    position G, W, P;
    
    environment();

    position generate_random();

    pos_arr generate_positions();

    stack<position> neighbours(position pos);

    void display_envt(position agent_pos);

    void print_agent(position current_pos);

    int print_msg(string msg);
};