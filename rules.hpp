#pragma once
#include <iostream>
#include "environment.hpp"
#include "agent.hpp"
#include <stack>
using namespace std;



stack<position> neighbours(position pos);
 bool str_bool(string x);   
void Rules(position pos_ele,char name);
map<char, string> form_argument(position cur_pos,map<char,bool> a_hist);
map<char,bool> return_history_pos(position current_val);
string check_pit(position cur_pos, position neigh_pos,history a_hist);
string check_wumpus(position cur_pos, position neigh_pos,history a_hist);
