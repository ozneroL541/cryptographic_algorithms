#include "exponentiation.h"

unsigned long modular_exponential(const unsigned long base, const unsigned long exponent, const unsigned long modulus) {
    /** Base */
    auto unsigned long x = base % modulus, 
        /** Exponent */
        e = exponent, 
        /** Result */
        n = 1;
    #ifdef DEBUG
        auto unsigned short rounds = 0;
    #endif
    while (e >= 1) {
        if ( e % 2 ){
            e--;
            n *= x;
            n %= modulus;
        } else {
            e /= 2;
            x *= x;
            x %= modulus;
            #ifdef DEBUG
                printf("Round: %hi, x = %lu, n = %lu\n", ++rounds, x, n);
            #endif
        }        
    }
    return n;
}
