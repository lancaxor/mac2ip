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
#include <string.h>

#ifndef DEFS_H_
#define DEFS_H_

#define SPLIT_BAD_OKSIZE	1024
#define SPLIT_BAD_ATTRIB	1025

int ipoksize=0;
int macoksize=0;

/**
* pow(int number, int power)
* return number in power
*/

int powr(int,int);

char* removeSeparators(char*);

long atohex(const char*);

void printdbg(char*);

#endif /* DEFS_H_ */

