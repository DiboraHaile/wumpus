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
    
    
    Agent(){
        // start agent from pos 0,0
        pos current_pos;
        current_pos.x = 0;
        current_pos.y = 0;
        // set all room to unvisited
        for (int i=0;i<4;i++)
            for (int j=0;j<4;j++)
                hist_agent.V[i][j] = false;
        

    }
    void Senses(pos current_pos){

        //return sense;
    }
    pos Move (pos destination_pos){
        pos position;
        //position.x = current_pos.x;
        //position.y = current_pos.y;
        /*if (dir == "forward" and current_pos.y<3)
            position.y = current_pos.y + 1;
        else if(dir == "backward" and current_pos.y>0)
            position.y = current_pos.y - 1;
        else if(dir == "left" and current_pos.x>0)
            position.x = current_pos.x - 1;
        else if(dir == "right" and current_pos.x<3)
            position.x = current_pos.x + 1;
        else
        {
    
        }*/
        return destination_pos;

    }
    // gives us position of 
    void Actuates(pos position,string element){
        if (element == "wumpus")
            {
            // set every other room wumpus variable false
            // since we only have one wumpus
            for(int i=0;i<4;i++)
                for(int j=0;j<4;j++)
                    hist_agent.W[i][j] = false;
            hist_agent.W[position.x][position.y] = true;
            }
        else if (element == "gold"){
            Move(position);
            hist_agent.G[position.x][position.y] = true;
            cout<<"game over";
        }
        else if (element == "okay"){
            okay_rooms.push(position);
            hist_agent.Ok[position.x][position.y];
        }
        else{

        }
        
            
    }

    void initialize_movt(){
        
    }
    void Decide(history){
        
    }

};