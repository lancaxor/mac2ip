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
	case 0:	//0
		puts("Usage: bcopy [-m remotehost [-p remoteport]]\n\t\t[-r] src [dest]");
		break;
	case 1:
		if(isOption(*(argv+inNum))==0)	//2
			printf("Invalid parameter: '%s'\n",*(argv+1));
		else{		//1
			if(strcmp(getParam(*(argv+inNum)),"h")==0||strcmp(getParam(*(argv+inNum)),"-help")==0)
				puts("Usage: bcopy [-m remotehost [-p remoteport]]\n\t\t[-r] src [dest]\n");
			else if(strcmp(getParam(*(argv+inNum)),"v")==0)
				puts((char*)version);
			else
				printf("bcopy: Invalid option \"%s\"\n", getParam(*(argv+inNum)));
		}
		break;
	case 2:
		if(isOption(*(argv+1))==0 &&isOption(*(argv+2))==0){	//3
			if(strcmp(*(argv+1),*(argv+2))==0){
				printf("source cannot equals to destination!\n");
				return -4;
			}
			FILE*reader,*writer;
			if((reader=fopen(*(argv+1),"r"))!=NULL && (writer=fopen(*(argv+2),"w"))!=NULL){
				while(!feof(reader)){
					int _char=fgetc(reader);
					if(_char==EOF)
						break;
					fputc(_char,writer);
				}
				fclose(writer);
				fclose(reader);}
			else
			{
				printf("Error opening file!\n");
				return -3;
			}
		}
		else
			printf("Invalid parameters: '%s %s'\n",*(argv+1),*(argv+2));
		break;
	default:
		puts("Default msg...");
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
