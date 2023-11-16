#include <stdio.h>
int extended_gcd(int a, int b, int *x, int *y) {
    if (a == 0) {
        *x = 0;
        *y = 1;
        return b;
    }
    int x1, y1;
    int gcd = extended_gcd(b % a, a, &x1, &y1);
    *x = y1 - (b / a) * x1;
    *y = x1;
    return gcd;
}
int mod_inverse(int a, int m) {
    int x, y;
    extended_gcd(a, m, &x, &y);
    x = (x % m + m) % m;
    return x;
}
int main() {
    int plaintext[2] = {3, 2};
    int ciphertext[2] = {12, 9}; 
    int determinant = (plaintext[0] * plaintext[3] - plaintext[1] * plaintext[2]);
    int determinant_inverse = mod_inverse(determinant, 26);
    int inverse[4];
    inverse[0] = (determinant_inverse * plaintext[3]) % 26;
    inverse[1] = (-determinant_inverse * plaintext[1]) % 26;
    inverse[2] = (-determinant_inverse * plaintext[2]) % 26;
    inverse[3] = (determinant_inverse * plaintext[0]) % 26;
    int key[4];
    key[0] = (inverse[0] * ciphertext[0] + inverse[1] * ciphertext[1]) % 26;
    key[1] = (inverse[2] * ciphertext[0] + inverse[3] * ciphertext[1]) % 26;
    printf("The recovered key matrix is:\n");
    printf("%d %d\n%d %d\n", key[0], key[1], key[2], key[3]);

    return 0;
}
