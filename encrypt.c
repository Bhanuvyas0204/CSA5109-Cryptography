#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int modInverse(int a, int m) {
    int x;
	for (x = 1; x < m; x++) {
        if ((a * x) % m == 1) {
            return x;
        }
    }
    return -1;
}
void encrypt(int key[2][2], char *message, int len) {
    int i, j;
    int ciphertext[len];

    for (i = 0; i < len; i += 2) {
        int pair[2] = {message[i] - 'a', message[i + 1] - 'a'};
        int result[2] = {0, 0};

        for (j = 0; j < 2; j++) {
            result[j] = (key[j][0] * pair[0] + key[j][1] * pair[1]) % 26;
        }

        ciphertext[i] = result[0];
        ciphertext[i + 1] = result[1];
    }

    printf("Encrypted message: ");
    for (i = 0; i < len; i++) {
        printf("%c", ciphertext[i] + 'a');
    }
    printf("\n");
}

void decrypt(int key[2][2], char *ciphertext, int len) {
    int i, j;
    int message[len];
    int det = (key[0][0] * key[1][1] - key[0][1] * key[1][0] + 26) % 26;
    int inverse = modInverse(det, 26);

    if (inverse == -1) {
        printf("Decryption is not possible. The determinant is not relatively prime to 26.\n");
        return;
    }

    int adj[2][2] = {
        {key[1][1], -key[0][1]},
        {-key[1][0], key[0][0]}};
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            adj[i][j] = (adj[i][j] + 26) % 26;
        }
    }

    for (i = 0; i < len; i += 2) {
        int pair[2] = {ciphertext[i] - 'a', ciphertext[i + 1] - 'a'};
        int result[2] = {0, 0};

        for (j = 0; j < 2; j++) {
            result[j] = (adj[j][0] * pair[0] + adj[j][1] * pair[1]) % 26;
        }

        message[i] = result[0];
        message[i + 1] = result[1];
    }

    printf("Decrypted message: ");
    for (i = 0; i < len; i++) {
        printf("%c", message[i] + 'a');
    }
    printf("\n");
}

int main() {
    char message[] = "meetmeattheusualplaceattenratherthaneightoclock";
    int key[2][2] = {{9, 4}, {5, 7}};
    int len = strlen(message);

    printf("Original message: %s\n", message);

    encrypt(key, message, len);
    decrypt(key, message, len);

    return 0;
}
