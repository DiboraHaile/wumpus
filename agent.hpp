#pragma once
#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <map>
//#include "tablox.hpp"
//#include "evaluate.hpp"
//#include "rules.hpp"
//#include "environment.hpp"
using namespace std;

struct history{
        string S[4][4];
        string B[4][4];
        string V[4][4];
        string P[4][4];
        string Ok[4][4];
        string W[4][4];
        string G[4][4];
    };

class Agent{
    
    public:
    map<string,string> rule_match;
    history agent_history;
    stack<position> okay_rooms;
    vector<position> visited_rooms;
    vector<position> uncertain_rooms;
    position current_pos;
    
    Agent();
    
    position Move (position destination_pos);
    
    void Actuates(position position,string element);

    void Actuates(string element);

    void update_history(perception env_percept,position current_pos);

    void Decide(history a_hist, position cur_pos);
    
    void update_okay_room(position added_pos);

};