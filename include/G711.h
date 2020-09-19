/*
 * G711.h
 *
 *  Created on: 2011-11-3
 *      Author: limubai
 */

#ifndef G711_H_
#define G711_H_

#include "sysconfig.h"

//g711压缩率为2:1
//常用的是A率   linear2alaw，alaw2linear

unsigned char linear2alaw(short pcm_val);	/* 2's complement (16-bit range) */
short alaw2linear(unsigned char a_val);

unsigned char linear2ulaw(int pcm_val);
int ulaw2linear(unsigned char u_val);

unsigned char alaw2ulaw(unsigned char aval);
unsigned char ulaw2alaw(unsigned char uval);

#endif /* G711_H_ */
