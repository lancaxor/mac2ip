<<<<<<< HEAD
/*
 * defs.h
 *
 *  Created on: 1 нояб. 2013
 *      Author: lexis
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <math.h>
#include <stdint.h>

#ifndef DEFS_H_
#define DEFS_H_

#define SPLIT_BAD_OKSIZE	1024
#define SPLIT_BAD_ATTRIB	1025

/**
 *	second parameter -- attribute.
 *	attrib='m' => splitting MAC
 *	arrtib='i' => splitting IP
 *	attrib=[other] => error & exit
 */
int ipoksize=0;
int macoksize=0;

long* splitIP(const char*,const char);

int powr(int,int);

void printdbg(char*);

#endif /* DEFS_H_ */
=======
#define _AFXDLL 0
#include <unistd.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
//#include <WinSock2.h>

#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

struct in_addr sin_mac,sin_inIP,sin_outIP;

long l_mac,l_out;

int noFound=1;

int firstParamLen=17;

void dbg(long ch);

void OutHelp();

//int hex2dec(char*dec);
>>>>>>> e3dac8dcccfc3f678516c7b89a0af1112d4108ed
