#include <stdio.h>
#include <stdint.h>

uint8_t sdes_key[10] = {0, 1, 1, 1, 1, 1, 1, 1, 1, 0};
uint8_t p10[] = {2, 4, 1, 6, 3, 9, 0, 8, 7, 5};
uint8_t p8[] = {5, 2, 6, 3, 7, 4, 9, 8};
uint8_t ip[] = {1, 5, 2, 0, 3, 7, 4, 6};
uint8_t ep[] = {3, 0, 1, 2, 1, 2, 3, 0};
uint8_t p4[] = {1, 3, 2, 0};
uint8_t s0[4][4] = {{1, 0, 3, 2}, {3, 2, 1, 0}, {0, 2, 1, 3}, {3, 1, 3, 2}};
uint8_t s1[4][4] = {{0, 1, 2, 3}, {2, 0, 1, 3}, {3, 0, 1, 0}, {2, 1, 0, 3}};
uint8_t ip_inverse[] = {3, 0, 2, 4, 6, 1, 7, 5};
void xor8(uint8_t *a, uint8_t *b, uint8_t *result) {
    for (int i = 0; i < 8; i++) {
        result[i] = a[i] ^ b[i];
    }
}
void circularLeftShift(uint8_t *key, int shift) {
    int i;
    uint8_t temp[10];

    for (i = 0; i < 10; i++) {
        temp[i] = key[(i + shift) % 10];
    }

    for (i = 0; i < 10; i++) {
        key[i] = temp[i];
    }
}
void generateRoundKeys(uint8_t *key, uint8_t *k1, uint8_t *k2) {
    uint8_t temp_key[10];
    for (int i = 0; i < 10; i++) {
        temp_key[i] = key[p10[i]];
    }
    circularLeftShift(temp_key, 1);
    for (int i = 0; i < 8; i++) {
        k1[i] = temp_key[p8[i]];
    }
    circularLeftShift(temp_key, 2);
    for (int i = 0; i < 8; i++) {
        k2[i] = temp_key[p8[i]];
    }
}
void initialPermutation(uint8_t *plaintext, uint8_t *ip_result) {
    for (int i = 0; i < 8; i++) {
        ip_result[i] = plaintext[ip[i]];
    }
}
void inverseInitialPermutation(uint8_t *ciphertext, uint8_t *ip_inverse_result) {
    for (int i = 0; i < 8; i++) {
        ip_inverse_result[i] = ciphertext[ip_inverse[i]];
    }
}
void expansionPermutation(uint8_t *right_half, uint8_t *ep_result) {
    for (int i = 0; i < 8; i++) {
        ep_result[i] = right_half[ep[i]];
    }
}
void permutationP4(uint8_t *input, uint8_t *output) {
    for (int i = 0; i < 4; i++) {
        output[i] = input[p4[i]];
    }
}
void sBoxSubstitution(uint8_t *input, uint8_t *output, uint8_t sBox[4][4]) {
    int row = (input[0] << 1) + input[3];
    int col = (input[1] << 1) + input[2];
    uint8_t value = sBox[row][col];

    for (int i = 0; i < 2; i++) {
        output[i] = (value >> (1 - i)) & 0x01;
    }
}
void sDesF(uint8_t *right_half, uint8_t *key, uint8_t *result) {
    uint8_t expanded_right[8];
    uint8_t xor_result[8];
    uint8_t sbox_result[4];
    expansionPermutation(right_half, expanded_right);
    xor8(expanded_right, key, xor_result);
    sBoxSubstitution(xor_result, sbox_result, s0);
    sBoxSubstitution(xor_result + 4, sbox_result + 2, s1);
    permutationP4(sbox_result, result);
}
void sDesRound(uint8_t *left_half, uint8_t *right_half, uint8_t *key) {
    uint8_t f_result[4];
    uint8_t original_right[4];
    for (int i = 0; i < 4; i++) {
        original_right[i] = right_half[i];
    }
    sDesF(right_half, key, f_result);
    for (int i = 0; i < 4; i++) {
        right_half[i] = left_half[i] ^ f_result[i];
    }
    for (int i = 0; i < 4; i++) {
        left_half[i] = original_right[i];
    }
}
void sDesEncrypt(uint8_t *plaintext, uint8_t *key, uint8_t *ciphertext) {
    uint8_t initial_permutation_result[8];
    uint8_t left_half[4];
    uint8_t right_half[4];
    uint8_t k1[8];
    uint8_t k2[8];
    initialPermutation(plaintext, initial_permutation_result);
    for (int i = 0; i < 4; i++) {
        left_half[i] = initial_permutation_result[i];
        right_half[i] = initial_permutation_result[i + 4];
    }
    generateRoundKeys(key, k1, k2);
    sDesRound(left_half, right_half, k1);
    sDesRound(left_half, right_half, k2);
    for (int i = 0; i < 4; i++) {
        ciphertext[i] = left_half[i];
        ciphertext[i + 4] = right_half[i];
    }
    inverseInitialPermutation(ciphertext, ciphertext);
}
void printBinary(uint8_t *array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d", array[i]);
    }
    printf("\n");
}
int main() {
    uint8_t plaintext[] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 1, 0};
    uint8_t key[] = {0, 1, 1, 1, 1, 1, 1, 0, 1, 0}; // Binary key of 011111101
    uint8_t ciphertext[8];
    printf("Original Plaintext: ");
    printBinary(plaintext, 16);
    printf("Key: ");
    printBinary(key, 10);
    sDesEncrypt(plaintext, key, ciphertext);
    printf("Ciphertext: ");
    printBinary(ciphertext, 16);

    return 0;
}
