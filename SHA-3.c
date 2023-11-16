#include <stdio.h>
#include <string.h>
#include "tiny_sha3/sha3.h"

int main() {
    uint64_t message_block[16];
    memset(message_block, 0, sizeof(message_block));
    message_block[0] = 0x8000000000000001ULL;
    keccak_state state;
    memset(state.s, 0, sizeof(state.s));
    keccak_absorb(&state, message_block, SHA3_1024);
    printf("Internal State After Absorption:\n");
    for (int i = 0; i < 25; ++i) {
        printf("%016llx ", state.s[i]);
        if ((i + 1) % 5 == 0) printf("\n");
    }
    return 0;
}
