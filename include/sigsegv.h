/*
 * sigsegv.h
 *
 *  Created on: 2010-8-12
 *      Author: limubai
 */

#ifndef SIGSEGV_H_
#define SIGSEGV_H_

#include "sysconfig.h"

#ifdef VER_DEBUG_STATE

	#ifdef __cplusplus
	extern "C" {
	#endif

		boolean setup_sigsegv();

	#ifdef __cplusplus
	}
	#endif

#endif

#endif /* SIGSEGV_H_ */
