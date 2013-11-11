/*
 ============================================================================
 Name        : bcopy.c
 Author      : lexis
 Version     :
 Copyright   : Only for non-commercial use(c)
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "defs.h"

int main(int args,char**argv) {
	int inNum=args-1;
	switch(inNum){
	case 0:
		puts("Usage: bcopy [-m remotehost [-p remoteport]]\n\t\t[-r] src [dest]");
		break;
	case 1:
		if(isOption(*(argv+inNum))==0)
			puts("Invalid params.");
		else{
			if(strcmp(getParam(*(argv+inNum)),"h")==0)
				puts("Usage: bcopy [-m remotehost [-p remoteport]]\n\t\t[-r] src [dest]\n");
			else if(strcmp(getParam(*(argv+inNum)),"v")==0)
				puts((char*)version);
			else
				printf("bcopy: Invalid option \"%s\"\n", getParam(*(argv+inNum)));
		}
		break;

	}
	return EXIT_SUCCESS;
}

int isOption(const char* arg){
	if(*arg=='-')
		return 1;
	else
		return 0;
}

char*getParam(const char* param){
	if(isOption(param)==0){
		return GP_NO_PARAM;
	}
	int paramLen=strlen(param);
	char* res=(char*)malloc(sizeof(char)*(strlen(param)-1));
	for(int i=1;i<paramLen;i++)
		*(res+(i-1))=*(param+i);
	return res;
}
