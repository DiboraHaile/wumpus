#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <map>
//#include "tablox.hpp"
//#include "evaluate.hpp"
#include "rules.hpp"
#include "environment.hpp"
#include "agent.hpp"
using namespace std;


Agent::Agent(){
    // start agent from pos 0,0
    current_pos.x = 0;
    current_pos.y = 0;
    // set all room to unvisited
    for (int i=0;i<4;i++)
        for (int j=0;j<4;j++)
            agent_history.V[i][j] = false;
    okay_rooms.push(current_pos);
    

}

position Agent::Move (position destination_pos){
    return destination_pos;

}
// gives us position of 
void Agent::Actuates(position ele_pos,string element){
    if (element == "wumpus")
        {
        // set every other room wumpus variable false
        // since we only have one wumpus
        for(int i=0;i<4;i++)
            for(int j=0;j<4;j++)
                agent_history.W[i][j] = false;
        agent_history.W[ele_pos.x][ele_pos.y] = true;
        }
    else if (element == "gold"){
        Move(ele_pos);
        agent_history.G[ele_pos.x][ele_pos.y] = true;
        cout<<"game over";
    }
    else if (element == "okay"){
        okay_rooms.push(ele_pos);
        agent_history.Ok[ele_pos.x][ele_pos.y];
    }
    else{

    }
    
        
}

void Agent::update_history(perception env_percept,position current_pos){
    agent_history.B[current_pos.x][current_pos.y] = false;
    agent_history.G[current_pos.x][current_pos.y] = false;
    agent_history.S[current_pos.x][current_pos.y] = false;
    agent_history.P[current_pos.x][current_pos.y] = false;
    agent_history.W[current_pos.x][current_pos.y] = false;

    for (int i=0;i<env_percept.B.size();i++)
        if (current_pos.x == env_percept.B[i].x and current_pos.y == env_percept.B[i].y)
            agent_history.B[current_pos.x][current_pos.y] = true;
    for (int i=0;i<env_percept.S.size();i++)
        if (current_pos.x == env_percept.S[i].x and current_pos.y == env_percept.S[i].y)
            agent_history.S[current_pos.x][current_pos.y] = true;
    for (int i=0;i<3;i++)
        if (current_pos.x == env_percept.P[i].x and current_pos.y == env_percept.P[i].y)
            agent_history.P[current_pos.x][current_pos.y] = true;
    
    if (current_pos.x == env_percept.G[0].x and current_pos.y == env_percept.G[0].y)
            agent_history.G[current_pos.x][current_pos.y] = true;
    if (current_pos.x == env_percept.W[0].x and current_pos.y == env_percept.W[0].y)
            agent_history.W[current_pos.x][current_pos.y] = true;

    agent_history.V[current_pos.x][current_pos.y] = true;
}

void Agent::Decide(history a_hist, position cur_pos){
    stack<position> neighs_cur;
    position neigh;
    neighs_cur = neighbours(cur_pos);
    while(!neighs_cur.empty()){
        neigh = neighs_cur.top();
        neighs_cur.pop();
        if (!no_pit(neigh) and !no_wumpus(neigh))
            okay_rooms.push(cur_pos);
        
    }
}

