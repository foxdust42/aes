#ifndef AES_H
#define AES_H
#include <stdint.h>

// Circular left-shift for 8 bits
#define ROTL8(x, shift) ((uint8_t) ((x) << (shift)) | ((x) >> (8 - (shift))))

typedef struct RoundKeys
{
    int a;
} Rk;

//const uint8_t sbox[256];
//const uint8_t invsbox[256];

char * Cipher(const uint8_t in[16], int Nr, Rk *rKeys);

void SubBytes(uint8_t state[16], uint8_t sbox[256]);
void InvSubBytes(uint8_t state[16], uint8_t invsbox[256]);

void ShiftRows(uint8_t state[16]);

void MixColumns(uint8_t state[16]);

void initSBox(uint8_t sbox[256], uint8_t invsbox[256]);
#endif