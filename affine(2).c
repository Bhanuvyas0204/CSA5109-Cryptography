#include <stdio.h>

int modInverse(int a, int m) {
}

char encrypt(char p, int a, int b) {
}

int main() {
    int a, b;
    char plaintext[100];
    char choice;

    do {
        printf("Enter the value of 'a' (must be coprime with 26): ");
        scanf("%d", &a);

        if (a % 2 == 0 || a % 13 == 0) {
            printf("Error: 'a' must be coprime with 26.\n");
            return 1;
        }

        printf("Enter the value of 'b': ");
        scanf("%d", &b);

        printf("Enter the plaintext: ");
        scanf(" %[^\n]s", plaintext);

        int aInverse = modInverse(a, 26);

        for (int i = 0; plaintext[i] != '\0'; i++) {
            char encryptedChar = encrypt(plaintext[i], a, b);
            printf("%c", encryptedChar);
        }

        printf("\n");

        printf("Do you want to encrypt another message? (y/n): ");
        scanf(" %c", &choice);

    } while (choice == 'y' || choice == 'Y');
    return 0;
}
