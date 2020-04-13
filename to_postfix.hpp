#include <iostream>
#include <queue>
#include <stack>
#include <string>
using namespace std;


bool is_operator(string arg);
queue<string> to_postfix(queue<string> contain,int length_);