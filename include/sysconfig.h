
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

	#define	SERVER_INFO_MAXCOUNT	30		//最大服务器端连接数


	#include <time.h>
	#include <stdio.h>     /*标准输入输出定义*/
	#include <stdlib.h>
	#include <string.h>

	#include "G711.h"
	#include "voice_Encoder_Decoder.h"

	extern char ApplicationPath[128];	//软件运行的绝对路径
	extern char ApplicationName[30];	//软件名称
	extern char LOGFILE_NAME[128];
	extern char CONFIGFILE_NAME[128];

	extern struct server_info_struct	server_infos[SERVER_INFO_MAXCOUNT];

	extern int localID;				//电台号

	#define local_project_No		1		//项目编号

	extern int local_version_No;	//系统版本号

	extern int COM_PORTNUM;			//串口号

	extern int UDP_SERV_PORT;		//UDP端口号

	extern int TCP_SERV_PORT;		//TCP端口号

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
