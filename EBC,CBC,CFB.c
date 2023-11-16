#include <stdio.h>
#include <string.h>

void addPadding(char *plaintext, int block_size) {
    int padding_size = block_size - (strlen(plaintext) % block_size);
    strcat(plaintext, "\x80");
    for (int i = 0; i < padding_size - 1; i++) {
        strcat(plaintext, "\x00");
    }
}
void encryptECB(char *plaintext, int block_size) {
    printf("ECB Encryption: %s\n", plaintext);
}
void encryptCBC(char *plaintext, int block_size, char *iv) {
    printf("CBC Encryption: %s\n", plaintext);
}
void encryptCFB(char *plaintext, int block_size, char *iv) {
    printf("CFB Encryption: %s\n", plaintext);
}

int main() {
    char plaintext[] = "This is a test message.";
    int block_size = 8; 
    char iv[] = "initvec"; 
    addPadding(plaintext, block_size);
    encryptECB(plaintext, block_size);
    encryptCBC(plaintext, block_size, iv);
    encryptCFB(plaintext, block_size, iv);

    return 0;
}
