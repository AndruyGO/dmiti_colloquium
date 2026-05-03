#include "part0.h"
#include "../Module_1/part3.h"
#include "../Module_1/part2.h"


big_P DER_P_P(const big_P& p){
   big_P res = p;
 
   for (int i = 0;i<p.monomials.size(); i++){
      monomial m = p.monomials[i];
      if (m.degree.digits.size() == 1 && m.degree.digits[0] == 0){
         res.monomials[i].val.up = big_N("0");
      }
      else{
         res.monomials[i].val.up = MUL_NN_N(res.monomials[i].val.up, res.monomials[i].degree);
         res.monomials[i].degree = SUB_NN_N(res.monomials[i].degree,big_N("1"));
      }
      }
   sort(res.monomials.begin(), res.monomials.end());
   res.combine_monoms();
   return res;
}
