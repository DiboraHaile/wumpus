#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h> 
#include "environment.hpp"
//#include "rules.hpp"
#include "agent.hpp"
using namespace std;

environment:: environment(){
    position agent_pos;
    Agent my_agent = Agent();
    agent_pos = my_agent.current_pos;
    display_envt(agent_pos);
     
}
position environment::generate_random(){
    position generate_pos;
    generate_pos.x= rand() % 4;
    if (generate_pos.x == 0)
    generate_pos.y= (rand() % 2)+2;
    else if (generate_pos.x == 1)
    generate_pos.y= (rand() % 3)+1;
    else
    generate_pos.y= rand() % 4;

    return generate_pos;

}
pos_arr environment::generate_positions(){
    pos_arr array; 

    for (int k=0;k<5;k++){
        // leave 0,0 1,0 and 0,1 empty
       
        array.arr[k].x = generate_random().x;
        array.arr[k].y = generate_random().y;
        //cout<<"the values generated at first with k "<<k<<"\n";
        
        //generate unique numbers
       
        for (int i = 0;i<k;i++){
            while (array.arr[k].x == array.arr[i].x and array.arr[k].y == array.arr[i].y)
            {
            
            array.arr[k].x = generate_random().x;
            array.arr[k].y = generate_random().y;
            
            }
            //cout<<"the values generated corrected with i "<<i<<"\n";
        //cout<<array.arr[k].x;
        //cout<<array.arr[k].y; 
        //cout<<"\n";
        }
        //cout<<array.arr[k].x;
        //cout<<array.arr[k].y;   
        //cout<<"\n";s
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
void environment::display_envt(position agent_pos){
    srand(time(0));
    pos_arr pos;  
    stack<position> neigh_stack;
    int t = 0;
    position popped_neighbour;
    pos = generate_positions();


for (int i=0;i<4;i++){
    for (int j=0;j<4;j++){
        grid[i][j] = "0";
    }
}


for (int t=0;t<5;t++){
    grid [pos.arr[t].x][pos.arr[t].y] = ele[t];
    neigh_stack = neighbours(pos.arr[t]);
    while(!neigh_stack.empty()){
        popped_neighbour = neigh_stack.top();
        neigh_stack.pop();
        if (ele[t] == 'P'){            
            if ((grid[popped_neighbour.x][popped_neighbour.y]) == "0")
                grid[popped_neighbour.x][popped_neighbour.y] = "b";
            else if ((grid[popped_neighbour.x][popped_neighbour.y]) != "b")
                grid[popped_neighbour.x][popped_neighbour.y] += "b";           
        }        
                //Rules(P,'p');
            
        else if (ele[t] == 'W'){
            if ((grid[popped_neighbour.x][popped_neighbour.y]) == "0")
                grid[popped_neighbour.x][popped_neighbour.y] = "s";
            else if ((grid[popped_neighbour.x][popped_neighbour.y]) != "s")
                grid[popped_neighbour.x][popped_neighbour.y] += "s";
        }
            //Rules(W,'w');
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

vector<char> element_in_room(position current_pos){

}




