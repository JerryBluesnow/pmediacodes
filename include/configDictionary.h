#ifndef CONFIGDICTIONARY_H_
#define CONFIGDICTIONARY_H_

	#include <sys/types.h>
	#include <stdio.h>
	#include <string.h>

	#include "sysconfig.h"


#define CONFIGDIC_BUF_SIZE 1600

#define CONFIG_VALUE_MAXSIZE 200

	//定义元素
	typedef struct dic_LinkList
	{
		char * key;
		char * value;
		struct dic_LinkList * next;
	} dic_LinkList, * dic_LinkListPtr;

	int shipinfo_init(); 
	boolean Config_init();
	boolean Config_save();
	char * Config_getItem(const char * key);
	void Config_setItem(const char * key, char * value);
	void Config_Destory();

#endif /* SYSDICTIONARY_H_ */
