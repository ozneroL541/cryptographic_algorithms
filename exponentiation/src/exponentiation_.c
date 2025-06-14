#include "exponentiation.h"

unsigned long modular_exponential(const unsigned long base, const unsigned long exponent, const unsigned long modulus){
    /** Result of the exponentiation */
    auto unsigned long r = 1;
    /** Base of the exponentiation */
    auto unsigned long b = base % modulus;
    /** Number of bits of the exponent */
    const unsigned char m = sizeof(unsigned long) * 8 - __builtin_clzl(exponent);
    /** Index of the current bit */
    auto unsigned char i = m - 1;
    /** Check if number has started */
    auto unsigned char started = 0;
    /** Exponent BIT index */
    #ifdef DEBUG
        auto unsigned short rounds = 0;
    #endif
    for (i = 0; i < m; i++) {
        if (exponent & (1UL << i)) {
            started = 1;
            r *= b;
            r %= modulus;
        } 
        if (started) {
            b *= b;
            b %= modulus;
        #ifdef DEBUG
            printf("Round %hi: exponent & (1UL << i): %lu\ty = %lu\n", ++rounds,  (exponent & (1UL << i)), r);
        #endif
        }
    }
    return r;
}
