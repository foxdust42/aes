#include "aes.h"
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

char * Cipher(const uint8_t in[16], int Nr, Rk *rKeys){
    char state[16];
    memcpy(state, in, 16);   
    return NULL; 
}

void SubBytes(uint8_t state[16], uint8_t sbox[256]){
    int i = 0;
    while (i < 16){
        state[i] = sbox[state[i]];
        i++;
    }
}

void InvSubBytes(uint8_t state[16], uint8_t invsbox[256]){
    int i=0;
    while (i < 16)
    {
        state[i] = invsbox[state[i]];
        i++;
    }
    
}

void initSBox(uint8_t sbox[256], uint8_t invsbox[256]){
    uint8_t p = 1, q = 1;
    uint8_t val;
    do
    {
        p = p ^ (p << 1) ^ (p & 0x80 ? 0x1B : 0x00);

        q ^= q << 1;
        q ^= q << 2;
        q ^= q << 4;
        q ^= q & 0x80 ? 0x09 : 0x00;

        //Exactly equivalent to the affine transformation
        val = q ^ (ROTL8(q, 1)) ^ (ROTL8(q,2)) ^ (ROTL8(q,3)) ^ (ROTL8(q,4)) ^ (0x63);
        sbox[p] = val;
        invsbox[val] = p; 
    } while (p != 1);
    
}

void ShiftRows(uint8_t state[16]){
    //shift row its own rank spaces to the left
    uint8_t tmp;
    int i, j;
    for (i=1; i<4; i++){
        tmp = state[4*i];
        for (j=0; j<4; j++){
            state[4*i + (j*i)%4] = state[4*i + ((j+1)*i)%4];
        }
        state[4*i + 4 - i] = tmp;
    }
}

void MixColumns(uint8_t state[16]){
    uint8_t tmp[4];
    int i, j;
    for (i=0; i<4; i++){
        tmp[0] = state[      i]; 
        tmp[1] = state[  4 + i];
        tmp[2] = state[2*4 + i]; 
        tmp[3] = state[3*4 + i];
        for(j=0; j<4; j++){
            //state[i] = (0x02)
        }
    }
}