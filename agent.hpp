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
        bool Ok[4][4];
        bool W[4][4];
        bool G[4][4];
    };

    struct pos{
        int x;
        int y;
    };

    history hist_agent;
    stack<pos> okay_rooms;
    
    Agent();
    void Senses(pos current_pos);

    pos Move (pos destination_pos);
    // gives us position of 
    void Actuates(pos position,string element);

    void initialize_movt();

    void Decide(history);

};