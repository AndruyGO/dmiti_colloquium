#include "Module_1/natural.h"
#include "Module_2/integer.h"
#include "Module_3/rational.h"
#include "Module_4/polinoms.h"
#include <cassert>
#include <iostream>
#include <string>

using namespace std;
void test_mul_pxk() {
    cout << "\n========== MUL_Pxk_P ==========\n";
    
    big_P p1("x^2+2x+1");
    big_P r1 = MUL_Pxk_P(p1, big_N("3"));
    cout << "Input: " << p1 << " * x^3\n";
    cout << "Output: " << r1 << "\n";
    cout << "Expected: x^5+2x^4+1x^3\n\n";
    
    big_P p2("5x^3-2x");
    big_P r2 = MUL_Pxk_P(p2, big_N("1"));
    cout << "Input: " << p2 << " * x^1\n";
    cout << "Output: " << r2 << "\n";
    cout << "Expected: 5x^4-2x^2\n\n";
    
    big_P p3("7");
    big_P r3 = MUL_Pxk_P(p3, big_N("0"));
    cout << "Input: " << p3 << " * x^0\n";
    cout << "Output: " << r3 << "\n";
    cout << "Expected: 7\n\n";
}

void test_led() {
    cout << "========== LED_P_Q ==========\n";
    
    big_P p1("5x^5-3x^3+2x");
    big_Q r1 = LED_P_Q(p1);
    cout << "Input: " << p1 << "\n";
    cout << "Output: " << r1 << "\n";
    cout << "Expected: 5\n\n";
    
    big_P p2("-2x^4+7x^2");
    big_Q r2 = LED_P_Q(p2);
    cout << "Input: " << p2 << "\n";
    cout << "Output: " << r2 << "\n";
    cout << "Expected: -2\n\n";
    
    big_P p3("3");
    big_Q r3 = LED_P_Q(p3);
    cout << "Input: " << p3 << "\n";
    cout << "Output: " << r3 << "\n";
    cout << "Expected: 3\n\n";
}

void test_deg() {
    cout << "========== DEG_P_N ==========\n";
    
    big_P p1("5x^5-3x^3+2x");
    big_N r1 = DEG_P_N(p1);
    cout << "Input: " << p1 << "\n";
    cout << "Output: " << r1 << "\n";
    cout << "Expected: 5\n\n";
    
    big_P p2("7");
    big_N r2 = DEG_P_N(p2);
    cout << "Input: " << p2 << "\n";
    cout << "Output: " << r2 << "\n";
    cout << "Expected: 0\n\n";
    
    big_P p3("0");
    big_N r3 = DEG_P_N(p3);
    cout << "Input: " << p3 << "\n";
    cout << "Output: " << r3 << "\n";
    cout << "Expected: 0\n\n";
}

void test_fac() {
    cout << "========== FAC_P_Q ==========\n";
    
    big_P p1("2/3x^2+4/6x+2/3");
    big_Q r1 = FAC_P_Q(p1);
    cout << "Input: " << p1 << "\n";
    cout << "Output: " << r1 << "\n";
    cout << "Expected: 2/3 (или 2/3x^2+2/3x+2/3 после вынесения)\n\n";
    
    big_P p2("1/2x+1/4");
    big_Q r2 = FAC_P_Q(p2);
    cout << "Input: " << p2 << "\n";
    cout << "Output: " << r2 << "\n";
    cout << "Expected: 1/4 (или 2x+1)\n\n";
}

void test_mul_pp() {
    cout << "========== MUL_PP_P ==========\n";
    
    big_P p1("x+1");
    big_P p2("x-1");
    big_P r1 = MUL_PP_P(p1, p2);
    cout << "Input: " << p1 << " * " << p2 << "\n";
    cout << "Output: " << r1 << "\n";
    cout << "Expected: x^2-1\n\n";
    
    big_P p3("x^2+2x+1");
    big_P p4("x+1");
    big_P r2 = MUL_PP_P(p3, p4);
    cout << "Input: " << p3 << " * " << p4 << "\n";
    cout << "Output: " << r2 << "\n";
    cout << "Expected: x^3+3x^2+3x+1\n\n";
}

void test_div() {
    cout << "========== DIV_PP_P ==========\n";
    
    big_P p1("x^3-1");
    big_P p2("x-1");
    big_P r1 = DIV_PP_P(p1, p2);
    cout << "Input: " << p1 << " / " << p2 << "\n";
    cout << "Output: " << r1 << "\n";
    cout << "Expected: x^2+x+1\n\n";
    
    big_P p3("x^2+2x+1");
    big_P p4("x+1");
    big_P r2 = DIV_PP_P(p3, p4);
    cout << "Input: " << p3 << " / " << p4 << "\n";
    cout << "Output: " << r2 << "\n";
    cout << "Expected: x+1\n\n";
}

void test_mod() {
    cout << "========== MOD_PP_P ==========\n";
    
    big_P p1("x^3-1");
    big_P p2("x-1");
    big_P r1 = MOD_PP_P(p1, p2);
    cout << "Input: " << p1 << " % " << p2 << "\n";
    cout << "Output: " << r1 << "\n";
    cout << "Expected: 0\n\n";
    
    big_P p3("x^3+2x^2+2x+1");
    big_P p4("x+1");
    big_P r2 = MOD_PP_P(p3, p4);
    cout << "Input: " << p3 << " % " << p4 << "\n";
    cout << "Output: " << r2 << "\n";
    cout << "Expected: 0\n\n";
}

void test_gcf() {
    cout << "========== GCF_PP_P ==========\n";
    
    big_P p1("x^2-1");
    big_P p2("x^2-2x+1");
    big_P r1 = GCF_PP_P(p1, p2);
    cout << "Input: GCF(" << p1 << ", " << p2 << ")\n";
    cout << "Output: " << r1 << "\n";
    cout << "Expected: x-1\n\n";
}

void test_der() {
    cout << "========== DER_P_P ==========\n";
    
    big_P p1("x^3+3x^2+3x+1");
    big_P r1 = DER_P_P(p1);
    cout << "Input: " << p1 << "\n";
    cout << "Output: " << r1 << "\n";
    cout << "Expected: 3x^2+6x+3\n\n";
    
    big_P p2("5x^4-3x^2+2");
    big_P r2 = DER_P_P(p2);
    cout << "Input: " << p2 << "\n";
    cout << "Output: " << r2 << "\n";
    cout << "Expected: 20x^3-6x\n\n";
    
    big_P p3("7");
    big_P r3 = DER_P_P(p3);
    cout << "Input: " << p3 << "\n";
    cout << "Output: " << r3 << "\n";
    cout << "Expected: 0\n\n";
}

void test_nmr() {
    cout << "========== NMR_P_P ==========\n";
    
    big_P p1("x^4-2x^2+1");
    cout << "lelel" << endl;
    big_P r1 = NMR_P_P(p1);
    cout << "Input: " << p1 << "\n";
    cout << "Output: " << r1 << "\n";
    cout << "Expected: x^2-1\n\n";
}

int main() {
    ALWAYS_PRINT_DENOMINATOR = 0;
    cout << "========== POLYNOMIAL TESTS ==========\n";
    
    test_mul_pxk();
    test_led();
    test_deg();
    test_fac();
    test_mul_pp();
    test_div();
    test_mod();
    test_der();
    test_gcf();
    test_nmr();
    
    cout << "========== ALL TESTS COMPLETED ==========\n";
    return 0;
}