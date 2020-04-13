#include <iostream>
#include <string>
#include "helper_methods.hpp"


    bool helper_methods::Not(bool a){
        int operand_no = 1;
        return !a;
    }
    bool helper_methods::And(bool a, bool b){
        int operand_no = 2;
        if (a and b)
        return true;
        else
        return false;
    }

    bool helper_methods::Or(bool a, bool b){
        int operand_no = 2;
        if (a or b)
        return true;
        else
        return false;
    }

    bool helper_methods::Imp(bool a, bool b){
        int operand_no = 2;
        if (!a or b)
        return true;
        else
        return false;
    }

    bool helper_methods::Bimp(bool a, bool b){
        int operand_no = 2;
        if ((a and b) or (!a and !b))
        return true;
        else
        return false;
    }

