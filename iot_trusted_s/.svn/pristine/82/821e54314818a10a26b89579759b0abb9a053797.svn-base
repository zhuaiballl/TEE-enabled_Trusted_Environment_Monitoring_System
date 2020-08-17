#include "app_aes.h"

static uint8_t key[] = { 0x2b, 0x7e, 0x15, 0x16, 0x28, 0xae, 0xd2, 0xa6, 0xab, 0xf7, 0x15, 0x88, 0x09, 0xcf, 0x4f, 0x3c};

void app_aes_encrypt(uint8_t* Clear_text,uint16_t dlen)
{
	struct AES_ctx ctx;
	//uint32_t dlen = strlen(Clear_text);
	AES_init_ctx(&ctx, key);
	for (int i = 0; i * 16 < dlen; i++)
	{
		AES_ECB_encrypt(&ctx, Clear_text+i*16);
	}
#if DEBUG_APP_AES
	PRINTF("%s\r\n",Clear_text);
#endif
	return;
}

void app_aes_decrypt(uint8_t* Cipher_text,uint16_t dlen)
{
	struct AES_ctx ctx;
	//uint32_t dlen = strlen(Cipher_text);
	AES_init_ctx(&ctx, key);
	for (int j = 0; j * 16 < dlen; j++)
	{
		AES_ECB_decrypt(&ctx, Cipher_text + j*16);
	}
#if DEBUG_APP_AES
	PRINTF("%s\r\n",Ciphertext);
#endif
	return;
}
