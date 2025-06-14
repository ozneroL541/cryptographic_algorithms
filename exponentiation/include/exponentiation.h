#ifndef __EXPONENTIATION_H__
    #define __EXPONENTIATION_H__
    #undef DEBUG
    #ifdef DEBUG
        #include <stdio.h>
    #endif
    /**
    * Efficient way to calculate modular exponentiation.
    * This function computes (base^exponent) % modulus using the method of exponentiation by squaring.
    * It is efficient for large numbers and avoids overflow by taking modulus at each step.
    * @param base The base of the exponentiation.
    * @param exponent The exponent to which the base is raised.
    * @param modulus The modulus to which the result is taken.
    * @return The result of (base^exponent) % modulus.
    * @note This function assumes that base, exponent, and modulus are non-negative integers.
    */
    unsigned long modular_exponential(const unsigned long base, const unsigned long exponent, const unsigned long modulus);

#endif
