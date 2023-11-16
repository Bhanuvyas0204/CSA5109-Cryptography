#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void encryptECB(const char *plaintext, char *key, char *ciphertext) {
    strcpy(ciphertext, plaintext);
}
void decryptECB(const char *ciphertext, char *key, char *plaintext) {
    strcpy(plaintext, ciphertext);
}
void encryptCBC(const char *plaintext, char *key, char *iv, char *ciphertext) {
    int i;
    int blockCount = strlen(plaintext) / 8; 
    char previousBlock[9];
    strcpy(previousBlock, iv);

    for (i = 0; i < blockCount; i++) {
        for (int j = 0; j < 8; j++) {
            ciphertext[i * 8 + j] = plaintext[i * 8 + j] ^ previousBlock[j];
        }
        encryptECB(ciphertext + i * 8, key, ciphertext + i * 8);
        strcpy(previousBlock, ciphertext + i * 8);
    }
}
void decryptCBC(const char *ciphertext, char *key, char *iv, char *plaintext) {
    int i;
    int blockCount = strlen(ciphertext) / 8;  // Assuming 8-byte blocks
    char previousBlock[9];
    strcpy(previousBlock, iv);

    for (i = 0; i < blockCount; i++) {
        decryptECB(ciphertext + i * 8, key, plaintext + i * 8);
        for (int j = 0; j < 8; j++) {
            plaintext[i * 8 + j] = plaintext[i * 8 + j] ^ previousBlock[j];
        }
        strcpy(previousBlock, ciphertext + i * 8);
    }
}
int main() {
    char key[] = "mysecret";  
    char iv[] = "initvec";   
    const char *originalPlaintext = "Hello123ThisIsSomeText";
    char encryptedECB[256];
    char decryptedECB[256];
    char encryptedCBC[256];
    char decryptedCBC[256];
    encryptECB(originalPlaintext, key, encryptedECB);
    decryptECB(encryptedECB, key, decryptedECB);
    encryptCBC(originalPlaintext, key, iv, encryptedCBC);
    encryptedCBC[0] ^= 0x01;
    decryptCBC(encryptedCBC, key, iv, decryptedCBC);
    printf("Original Plaintext: %s\n", originalPlaintext);
    printf("Encrypted ECB: %s\n", encryptedECB);
    printf("Decrypted ECB: %s\n\n", decryptedECB);
    printf("Encrypted CBC: %s\n", encryptedCBC);
    printf("Decrypted CBC: %s\n", decryptedCBC);

    return 0;
}
