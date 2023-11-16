#include <stdio.h>

int main() {
    unsigned long long cipher_key = 0x0123456789ABCDEF;
    unsigned long long C0 = cipher_key >> 28;
    unsigned long long D0 = cipher_key & 0x0FFFFFFF;
    for (int round = 16; round >= 1; round--) {
        int shift_positions = (round == 1 || round == 2 || round == 9 || round == 16) ? 1 : 2;
        C0 = (C0 >> shift_positions) | (C0 << (28 - shift_positions));
        D0 = (D0 >> shift_positions) | (D0 << (28 - shift_positions));
        unsigned long long subkey = (C0 << 28) | D0;
        printf("Round %2d Subkey: 0x%012llx\n", round, subkey);
    }
    return 0;
}
