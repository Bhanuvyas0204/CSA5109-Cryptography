#include <stdio.h>

void generateSubkeys(unsigned long long cipher_key) {
    unsigned long long C = cipher_key >> 28;  
    unsigned long long D = cipher_key & 0x0FFFFFFF;  
    unsigned long long subkey;

    printf("Round 1: First 24 bits of Subkey = ");
    subkey = (C >> 4) & 0x0FFFFFFF;
    printf("0x%06llx\n", subkey);
    subkey = (D >> 4) & 0x0FFFFFFF;
    printf("Round 1: Second 24 bits of Subkey = 0x%06llx\n", subkey);

    for (int round = 2; round <= 16; round++) {
        C = ((C << 1) | (C >> 27)) & 0x0FFFFFFF;
        D = ((D << 1) | (D >> 27)) & 0x0FFFFFFF;

        printf("Round %2d: First 24 bits of Subkey = ", round);
        subkey = (C >> 4) & 0x0FFFFFFF;
        printf("0x%06llx\n", subkey);
        subkey = (D >> 4) & 0x0FFFFFFF;
        printf("Round %2d: Second 24 bits of Subkey = 0x%06llx\n", round, subkey);
    }
}

int main() {
    unsigned long long cipher_key = 0x0123456789ABCDEF;
    generateSubkeys(cipher_key);

    return 0;
}
