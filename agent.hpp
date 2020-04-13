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


class Agent{
    
    public:
    map<string,string> rule_match;
    struct history{
        bool S[4][4];
        bool B[4][4];
        bool V[4][4];
        bool P[4][4];
        bool Ok[4][4];
        bool W[4][4];
        bool G[4][4];
    };

  
    
    history agent_history;
    stack<position> okay_rooms;
    stack<position> visited_rooms;
    position current_pos;
    
    Agent();
    
    position Move (position destination_pos);
    
    void Actuates(position position,string element);

    void update_history(perception env_percept,position current_pos);

    void Decide(history a_hist, position cur_pos);

};