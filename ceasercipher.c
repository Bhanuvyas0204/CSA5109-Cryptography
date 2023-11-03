#include <stdio.h>
#include <ctype.h>
#include <string.h>

char decryptChar(char ch, int key) {
    if (isalpha(ch)) {
        char base = isupper(ch) ? 'A' : 'a';
        return (((ch - base) - key + 26) % 26) + base;
    }
    return ch;
}

void decryptString(char* str, int key) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = decryptChar(str[i], key);
    }
}

int main() {
    char ciphertext[1000];
    int key;

    printf("Enter the ciphertext: ");
    gets(ciphertext); 

    printf("Enter the key: ");
    scanf("%d", &key);

    decryptString(ciphertext, key);

    printf("Decrypted plaintext: %s\n", ciphertext);
	return 0;
}
