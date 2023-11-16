#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/dsa.h>
#include <openssl/rsa.h>
#include <openssl/sha.h>

void generateDSASignature() {
    DSA *dsa = DSA_new();
    if (dsa == NULL) {
        fprintf(stderr, "Error creating DSA key\n");
        exit(EXIT_FAILURE);
    }
    if (!DSA_generate_parameters_ex(dsa, 2048, NULL, 0, NULL, NULL, NULL)) {
        fprintf(stderr, "Error generating DSA parameters\n");
        exit(EXIT_FAILURE);
    }
    if (!DSA_generate_key(dsa)) {
        fprintf(stderr, "Error generating DSA key pair\n");
        exit(EXIT_FAILURE);
    }
    const char *message = "Hello, DSA!";
    unsigned char hash[SHA_DIGEST_LENGTH];
    SHA1((const unsigned char *)message, strlen(message), hash);

    DSA_SIG *signature = DSA_do_sign(hash, SHA_DIGEST_LENGTH, dsa);
    if (signature == NULL) {
        fprintf(stderr, "Error generating DSA signature\n");
        exit(EXIT_FAILURE);
    }
    if (DSA_do_verify(hash, SHA_DIGEST_LENGTH, signature, dsa) == 1) {
        printf("DSA Signature verification successful\n");
    } else {
        printf("DSA Signature verification failed\n");
    }
    DSA_free(dsa);
    DSA_SIG_free(signature);
}
void generateRSASignature() {
    RSA *rsa = RSA_generate_key(2048, RSA_F4, NULL, NULL);
    if (rsa == NULL) {
        fprintf(stderr, "Error generating RSA key pair\n");
        exit(EXIT_FAILURE);
    }
    const char *message = "Hello, RSA!";
    unsigned char hash[SHA_DIGEST_LENGTH];
    SHA1((const unsigned char *)message, strlen(message), hash);
    unsigned char signature[4096];
    unsigned int signatureLength;
    if (RSA_sign(NID_sha1, hash, SHA_DIGEST_LENGTH, signature, &signatureLength, rsa) == 1) {
        printf("RSA Signature generation successful\n");
    } else {
        fprintf(stderr, "Error generating RSA signature\n");
        exit(EXIT_FAILURE);
    }
    if (RSA_verify(NID_sha1, hash, SHA_DIGEST_LENGTH, signature, signatureLength, rsa) == 1) {
        printf("RSA Signature verification successful\n");
    } else {
        printf("RSA Signature verification failed\n");
    }
    RSA_free(rsa);
}
int main() {
    printf("Demonstrating DSA Signature:\n");
    generateDSASignature();
    printf("\nDemonstrating RSA Signature:\n");
    generateRSASignature();

    return 0;
}
