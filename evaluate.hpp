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


argument_info separate_arg_elements(string x);

bool str_bool(string x);

bool operators(string oper, bool a);

bool operators(string oper,bool a,bool b);

bool evaluate(queue<string> postfix);

