#include <stdio.h>
#define CONSTANT_64 0x1B

unsigned char leftShift(unsigned char value) {
    return (value << 1) | ((value & 0x80) ? 1 : 0);
}
void generateCMACSubkeys(unsigned char key[], unsigned char k1[], unsigned char k2[]) {
    unsigned char L[16];
    unsigned char K[16];
    for (int i = 0; i < 16; i++) {
        L[i] = 0;
        K[i] = key[i];
    }
    if ((K[0] & 0x80) == 0) {
        leftShift(K[0]);
    } else {
        leftShift(K[0]);
        K[15] ^= CONSTANT_64;
    }
    for (int i = 0; i < 16; i++) {
        k1[i] = K[i];
    }
    if ((k1[0] & 0x80) == 0) {
        leftShift(k1[0]);
    } else {
        leftShift(k1[0]);
        k1[15] ^= CONSTANT_64;
    }
    for (int i = 0; i < 16; i++) {
        k2[i] = k1[i];
    }
}
int main() {
    unsigned char key[16] = {0};  // Example key (all zeros)
    unsigned char k1[16], k2[16];
    generateCMACSubkeys(key, k1, k2);
    printf("K1: ");
    for (int i = 0; i < 16; i++) {
        printf("%02X", k1[i]);
    }
    printf("\n");

    printf("K2: ");
    for (int i = 0; i < 16; i++) {
        printf("%02X", k2[i]);
    }
    printf("\n");

    return 0;
}
