#pragma once
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h> 
#include <stack>
#include <vector>
using namespace std;

struct position{
    int x;
    int y;
};

struct pos_arr{
    position arr[5];
};

struct perception{
        vector<position> S;
        vector<position> B;
        vector<position> P;
        vector<position> W;
        vector<position> G;
    };

void delay(int number_of_seconds);
class environment{
    public:
    string grid[4][4];
    
    environment();

    pos_arr generate_positions();

    stack<position> neighbours(position pos);

    perception display_envt(position agent_pos);

    void print_agent(position current_pos);

    int print_msg(string msg);
};