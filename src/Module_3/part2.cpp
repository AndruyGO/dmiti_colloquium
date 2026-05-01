#include "part0.h"
#include "../Module_1/part1.h"
#include "../Module_1/part3.h"


char INT_Q_B(const big_Q& q) {
    if (COM_NN_D(q.down, big_N("1")) == 0) 
        return 1;
    return 0;
}


big_Q RED_Q_Q(const big_Q& q) {
    big_N nod = GCF_NN_N(q.up, q.down);
    big_N up = DIV_NN_N(q.up, nod);
    big_N down = DIV_NN_N(q.down, nod);
    return big_Q(q.sign, up, down);
}
