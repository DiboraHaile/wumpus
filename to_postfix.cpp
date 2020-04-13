#include <iostream>
#include <queue>
#include <stack>
#include <string>
using namespace std;

bool is_operator(string arg){
if(arg == "and" or arg == "or" or arg == "not" or arg == "imp" or arg == "bimp" or arg == "(" or arg == ")")
 return true;
else
 return false;
}

queue<string> to_postfix(queue<string> contain,int length_)
{
stack <string> oper;
queue <string> postfix;
string popped;
bool presc = false;

for(int k=0;k<length_;k++){
    popped = contain.front();
    contain.pop();
    //if it isnot operator push to postfix
    if(!is_operator(popped))
        postfix.push(popped);

    else 
    //if operator push to operand stack
    {       
        if(!oper.empty()){
            if(popped == ")")
            {
                // if operator stack not empty and the operator is )
                // pop until ( can be found
                presc = false;
                while(oper.top() != "("){
                    postfix.push(oper.top());
                    oper.pop();
                }
                oper.pop();
            }
            else{
                // if operator stack not empty and operator is (
                if(popped == "(")
                {
                   // push ( to the operator stack and set presc true
                   presc = true;
                   oper.push(popped);
                }
                else{
                    // if presc true, push the operator 
                    if(presc == true){
                        oper.push(popped);
                    }
                    // if presc false, pop the operator in the operator stack
                    // and push the upcoming operator 
                    else{
                postfix.push(oper.top());
                oper.pop();
                oper.push(popped);
                }
           
        }
        }
        }
        // if operator stack is empty, push the operator
        else
        {
            oper.push(popped);
        }
        
    }
    
}
postfix.push(oper.top());
oper.pop();

return postfix;
}