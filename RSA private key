#include <stdio.h>
#include <string.h>
#include <ctype.h>

void findCharPosition(char matrix[5][5], char ch, int *row, int *col) {
    if (ch == 'J') ch = 'I';
    int i;
    int j;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            if (matrix[i][j] == ch) {
                *row = i;
                *col = j;
                return;
            }
        }
    }
}

void encryptPlayfair(char message[], char matrix[5][5]) {
    int len = strlen(message);
    int i = 0;
    char ciphertext[len * 2];

    while (i < len) {
        if (!isalpha(message[i])) {
            ciphertext[i * 2] = message[i];
            i++;
            continue;
        }

        char first = message[i++];
        char second = (i < len && isalpha(message[i])) ? message[i++] : 'X';

        if (first == 'J') first = 'I';
        if (second == 'J') second = 'I';

        int row1, col1, row2, col2;
        findCharPosition(matrix, first, &row1, &col1);
        findCharPosition(matrix, second, &row2, &col2);

        if (row1 == row2) {
            ciphertext[(i - 2) * 2] = matrix[row1][(col1 + 1) % 5];
            ciphertext[(i - 2) * 2 + 1] = matrix[row2][(col2 + 1) % 5];
        } else if (col1 == col2) {
            ciphertext[(i - 2) * 2] = matrix[(row1 + 1) % 5][col1];
            ciphertext[(i - 2) * 2 + 1] = matrix[(row2 + 1) % 5][col2];
        } else {
            ciphertext[(i - 2) * 2] = matrix[row1][col2];
            ciphertext[(i - 2) * 2 + 1] = matrix[row2][col1];
        }
    }

    ciphertext[len * 2] = '\0';
    strcpy(message, ciphertext);
}

int main() {
    char message[] = "Must see you over Cadogan West. Coming at once.";
    char matrix[5][5] = {
        {'M', 'F', 'H', 'I', 'K'},
        {'U', 'N', 'O', 'P', 'Q'},
        {'Z', 'V', 'W', 'X', 'Y'},
        {'E', 'L', 'A', 'R', 'G'},
        {'D', 'S', 'T', 'B', 'C'}
    };

    encryptPlayfair(message, matrix);
    printf("Encrypted message: %s\n", message);

    return 0;
}
