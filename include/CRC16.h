
#ifndef CRC16_H_
#define CRC16_H_

	#include "sysconfig.h"

	boolean check_CRC16(const unsigned char * newdata, unsigned int length);

	void get_CRC16(unsigned char * newdata, unsigned int length);

#endif /* CRC16_H_ */
