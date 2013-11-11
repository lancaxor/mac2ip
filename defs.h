/*
 * defs.h
 *
 *  Created on: 11 нояб. 2013
 *      Author: lexis
 */

#ifndef DEFS_H_
#define DEFS_H_
#define version "bcopy utility version 0.0.1"
#define GP_NO_PARAM "NO_PARAM_INPUT"
#define GP_NO_CHPARAM "NO_CHAR_PARAM_INPUT"

/**
 * int isOption(char* arg)
 * return 0 if arg is not option
 * Option -- some string, started with '-' char
 */

int isOption(const char*);

/**
 * return param name
 * (only deleting '-' from input string)
 */
char*getParam(const char*);

#endif /* DEFS_H_ */
