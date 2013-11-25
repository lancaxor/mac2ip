/*
 * defs.h
 *
 *  Created on: 1 нояб. 2013
 *      Author: lexis
 */

#include <stdint.h>
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

/**
 * (Отсюда и дальше писать на инглише комменты влом...
 * Конвертация строки в mac48_t
 */

mac48_t atohex(const char*);

/*
 * Вывод отладочных сообщений. Сообщения, выведенные с помощью этой функции, будут
 * выделены (отличаются от printf)
 */

void printdbg(char*);

/*
 * Вывод справки по приложению
 */

void printHelp();

/*
 * Конвертация длинного числа mac48ip_t в строку
 */

char*mac48toa(mac48_t,char);


#endif /* DEFS_H_ */

