/*
 * defs.h
 *
 *  Created on: 1 нояб. 2013
 *      Author: lexis
 */

#ifndef DEFS_H_
#define DEFS_H_

#define MAX_MAC48 281474976710655

typedef uint64_t mac48_t;


/**
* powr(int number, int power)
* return number in power
*/

int powr(int,int);

/**
 * char* removeSeparators(char*src,char type);
 * remove separators in string srs and return result
 */
char* removeSeparators(char*,char);

mac48_t atohex(const char*);

void printdbg(char*);

void printHelp();

char*mac48toa(mac48_t,char);

#endif /* DEFS_H_ */

