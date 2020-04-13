#include <iostream>
#include "environment.hpp"
#include "rules.hpp"
#include <stack>
using namespace std;


stack<position> neighbours(position pos){
    stack<position> neighs;
    position left_neigh,right_neigh,up_neigh,down_neigh;
    if (pos.x >= 0 and pos.x < 3){
        right_neigh.x = pos.x++;
        right_neigh.y = pos.y;
        neighs.push(right_neigh);
    }
    else if (pos.x <= 3 and pos.x > 0){
        left_neigh.x = pos.x--;
        left_neigh.y = pos.y;
        neighs.push(left_neigh);
    }
    else if (pos.y <= 3 and pos.y > 0){
        down_neigh.y = pos.y--;
        down_neigh.x = pos.x;
        neighs.push(down_neigh);
    }
    else if (pos.y >= 0 and pos.y < 3){
        up_neigh.y = pos.y++;
        up_neigh.x = pos.x;
        neighs.push(up_neigh);
    }
    else{
        }
    return neighs;

}
void Rules(position pos_ele,char name){
  
    }
bool no_pit(position cur_pos){

}
bool no_wumpus(position cur_pos){
    

}
