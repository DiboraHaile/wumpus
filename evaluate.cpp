#include "helper_methods.hpp"
#include "to_postfix.hpp"
#include <iostream>
#include <string>
#include <stack>
#include <queue> 
using namespace std;

struct argument_info{
    queue <string> cont;
    int len;
};


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



///////
bool str_bool(string x){
        if(x == "true")
            return 1;
        else
            return 0;
        
    }
////////////////////
bool operators(string oper, bool a){
    helper_methods operations = helper_methods();
    if(oper == "not")
    return operations.Not(a);

}
bool operators(string oper,bool a,bool b){
    helper_methods operations = helper_methods();
    if (oper == "and"){
        return operations.And(a,b);
    }
    else if (oper == "or")
    {
        return operations.Or(a,b);
    }
    else if (oper == "imp")
    {
        return operations.Imp(a,b);
    }
    else if (oper == "bimp")
    {
        return operations.Bimp(a,b);
    }
    else
    return false;
}

bool evaluate(queue<string> postfix){
    string x;
int operand_no;
queue <bool> operand;

while(!postfix.empty()){
    cout<<postfix.front();
   
    //

    if(!is_operator(postfix.front())){
        operand.push(str_bool(postfix.front()));
        postfix.pop();
    }
    else{
        if (postfix.front() == "not"){
            operand.push(operators("not",operand.back()));
            
        }
        else {
           string a,b;
           a = operand.front();
           operand.pop();
           b = operand.front();
           operand.pop();
           operand.push(operators(postfix.front(),str_bool(a),str_bool(b)));
           //c = evaluate(postfix.front(),str_bool(a),str_bool(b));
            
        }
       postfix.pop();
    }
    }
    return operand.front();
}
///////////
int main()
{
  
string argument;
queue <string> contain;
queue <string> postfix;
argument_info inf;
int length_ ;
bool c;

cout<<"enter your expression:";
cin>>argument;
inf =separate_arg_elements(argument);
postfix = to_postfix(inf.cont,inf.len);
cout<<"\n"<<evaluate(postfix);



    //cout<<"\n"<<
}
