#include "aes.h"

#define DEBUG_APP_AES 0

#if DEBUG_APP_AES
	#include "fsl_debug_console.h"
#endif

void app_aes_encrypt(uint8_t* Clear_text,uint16_t dlen);
void app_aes_decrypt(uint8_t* Ciphertext,uint16_t dlen);
