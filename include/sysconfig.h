
#ifndef SYSCONFIG_H_
#define SYSCONFIG_H_

#include "hshb_type.h"

#ifdef __cplusplus
extern "C" {
#endif
	//#define VER_Audio_OSS
	#define VER_Audio_ALSA

	//#define VER_G729A_PC
	#define VER_G729A_ARM

	//#define VER_DEBUG_STATE					//调试状态

	//#define VER_PLATFORM_PC
	#define VER_PLATFORM_FRIENDLYARM			//硬件平台


	typedef int	boolean;
	typedef unsigned char	uint8;
	typedef short			int16;
	typedef unsigned short	uint16;
	typedef int				int32;
	typedef unsigned int	uint32;

	#include <time.h>
	#include <stdio.h>     /*标准输入输出定义*/
	#include <stdlib.h>
	#include <string.h>

	#include "G711.h"
	extern volatile unsigned int local_TX_frequency;
	extern volatile unsigned int local_RX_frequency;
	extern volatile unsigned char local_radio_mode;
	extern volatile unsigned int local_radio_channel;
	extern volatile int local_radio_RSSI;

	#define local_radio_type		TKR_750		
#ifdef __cplusplus
}
#endif
#endif /* SYSCONFIG_H_ */
