#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define BASE 10

unsigned long euclide_alg(const unsigned long a, const unsigned long b) {
    unsigned long A = a, B = b, R = 0;
    auto int round = 0;
    while (B) {
        printf("%4d\tA: %15ld B: %15ld R: %15ld\n", round++, A, B, R);
        R = A % B;
        A = B;
        B = R;
    }
    return A;
}

void euclide(const unsigned long a, const unsigned long b) {
    unsigned long e;
    e = euclide_alg(a,b);
    printf("Result:\t%ld\n", e);
}

int main(int argc, char** argv) {
    char *endptr;
    /** Algorith arguments */
    unsigned long int a = 0, b = 0;

	if (argc != 3) {
        fprintf(stderr, "Wrong number of arguments.\n");
        fprintf(stderr, "Usage: %s <long unsigned int> <long unsigned int>\n", argv[0]);
        return 1;
	}
    if (argv[1][0] == '-' || argv[2][0] == '-') {
        printf("Error: Argument should not be negative.\n");
        return 1;
    }
    a = strtoul(argv[1], &endptr, BASE);
    /* Check for conversion errors */
    if (*endptr != '\0' || a > ULONG_MAX) {
        printf("Error: Argument 1 is not a valid long unsigned integer.\n");
        return 1;
    }
    b = strtoul(argv[2], &endptr, BASE);
    /* Check for conversion errors */
    if (*endptr != '\0' || b > ULONG_MAX) {
        printf("Error: Argument 2 is not a valid long unsigned integer.\n"); 
        return 1;
    }
    
    euclide(a,b);

	return 0;
}
