
#ifndef PROTOCOL_RTOS_ALIVE_H_
#define PROTOCOL_RTOS_ALIVE_H_

#include "Protocol_Basic.h"

typedef union __attribute__((packed)) Radio_frequency
{
	struct __attribute__((packed))
	{
		uint32              TX_frequency;
		uint32              RX_frequency;
		uint8				radio_mode;			//enum eRadio_mode
		uint8				radio_failure;
		int16				radio_RSSI;
		uint16				channel_No;
	}fld;

	/*
	5.1.1 电台频率
	偏移量	字段	字节数	值	描述
	0	发射频率	4	频率*1000	整数
	4	接收频率	4	频率*1000	整数
	8	电台工作模式	1		4.2.3
	9	电台故障代码	1	0正常；1故障
	10	场强值	2
	12	信道号	2
	*/

	uint8                 All[14];
} Radio_frequency;

//5.1 ROIP心跳包（R->S）
typedef union __attribute__((packed)) tRtoS_ALIVE_REQUEST
{
	struct __attribute__((packed))
	{
		uint16 				Opcode;			//0x0400
		uint16              radio_No;
		union Radio_frequency  	Radio_Frequency;	//长度14
	}fld;

	/*
	5.1 ROIP心跳包（R->S）
	偏移量	字段	字节数	值	描述
	0	操作码	2	0x0400
	2	电台编号	2
	4	电台频率	12	结构	5.1.1
	*/

	uint8                 All[18 + 2];
} tRtoS_ALIVE_REQUEST;

//5.2 ROIP心跳包，服务器的回应（S->R）
typedef union __attribute__((packed)) tStoR_ALIVE_RESPONSE
{
	struct __attribute__((packed))
	{
		uint16 				Opcode;				//0x0401
		uint16              radio_No;
		uint8				alive_status;		//enum eAlive_status
		uint16              ROIP_version_No;	//最新ROIP版本
		uint16				UDP_package_count;	//升级包数量
	}fld;

	/*
	5.2 ROIP心跳包，服务器的回应（S->R）
	偏移量	字段	字节数	值	描述
	0	操作码	2	0x0401
	2	电台编号	2
	4	运行情况	1		4.2.2
	5	版本号	2	ROIP最新版本号
	7	UPD包数量	2
	*/

	uint8                 All[9 + 2];
} tStoR_ALIVE_RESPONSE;

//5.1 ROIP心跳包（R->S）
void send_RtoS_ALIVE_REQUEST(struct sockaddr_in * p_cliaddr);


#endif /* PROTOCOL_RTOS_ALIVE_H_ */
