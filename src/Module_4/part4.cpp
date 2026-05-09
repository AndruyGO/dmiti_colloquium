#include "part0.h"
#include "part2.h"
#include "part3.h"
#include "../Module_1/part3.h"
#include "../Module_1/part2.h"

big_P DER_P_P(const big_P& p){
   big_P res;
   
   for (const auto& m : p.monomials) {
      if (!(m.degree.digits.size() == 1 && m.degree.digits[0] == 0)) {
         monomial new_m = m;
         new_m.val = MUL_QQ_Q(new_m.val, big_Q(1, m.degree, big_N("1")));
         new_m.degree = SUB_NN_N(m.degree, big_N("1"));
         res.monomials.push_back(new_m);
      }
   }
   
   return res;
}

big_P GCF_PP_P (const big_P& p1, const big_P& p2){
   big_P new_p1 = p1;
   big_P new_p2 = p2;

   // Пока оба полинома не нулевые
   while (NZER_P_B(new_p1) && NZER_P_B(new_p2)){
      // Сравниваем степени
      if (COM_NN_D(DEG_P_N(new_p1), DEG_P_N(new_p2)) == 2){
         // Степень new_p1 больше - заменяем new_p1 на остаток от деления new_p1 на new_p2
         new_p1 = MOD_PP_P(new_p1, new_p2);
      } else {
         // Степень new_p2 больше или равна - заменяем new_p2 на остаток от деления new_p2 на new_p1
         new_p2 = MOD_PP_P(new_p2, new_p1);
      }
   }
   
   // Если new_p1 нулевой, то НОД = new_p2, иначе new_p1
   big_P result = (new_p1.monomials.empty()) ? new_p2 : new_p1;
   
   // Делим результат на старший коэффициент, чтобы сделать его приведённым
   return DIV_PQ_P(result, LED_P_Q(result));
}

big_P NMR_P_P(const big_P& p){
   big_P der = DER_P_P(p);
   if (!NZER_P_B(der)) return p;
   big_P NOD = GCF_PP_P(p, der);
   return DIV_PP_P(p, NOD);
}