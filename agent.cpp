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
    // set all rooms to unvisited and all the senses unset
    for (int i=0;i<4;i++)
        for (int j=0;j<4;j++){
            agent_history.V[i][j] = "false";
            agent_history.S[i][j] = "unset";
            agent_history.B[i][j] = "unset";
            agent_history.V[i][j] = "unset";
            agent_history.P[i][j] = "unset";
            agent_history.Ok[i][j]= "unset";
            agent_history.W[i][j] = "unset";
            agent_history.G[i][j] = "unset";
        }

    //agent_history.Ok[current_pos.x][current_pos.y]= "true";
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
                agent_history.W[i][j] = "false";
        agent_history.W[ele_pos.x][ele_pos.y] = "true";
        }
        
    else if (element == "okay"){
        okay_rooms.push(ele_pos);
        // check if there are rooms in uncertain_rooms we 
        // have proved to be okay
                for (int ind=0;ind<uncertain_rooms.size();ind++){
                    if( ele_pos.x == uncertain_rooms[ind].x and ele_pos.y == uncertain_rooms[ind].y)
                        uncertain_rooms.erase(uncertain_rooms.begin()+ind);
                }
         
    }
    else if (element == "uncertain"){
        uncertain_rooms.push_back(ele_pos);

    } 
    
        
}

void Agent::Actuates(string element){
    //generate random no from uncertain stack
    if (element == "empty")
        {
            int ind;
            ind = rand() % uncertain_rooms.size();
            okay_rooms.push(uncertain_rooms[ind]);
            uncertain_rooms.erase(uncertain_rooms.begin()+ind);
            
            
        }
    else if (element == "gold"){
        cout<<"\n"<<"The agent has found the gold!!...... Winner!!";
        exit(0);
    }
    else if (element == "pit" or element == "wumpus"){
        cout<<"\n"<<"The agent found a "<<element<<" ..... Game Over!!";
        exit(0);
    }
    else if(element == "end")
        //end the game
        exit(0);
    else if (element == "restart")
        //restart the game
        exit(0);
}

void Agent::update_history(perception env_percept,position current_pos){
    agent_history.B[current_pos.x][current_pos.y] = "false";
    agent_history.S[current_pos.x][current_pos.y] = "false";
    agent_history.P[current_pos.x][current_pos.y] = "false";
    agent_history.G[current_pos.x][current_pos.y] = "false";
    agent_history.W[current_pos.x][current_pos.y] = "false";


    for (int i=0;i<env_percept.B.size();i++){
        if (current_pos.x == env_percept.B[i].x and current_pos.y == env_percept.B[i].y)
            agent_history.B[current_pos.x][current_pos.y] = "true";
            }
    for (int i=0;i<env_percept.S.size();i++){
        if (current_pos.x == env_percept.S[i].x and current_pos.y == env_percept.S[i].y)
            agent_history.S[current_pos.x][current_pos.y] = "true";
            }
    for (int i=0;i<3;i++){
        if (current_pos.x == env_percept.P[i].x and current_pos.y == env_percept.P[i].y)
            agent_history.P[current_pos.x][current_pos.y] = "true";   
    }
    if (current_pos.x == env_percept.G[0].x and current_pos.y == env_percept.G[0].y)
            agent_history.G[current_pos.x][current_pos.y] = "true";
            
    if (current_pos.x == env_percept.W[0].x and current_pos.y == env_percept.W[0].y)
            agent_history.W[current_pos.x][current_pos.y] = "true";

}


void Agent::Decide(history a_hist, position cur_pos){
    string b_arg,s_arg;
    stack<position> neighs_cur;
    bool found = false;
    position neigh;
    // check each neighbour for pit and wumpus    
    neighs_cur = neighbours(cur_pos);
    while(!neighs_cur.empty()){
        neigh = neighs_cur.top();
        neighs_cur.pop();
        // check every neighbour if it isnot already visited
        for(position visited_room: visited_rooms){
          if ((visited_room.x == neigh.x) and (visited_room.y == neigh.y)){
              found = true;
          }
        }
        if(found == false){
        if(check_pit(cur_pos,neigh,a_hist) == "no_pit" and check_wumpus(cur_pos,neigh,a_hist) == "no_wumpus")
            Actuates(neigh,"okay");
        else if(check_wumpus(cur_pos,neigh,a_hist) == "wumpus")
            Actuates(neigh,"wumpus");
        else if(check_pit(cur_pos,neigh,a_hist) == "pit")
            Actuates(neigh,"pit"); 
        else if(check_wumpus(cur_pos,neigh,a_hist) == "uncertain" or check_pit(cur_pos,neigh,a_hist) == "uncertain")
            Actuates(neigh,"uncertain");
          }
        else
            found = false;
    }
}


