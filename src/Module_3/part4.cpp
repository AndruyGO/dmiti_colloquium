#include "part0.h"
#include "part2.h"
#include "../Module_1/part3.h"
#include "../Module_1/part1.h"
#include "../Module_1/part2.h"
#include "../Module_2/part2.h"
#include "../Module_2/part3.h"
#include "../Module_2/part4.h"

big_Q ADD_QQ_Q(const big_Q& q1,const big_Q& q2){
   if (q1.sign == 0) return q2;
   if (q2.sign == 0) return q1;
   big_Q res;
   big_Z new_q1;
   big_Z new_q2;
   big_N NOK = LCM_NN_N(q1.down,q2.down);
   res.down = NOK;
   new_q1 = TRANS_N_Z(DIV_NN_N(MUL_NN_N(q1.up,NOK),q1.down));
   new_q2 = TRANS_N_Z(DIV_NN_N(MUL_NN_N(q2.up,NOK),q2.down));
   new_q1.sign = q1.sign;
   new_q2.sign = q2.sign;
   big_Z sum = ADD_ZZ_Z(new_q1, new_q2);
   res.sign = sum.sign;
   big_Z abs_sum = ABS_Z_Z(sum);
   res.up = TRANS_Z_N(abs_sum);

   if (!NZER_N_B(res.up)) {
      res.sign = 0;
      return res;
   }
   return res;
}

big_Q SUB_QQ_Q(const big_Q& q1,const big_Q& q2){
   big_Q new_q2 = q2;
   new_q2.sign = new_q2.sign * (-1);
   return ADD_QQ_Q(q1,new_q2);
}
