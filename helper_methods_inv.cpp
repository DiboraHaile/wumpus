#include <iostream>
#include "helper_methods_inv.hpp"


operand_vals helper_methods_inv::INot(bool result){
    int operand_no = 1;
    operand_vals not_op;
    not_op.truth_vs[0] = !result;
    return not_op;
}
operand_vals helper_methods_inv::IAnd(bool result){
    int operand_no = 2;
    operand_vals op;
   if (result)
    {
        op.truth_vs[0] = 1;
        op.truth_vs[1] = 1;
        op.branch = 0;
        return op;
    }    
    else
    {
        op.truth_vs[0] = 0;
        op.truth_vs[1] = 0;
        op.branch = 1;
        return op;
    }
}

operand_vals helper_methods_inv::IOr(bool result){
   int operand_no = 2;
    operand_vals op;
    if (result)
    {
        op.truth_vs[0] = 1;
        op.truth_vs[1] = 1;
        op.branch = 1;
        return op;
    }    
    else
    {
        op.truth_vs[0] = 0;
        op.truth_vs[1] = 0;
        op.branch = 0;
        return op;
    }
    }


operand_vals helper_methods_inv::IImp(bool result){
     int operand_no = 2;
    operand_vals op;
    if (result)
    {
        op.truth_vs[0] = 0;
        op.truth_vs[1] = 1;
        op.branch = 1;
        return op;
    }    
    else
    {
        op.truth_vs[0] = 1;
        op.truth_vs[1] = 0;
        op.branch = 0;
        return op;
    }
}

operand_vals helper_methods_inv::IBimp(bool result){

}