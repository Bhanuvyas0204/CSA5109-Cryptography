#include <stdio.h>
#include <string.h>
#include <ctype.h>

void encryptVigenere(char plaintext[], int key[], int keyLength) {
    int len = strlen(plaintext);
    int i;
    for (i = 0; i < len; i++) {
        if (isalpha(plaintext[i])) {
            char base = islower(plaintext[i]) ? 'a' : 'A';
            plaintext[i] = (char)(((toupper(plaintext[i]) - 'A' + key[i % keyLength]) % 26) + base);
        }
    }
}

void decryptVigenere(char ciphertext[], int key[], int keyLength) {
    int len = strlen(ciphertext);
    int i;
    for (i = 0; i < len; i++) {
        if (isalpha(ciphertext[i])) {
            char base = islower(ciphertext[i]) ? 'a' : 'A';
            ciphertext[i] = (char)(((toupper(ciphertext[i]) - 'A' - key[i % keyLength] + 26) % 26) + base);
        }
    }
}

int main() {
    char plaintext[] = "SENDMOREMONEY";
    int key[] = {9, 0, 1, 7, 23, 15, 21, 14, 11, 11, 2, 8, 9};
    int keyLength = sizeof(key) / sizeof(key[0]);

    encryptVigenere(plaintext, key, keyLength);

    printf("Encrypted ciphertext: %s\n", plaintext);

    decryptVigenere(plaintext, key, keyLength);

    printf("Decrypted plaintext: %s\n", plaintext);

    return 0;
}
