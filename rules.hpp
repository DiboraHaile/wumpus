#include <iostream>
#include "environment.hpp"
#include <stack>
using namespace std;

bool S[4][4], B[4][4];

stack<position> neighbours(position pos);
    
void Rules(position pos_ele,char name);
bool no_pit(position cur_pos);
bool no_wumpus(position cur_pos);
