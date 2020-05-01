#pragma once
#include <iostream>
#include <string>
#include <stack>
#include <queue> 
#include <map>
#include "helper_methods_inv.hpp"
//#include "to_postfix.hpp"
// added for test
#include "rules.hpp"
using namespace std;

struct argument_info{
    queue <string> cont;
    int len;
    int statement;
};

struct statement_info{
    queue<string> container;
    int len;
    
};

bool is_operator(string arg);

argument_info separate_arg_elements(string x);
operand_vals operate_on(string oper,bool result);

bool tablox(vector<queue<string>> statement);