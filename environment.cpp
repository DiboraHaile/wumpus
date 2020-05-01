#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h> 
#include <stdio.h> 
#include <vector>
#include "environment.hpp"
//#include "rules.hpp"
#include "agent.hpp"
using namespace std;

environment:: environment(){
    perception env_percept;
    position ok_room_pos;
    // creating an agent
    Agent my_agent = Agent();
    env_percept = display_envt(my_agent.current_pos);
    //while(!my_agent.okay_rooms.empty()){
        ok_room_pos = my_agent.okay_rooms.top();
        my_agent.current_pos = my_agent.Move(ok_room_pos);
        my_agent.update_history(env_percept,my_agent.current_pos);
        //cout<<my_agent.agent_history.B[my_agent.current_pos.x][my_agent.current_pos.y]<<"\n";
        my_agent.Decide(my_agent.agent_history,my_agent.current_pos);
        my_agent.okay_rooms.pop();
        delay(1);
        
    //}
    // if out of this loop means okay rooms is empty
    // so we call decide with the element empty
    my_agent.Actuates(my_agent.current_pos,"empty");
     
}

pos_arr environment::generate_positions(){
    pos_arr array; 
    position generated_pos,pos;
    vector<position> generate_from;
    vector<position>::iterator it; 
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++){
            pos.x = i;
            pos.y = j;
            if(!(pos.x == 0 and pos.y == 0) and !(pos.x == 0 and pos.y == 1)and !(pos.x == 1 and pos.y == 0))
            generate_from.push_back(pos);
        }

int ind;
    for (int k=0;k<5;k++){
        // leave 0,0 1,0 and 0,1 empty
            srand(time(0));
            
            ind = rand() % generate_from.size();
            array.arr[k] = generate_from[ind];

             generate_from.erase(generate_from.begin()+ind);
          
            }
    return array;
}

stack<position> environment::neighbours(position pos){
    stack<position> neighs;
    position left_neigh,right_neigh,up_neigh,down_neigh;
    if (pos.x >= 0 and pos.x < 3){
        right_neigh.x = pos.x + 1;
        right_neigh.y = pos.y;
        neighs.push(right_neigh);
    }
    if (pos.x <= 3 and pos.x > 0){
        left_neigh.x = pos.x - 1;
        left_neigh.y = pos.y;
        neighs.push(left_neigh);
    }
    if (pos.y <= 3 and pos.y > 0){
        down_neigh.y = pos.y - 1;
        down_neigh.x = pos.x;
        neighs.push(down_neigh);
    }
    if (pos.y >= 0 and pos.y < 3){
        up_neigh.y = pos.y + 1;
        up_neigh.x = pos.x;
        neighs.push(up_neigh);
    }
    
    return neighs;

}
perception environment::display_envt(position agent_pos){
    pos_arr pos;  
    stack<position> neigh_stack;
    int t = 0;
    position popped_neighbour;
    perception env_perception;
    char ele[5] = {'G','W','P','P','P'};
    srand(time(0));
    pos = generate_positions();


for (int i=0;i<4;i++){
    for (int j=0;j<4;j++){
        grid[i][j] = "0";
    }
}


for (int t=0;t<5;t++){
    grid [pos.arr[t].x][pos.arr[t].y] = ele[t];
    neigh_stack = neighbours(pos.arr[t]);
    // set environment elements W,P,G
    if (ele[t] == 'W')
        env_perception.W.push_back(pos.arr[t]);
    else if (ele[t] == 'G')
        env_perception.G.push_back(pos.arr[t]);
    else if (ele[t] == 'P')
        env_perception.P.push_back(pos.arr[t]);
    // set environment perceptions S,B
    while(!neigh_stack.empty()){
        popped_neighbour = neigh_stack.top();
        neigh_stack.pop();
        if (ele[t] == 'P'){       
            env_perception.B.push_back(popped_neighbour);
            if ((grid[popped_neighbour.x][popped_neighbour.y]) == "0")
                grid[popped_neighbour.x][popped_neighbour.y] = "b";
            else if ((grid[popped_neighbour.x][popped_neighbour.y]) != "b")
                grid[popped_neighbour.x][popped_neighbour.y] += "b";           
        }        

            
        else if (ele[t] == 'W'){
            env_perception.W.push_back(pos.arr[t]);
            if ((grid[popped_neighbour.x][popped_neighbour.y]) == "0")
                grid[popped_neighbour.x][popped_neighbour.y] = "s";
            else if ((grid[popped_neighbour.x][popped_neighbour.y]) != "s")
                grid[popped_neighbour.x][popped_neighbour.y] += "s";
        }
  
        else
        {
            
        }
        neighbours(pos.arr[t]).pop();
    }
            
}
    // print agent
    if (grid[agent_pos.x][agent_pos.y] != "0")
        grid[agent_pos.x][agent_pos.y] += "X";
    else
        grid[agent_pos.x][agent_pos.y] = "X";
    
   for (int i=0;i<4;i++){
    for (int j=0;j<4;j++){
        cout<<grid[i][j]<<"          ";
    }
    cout<<"\n\n\n\n";
    }
}

void environment::print_agent(position current_pos){
    grid[current_pos.x][current_pos.y] = "x";
    cout<<grid[current_pos.x][current_pos.y];
}

int environment::print_msg(string msg){
    if (msg == "over")
        cout<<"Game over";
    else
        cout<<"You won";
    return 0;
}

void delay(int number_of_seconds) 
{ 
    // Converting time into milli_seconds 
    int milli_seconds = 1000 * number_of_seconds; 
  
    // Storing start time 
    clock_t start_time = clock(); 
  
    // looping till required time is not achieved 
    while (clock() < start_time + milli_seconds) 
        ; 
} 






