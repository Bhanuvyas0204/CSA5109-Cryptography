#include <stdio.h>
#include <string.h>

void encrypt(char* plaintext, char* key) {
    int i, j;
    int keyLen = strlen(key);
    int textLen = strlen(plaintext);

    for (i = 0; i < textLen; i++) {
        if (plaintext[i] >= 'A' && plaintext[i] <= 'Z') {
            char shift = key[i % keyLen] - 'A';
            char encryptedChar = ((plaintext[i] - 'A' + shift) % 26) + 'A';
            printf("%c", encryptedChar);
        } else if (plaintext[i] >= 'a' && plaintext[i] <= 'z') {
            char shift = key[i % keyLen] - 'A';
            char encryptedChar = ((plaintext[i] - 'a' + shift) % 26) + 'a';
            printf("%c", encryptedChar);
        } else {
            printf("%c", plaintext[i]); 
        }
    }
    printf("\n");
}

int main() {
    char plaintext[100], key[100];

    printf("Enter the plaintext: ");
    scanf("%[^\n]s", plaintext);

    printf("Enter the key: ");
    scanf("%s", key);

    encrypt(plaintext, key);

    return 0;
}
