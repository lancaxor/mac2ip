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
