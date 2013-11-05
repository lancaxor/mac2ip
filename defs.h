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
