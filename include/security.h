#ifndef _SECURITYHEAD_
#define _SECURITYHEAD_
#include "hshb_type.h"

#ifdef __cplusplus
extern "C" {
#endif

void aes_encrypt (U8 *in, U8 *key, U8 *out);
void aes_decrypt (U8 *in, U8 *key, U8 *out);
int  au_Init();
 int au_chk_vaild(U8 *recv_buf);
#ifdef __cplusplus
}
#endif

#endif


