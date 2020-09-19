
#ifndef VOICE_ENCODER_DECODER_H_
#define VOICE_ENCODER_DECODER_H_

	#ifdef VER_G729A_PC

		//G729A编解码
		extern void va_g729a_init_encoder();
		extern void va_g729a_encoder(short * speech, unsigned char * bitstream);
		extern void va_g729a_init_decoder();
		extern void va_g729a_decoder(unsigned char *bitstream, short * synth_short, int bfi);

	#else

		#include "typedef.h"

		//G729A编解码
		extern void G729aInitEncoder();
		extern void G729aEncoder(Word16 * speech, unsigned char * bitstream);
		extern void G729aInitDecoder();
		extern void G729aDecoder(unsigned char * bitstream, Word16 * synth_short, int bfi);

	#endif

#endif /* VOICE_ENCODER_DECODER_H_ */
