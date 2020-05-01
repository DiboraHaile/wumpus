#include <iostream>
#include <string>
#include <stack>
#include <queue> 
#include <map>
#include "helper_methods_inv.hpp"
#include "tablox.hpp"
// added for test
//#include "rules.hpp"
using namespace std;



bool is_operator(string arg){
if(arg == "and" or arg == "or" or arg == "not" or arg == "imp" or arg == "bimp" or arg == "(" or arg == ")")
 return true;
else
 return false;
}


operand_vals operate_on(string oper,bool result){
helper_methods_inv inv_methods = helper_methods_inv();
    if(oper == "not")
        return inv_methods.INot(result);
    else if (oper == "and")
    return inv_methods.IAnd(result);
    else if (oper == "or")
        return inv_methods.IOr(result);
    else if (oper == "imp")
        return inv_methods.IImp(result);
    else if (oper == "bimp")
        return inv_methods.IBimp(result);
    else
    return inv_methods.IBimp(result);
}

bool tablox(vector<queue<string>> statement){
int operand_no;
queue<string> argument;
bool prem = true;
stack <bool> truth_vs;
string operand;
multimap<string,bool> values;
bool tv;
operand_vals tv_from_inverse;
bool return_value = true;
// accept the statement and try to divide 
// the arguments

for(int i=0; i< statement.size();i++)
{
    //set the truth value of the argument true if premises
    //false if conclusion
    if(i == statement.size()-1)
        truth_vs.push(false);
    else
    {
        truth_vs.push(true);
    }
    
argument = statement[i];
while(!argument.empty())
 {
     // if operator, get the inverse value/s
     // and push to the stack truth_vs
    if(is_operator(argument.back())){
         tv_from_inverse = operate_on(argument.back(),truth_vs.top());
         truth_vs.pop();
         if ( argument.back() == "not"){
            truth_vs.push(tv_from_inverse.truth_vs[0]);
         }
         else
         {
            truth_vs.push(tv_from_inverse.truth_vs[0]);
            truth_vs.push(tv_from_inverse.truth_vs[1]);
         }
         argument.pop();
    // if not operator, pop from truth_vs and 
    // assign them to the operands
    }
    else
    {
        
        operand = argument.back();
        tv = truth_vs.top();
        if (values.empty())
            values.insert(pair<string, bool>(operand,tv));
        else{
        auto pos = values.find(operand);
        if (pos-> second == tv)
            return false;
        else{
        values.insert(pair<string, bool>(operand,tv));
        // search for a variable with the same key and if there is
        // them if different continue ifnot abort and return false
        truth_vs.pop();
        }
        }
    }
    
         
     }
   
}
return return_value;
}
/*
int main(){
    queue<string> r1,r2,r3,r4;
    vector<queue<string>> statement;
    string r_s = "pos,not,pos_r,not,pos_l,not,pos_u,not,pos_d,not,and,and,and,imp,";
    string r_not_s= "pos,pos_r,pos_l,pos_u,pos_d,or,or,or,imp,";
    string n_s = "pos,not,";
    string n_r = "pos_l,not,";
    r1 = separate_arg_elements(r_s).cont;
    r2 = separate_arg_elements(r_not_s).cont;
    r3 = separate_arg_elements(n_s).cont;
    r4 = separate_arg_elements(n_r).cont;
    statement.push_back(r1);
    statement.push_back(r3);
    statement.push_back(r4);
    cout<<tablox(statement);
}*/