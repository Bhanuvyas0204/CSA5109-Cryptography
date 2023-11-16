#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int encryptChar(int plaintext, int e, int n) {
    int ciphertext = 1;
    for (int i = 0; i < e; i++) {
        ciphertext = (ciphertext * plaintext) % n;
    }
    return ciphertext;
}
int main() {
    srand(time(NULL));
    int e = 65537;
    int n = 104729;
    for (char letter = 'A'; letter <= 'Z'; letter++) {
        int plaintext = letter - 'A';
        int ciphertext = encryptChar(plaintext, e, n);
        printf("Original: %c, Encrypted: %d\n", letter, ciphertext);
    }
    return 0;
	}
