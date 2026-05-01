#include "part0.h"
#include "../Module_1/natural.h"
#include "../Module_2/part2.h"
#include "../Module_2/part3.h"

big_Q TRANS_Z_Q(big_Z& z) {
    big_Q q;
    q.sign = z.sign;
    q.down = big_N("1");
    q.up = TRANS_Z_N(ABS_Z_Z(z));
    return q;
}

big_Z TRANS_Q_Z(big_Q& q) {
    if (COM_NN_D(q.down, big_N("1")) != 1)
        return big_Z();

    big_Z z;
    z.digits = q.up.digits;
    z.sign = q.sign;
    return z;
}
