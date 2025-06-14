#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>
#include "exponentiation.h"

#define BASE 10

void mod_exp(const unsigned long a, const unsigned long b, const unsigned long m) {
    unsigned long e;
    e = modular_exponential(a,b,m);
    printf("Result:\t%ld\n", e);
}

int main(int argc, char** argv) {
    char *endptr;
    /** Algorith arguments */
    unsigned long int a = 0, b = 0, m = 0;

	if (argc != 4) {
        fprintf(stderr, "Wrong arguments count.\nUsage: modular_exponential <base> <exponent> <modulus>\n");
        return 1;
	}
    if (argv[1][0] == '-' || argv[2][0] == '-' || argv[3][0] == '-') {
        fprintf(stderr, "Error: Argument should not be negative.\n");
        return 1;
    }
    /* Reset errno before conversion  */
    errno = 0;
    a = strtoul(argv[1], &endptr, BASE);
    /* Check for conversion errors */
    if (errno != 0 || *endptr != '\0' || a > ULONG_MAX) {
        fprintf(stderr, "Error: Argument 1 is not a valid long unsigned integer.\n");
        return 1;
    }
    errno = 0;
    b = strtoul(argv[2], &endptr, BASE);
    /* Check for conversion errors */
    if (errno != 0 || *endptr != '\0' || b > ULONG_MAX) {
        fprintf(stderr, "Error: Argument 2 is not a valid long unsigned integer.\n"); 
        return 1;
    }
    errno = 0;
    m = strtoul(argv[3], &endptr, BASE);
    /* Check for conversion errors */
    if (errno != 0 || *endptr != '\0' || m > ULONG_MAX) {
        fprintf(stderr, "Error: Argument 2 is not a valid long unsigned integer.\n"); 
        return 1;
    }
    
    mod_exp(a,b,m);

	return 0;
}
