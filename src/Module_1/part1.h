#pragma once
#include "part0.h"

using u32 = unsigned long;

char DIV_NN_Dk(const big_N& x, const big_N& y, u32 k); 

big_N DIV_NN_N(const big_N& x, const big_N& y);
 
big_N MOD_NN_N(const big_N& x, const big_N& y); 
