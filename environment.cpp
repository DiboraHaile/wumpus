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
    env_percept = create_envt(my_agent.current_pos);
    loop:
   while(!my_agent.okay_rooms.empty()){
        
        ok_room_pos = my_agent.okay_rooms.top();
        my_agent.okay_rooms.pop();
        my_agent.current_pos = my_agent.Move(ok_room_pos);
        my_agent.visited_rooms.push_back(ok_room_pos);
        my_agent.update_history(env_percept,my_agent.current_pos);
        my_agent.Decide(my_agent.agent_history,my_agent.current_pos);
        
        //cout<<"\n"<<my_agent.okay_rooms.top().x<<my_agent.okay_rooms.top().y<<"\n";
        system("clear");
        //my_agent.visited_rooms.push()
        display_envt(env_percept,my_agent.current_pos);
         if (my_agent.agent_history.G[my_agent.current_pos.x][my_agent.current_pos.y] == "true")
        my_agent.Actuates("gold");
         else if (my_agent.agent_history.P[my_agent.current_pos.x][my_agent.current_pos.y] == "true")
        my_agent.Actuates("pit");
        else if (my_agent.agent_history.W[my_agent.current_pos.x][my_agent.current_pos.y] == "true")
        my_agent.Actuates("wumpus");
        delay(4000);
    
   }
    // if out of this loop means okay rooms is empty
    // so we call decide with the element empty
   
    my_agent.Actuates("empty");
    goto loop;
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

perception environment::create_envt(position agent_pos){
    pos_arr pos;  
    stack<position> neigh_stack;
    int t = 0;
    position popped_neighbour;
    perception env_perception;
    char ele[5] = {'G','W','P','P','P'};
    srand(time(0));
    pos = generate_positions();


for (int t=0;t<5;t++){
    //grid [pos.arr[t].x][pos.arr[t].y] = ele[t];
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
        if (ele[t] == 'P')  
            env_perception.B.push_back(popped_neighbour);
        else if (ele[t] == 'W')
            env_perception.S.push_back(popped_neighbour);
    }
            
}
 return env_perception;
}

void display_envt(perception env, position cur_p){
    string grid[4][4];
    for (int i=0;i<4;i++){
    for (int j=0;j<4;j++){
        grid[i][j] = "0";
               
    }
    }
    for (int t=0;t<env.B.size();t++)
        grid[env.B[t].x][env.B[t].y] = "b";
    for (int k=0;k<env.S.size();k++)
        if (grid[env.S[k].x][env.S[k].y] == "b")
            grid[env.S[k].x][env.S[k].y] = "bs"; 
        else
            grid[env.S[k].x][env.S[k].y] = "s";
    for (int r=0;r<env.P.size();r++)
         grid[env.P[r].x][env.P[r].y] = "P";
    grid[env.G[0].x][env.G[0].y] = "G";
    grid[env.W[0].x][env.W[0].y] = "W";

    grid[cur_p.x][cur_p.y] = "X";
    
   for (int i=0;i<4;i++){
    for (int j=0;j<4;j++){
        cout<<grid[i][j]<<"          ";
    }
    cout<<"\n\n\n\n";
    }
    cout<<"\n\n\n";


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






