include <stdio.h>
#include <math.h>

unsigned long long factorial(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

int main() {
    int n = 25; 
    unsigned long long total_keys = factorial(n);

    printf("Total number of keys: %llu\n", total_keys);
    int power_of_2 = (int)(log2(total_keys));
    printf("Approximately 2^%d keys\n", power_of_2);

    return 0;
}
