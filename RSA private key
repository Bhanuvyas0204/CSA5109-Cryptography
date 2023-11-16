#include <stdio.h>

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}
int main() {
    int n = 143;
    int e = 17;
    int knownPlaintextBlock = 42;
    int commonFactor = gcd(knownPlaintextBlock, n);
    if (commonFactor > 1 && commonFactor < n) {
        int p = commonFactor;
        int q = n / commonFactor;

        printf("Factorization successful:\n");
        printf("p = %d\n", p);
        printf("q = %d\n", q);
    } else {
        printf("Factorization failed. No non-trivial common factor found.\n");
    }

    return 0;
}
