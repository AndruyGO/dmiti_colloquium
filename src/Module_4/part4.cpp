#include "part0.h"
#include "part2.h"
#include "part3.h"
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
   return res;
}
big_P GCF_PP_P (const big_P& p1,const big_P& p2){
   big_P new_p1 = p1;
   big_P new_p2 = p2;
   while (new_p1.monomials.size() != 0 && new_p2.monomials.size() != 0){
      if (DEG_P_N(new_p1)>DEG_P_N(new_p2)){
         new_p1 = MOD_PP_P(new_p1,new_p2);
      }
      else{
         new_p2 = MOD_PP_P(new_p2,new_p1);
      }
   }
   if (new_p1.monomials.size() == 0){
      return new_p2;
   }
   else{
      return new_p1;
   }
}
big_P NMR_P_P(const big_P& p){
   big_P der = DER_P_P(p);
   if (der.monomials.empty()) return p;
   big_P NOD = GCF_PP_P(p, der);
   return DIV_PP_P(p, NOD);
}