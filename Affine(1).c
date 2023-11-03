#include <stdio.h>

int modInverse(int a, int m) {
    int m0 = m, t, q;
    int x0 = 0, x1 = 1;

    if (m == 1) return 0;

    while (a > 1) {
        q = a / m;
        t = m;
        m = a % m;
        a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }

    if (x1 < 0) x1 += m0;

    return x1;
}

int main() {
    char mostFrequent = 'B'; 
    char secondMostFrequent = 'U'; 
    int a, b;
    a = (mostFrequent - 'A' - secondMostFrequent + 'A') % 26;
    if (a < 0) {
        a += 26;
    }
    b = (mostFrequent - 'A' - a * (secondMostFrequent - 'A')) % 26;
    if (b < 0) {
        b += 26;
    }

    printf("Possible values: a = %d, b = %d\n", a, b);
    return 0;
}
