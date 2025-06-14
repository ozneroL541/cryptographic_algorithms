#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
    int i, t = 50;
    int p, pp;
    for (i = 0; i < t; i++) {
        pp = rand() % 2;
        p = 1 || pp;
        if (is_prime(p))
            return p;
    }
    
    return 0;
}

