#include "part0.h"
#include "part1.h"
#include "part2.h"
#include "part3.h"
#include "part4.h"

#include <algorithm>

#define BIGGER 2
#define SMALLER 1
#define EQUAL 0

char DIV_NN_Dk(const big_N& x, const big_N& y, i64 k) {
  big_N mul_y("");
  if (k == 0)
    mul_y = y;
  else
    mul_y = MUL_Nk_N(y, k);

  char i = 1;
  while (i < 10 && COM_NN_D(x, MUL_ND_N(mul_y, i)) != SMALLER)
    ++i;

  return i - 1;
}

big_N DIV_NN_N(const big_N& x, const big_N& y) {
  if (COM_NN_D(y, big_N("0")) == EQUAL)
    return big_N("");
  i64 cmp = COM_NN_D(x, y);

  if (cmp == SMALLER)
    return big_N("0");
  else if (cmp == EQUAL)
    return big_N("1");

  big_N remainder = big_N {x};
  std::vector<char> result {};

  while (COM_NN_D(remainder, y) == BIGGER) {
    i64 k;

    if (COM_NN_D(remainder, MUL_Nk_N(y, remainder.digits.size() -
                                            y.digits.size())) != SMALLER)
      k = remainder.digits.size() - y.digits.size();
    else if (remainder.digits.size() > 1)
      k = remainder.digits.size() - y.digits.size() - 1;

    char digit = DIV_NN_Dk(remainder, y, k);
    if (digit == 0)
      break;

    result.push_back(digit);
    big_N temp("");
    // Проверка на ноль так как MUL_Nk_N при k = 0 иначе че то не то возвращает
    if (k == 0)
      temp = y;
    else
      // Приходится пересчитывать, хоть в DIV_NN_Dk это уже вычисляется
      // Если не использовать DIV_NN_Dk то можно без этого обойтись но раз надо юзать то юзаю
      temp = MUL_Nk_N(y, k);

    remainder = SUB_NDN_N(remainder, temp, digit);
  }

  std::reverse(result.begin(), result.end());
  big_N quotinent = big_N {result};

  return quotinent;
}

big_N MOD_NN_N(const big_N& x, const big_N& y) {
  if (COM_NN_D(y, big_N("0")) == EQUAL)
    return big_N("");
  big_N quotinent = DIV_NN_N(x, y);
  return SUB_NN_N(x, MUL_NN_N(quotinent, y));
}
