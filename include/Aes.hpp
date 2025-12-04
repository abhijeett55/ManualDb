#ifndef AES_HPP
#define AES_HPP

#ifndef uint8
#define uint8 unsigned char
#endif


#ifndef uint32
#define uint32 unsigned long int
#endif


typedef struct {
    uint32 erk[32];  /* encryption round keys */
    uint32 drk[32];
    int nr;           /* number of rounds */
}

aes_context;

extern int aes_set_key(aes_context *ctx, uint8 *key, int nbits);
extern void aes_encrypt( aes_context *ctx, uint8 input[16], uint8 output[16]);
extern void aes_decrypt( aes_context *ctx, uint8 input[16], uint8 output[16]);
#endif