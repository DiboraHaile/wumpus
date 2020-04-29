#include <iostream>
#include "environment.hpp"
#include "rules.hpp"
//#include "to_postfix.hpp"
#include "tablox.hpp"
#include "agent.hpp"
#include <stack>
#include <string>
using namespace std;

queue<string> r1,r2;
argument_info separate_arg_elements(string x){
string word = "";
int count = 0;
queue <string> contain;
argument_info info;
for(int i=0; i< x.size();i++)
{
    if(x[i] != ','){
        word = word + x[i];
    }
    else
    {
        contain.push(word);
        count++;
        word.clear();
    }


}

info.cont = contain;
info.len = count;
return info;
}

bool str_bool(string x){
        if(x == "true")
            return 1;
        else
            return 0;
        
    }

map<char,bool> return_history_pos(position current_pos,history agent_history){
     map<char,bool> agent_hist;
     agent_hist.insert(pair<char,bool>('b',str_bool(agent_history.B[current_pos.x][current_pos.y])));
     agent_hist.insert(pair<char,bool>('p',str_bool(agent_history.P[current_pos.x][current_pos.y])));
     agent_hist.insert(pair<char,bool>('s',str_bool(agent_history.S[current_pos.x][current_pos.y])));
     agent_hist.insert(pair<char,bool>('w',str_bool(agent_history.W[current_pos.x][current_pos.y])));
    return agent_hist;

}
map<char, string> form_argument(position cur_pos,map<char,bool> a_hist){
    string b_arg,s_arg;
    map<char, bool>::iterator itr; 
    map<char, string> argument;
    for (itr = a_hist.begin(); itr != a_hist.end(); ++itr) {
        if (itr->second)
            argument.insert(pair<char,string> (itr->first,(itr->first)+to_string(cur_pos.x)+to_string(cur_pos.y)+","));
        else
            argument.insert(pair<char,string> (itr->first,(itr->first)+to_string(cur_pos.x)+to_string(cur_pos.y)+",not,"));
 
    }
    // loop and get truth values if true append the argument

    return argument;
}

stack<position> neighbours(position pos){
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



void Rules(position pos_ele,string name){
    string rule1,rule2,s_or_b;
    stack<position> neighs;
    neighs = neighbours(pos_ele);
    cout<<neighs.size()<<"\n";
    if (name == "w")
        s_or_b = "s";
    else if (name == "p")
        s_or_b = "b";
    //concatenating the name suitable for tableau
    rule1= s_or_b+to_string(pos_ele.x)+to_string(pos_ele.y)+",not,";
    rule2 = s_or_b+to_string(pos_ele.x)+to_string(pos_ele.y)+",";
    int neigh_size = neighs.size();
    string and_no,or_no;
    for(int j=0;j<neigh_size-1;j++)
        and_no += "and,";
        or_no += "or,";
    for(int i=0;i<neigh_size;i++){
        rule1 += name+to_string(neighs.top().x) + to_string(neighs.top().y) + ",not,";
        rule2 += name+to_string(neighs.top().x) + to_string(neighs.top().y) + ",";
        neighs.pop();

        }
        rule1 += and_no +"imp,";
        rule2 += or_no + "imp,"; 
        r1 = separate_arg_elements(rule1).cont;
        r2 = separate_arg_elements(rule2).cont;
        
    }


void check_pit(position cur_pos,position neigh_pos,history hist_agent){
    vector<queue<string>> statement;
    string conclusion;
    Rules(cur_pos,"p");
    
    auto pos = form_argument(cur_pos,return_history_pos(cur_pos,hist_agent)).find('b');
    if (pos->second.length() > 4){
        statement.push_back(r1);
        conclusion = "p"+to_string(cur_pos.x)+to_string(cur_pos.y)+",not,";
    }
    else{
        statement.push_back(r2);
        conclusion = "p"+to_string(cur_pos.x)+to_string(cur_pos.y)+",";
    }
    statement.push_back(separate_arg_elements(pos->second).cont);
    statement.push_back(separate_arg_elements(conclusion).cont);
    cout<<tablox(statement);
    //statement.push_back(form_argument(cur_pos));

    // insert to the tablox r1 and notbneigh_pos if not b
    
    
}
bool no_wumpus(position cur_pos){

    return false;

}

int main(){
    position t;
    t.x = 0;
    t.y = 0;
    position t_1;
    t_1.x = 0;
    t_1.y = 1;

    history hist_agent;
    hist_agent.B[t.x][t.y] = "false";
    hist_agent.W[t.x][t.y] = "false";
    hist_agent.S[t.x][t.y] = "true";
    hist_agent.P[t.x][t.y] = "false";

    
    check_pit(t,t_1,hist_agent);

    //cout<<str_bool("true");
}