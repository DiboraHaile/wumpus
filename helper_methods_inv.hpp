#include <iostream>
struct operand_vals{
        bool truth_vs[2];
        bool branch;
    };
class helper_methods_inv{
    public:
    operand_vals INot(bool result);

    operand_vals IAnd(bool result);

    operand_vals IOr(bool result);

    operand_vals IImp(bool result);

    operand_vals IBimp(bool result);
};