/*
 ============================================================================
 Name        : test_c_cross.c
 Author      : lex
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <math.h>
#include <string.h>
#include "defs.h"

int ipoksize=0;
int macoksize=0;

int main(void) {
	char *mac=(char*)malloc(100*sizeof(char));
	char *outip=(char*)malloc(100*sizeof(char));
	char*unsMac;
	char*unsIP;
	int resNum=0;
	mac48_t lmac=0,loutip=0;

	puts("Enter MAC & outer IP");
	scanf("%s %s",mac, outip);


	unsMac=removeSeparators(mac,'m');
	unsIP=removeSeparators(outip,'i');
	if(strcmp(unsMac,"RS_BAD_MAC48_FORMAT")==0){
		printdbg("bad MAC format!");
		return -2;
	}
	else if(strcmp(unsIP,"RS_BAD_MAC48_FORMAT")==0){
		printdbg("bad IP format!");
		return -1;}
	else if((strcmp(unsIP,"RS_BAD_PARAMETER_TYPE")==0)||(strcmp(unsIP,"RS_BAD_PARAMETER_TYPE")==0)){
		printdbg("Bad input string format!");
		return -3;}

	lmac=atohex(unsMac);
	loutip=atohex(unsIP);

	resNum=MAX_MAC48-lmac+1;
	loutip=lmac&loutip;

	for(long i=0x0;i<resNum;i++){
		long linip=loutip+i+1;
		int holost=100500;
		//here will be output...
		//printf("%s\n",mac48toa(temp));
	}

	if(resNum==0)	printf ("no addresses found!\n");
	else	printf("Founded %d addresses...\n",resNum);

	free(unsIP);
	free(unsMac);
	free(outip);
	free(mac);
	return EXIT_SUCCESS;
}

int powr(const int arg,int power){
	int result=1;
	for(int i=1;i<=power;i++){
		result*=arg;
	}
	return result;
}

char* removeSeparators(char*param,char type){
	int oksize=0;
	int oknum=0;
	int length=0;
	int hexindex=0;
	char*result;
	
	if(param[2]=='-'||param[2]==':'||param[2]=='.'){
		oksize=2;
		length=17;}
	else if(param[4]=='-'||param[4]==':'||param[4]=='.'){
		oksize=4;
		length=14;}
	else
		return  "RS_BAD_MAC48_FORMAT";

	if(type=='m')
		macoksize=oksize;
	else if(type=='i')
		ipoksize=oksize;
	else
		return "RS_BAD_PARAMETER_TYPE";
	
	result=(char*)malloc(12*sizeof(char));			//12 symbols in MAC48 (except separators)
	
	for(int i=0;i<length-1;i++){
		if((i+1)%(oksize+1)!=0){
		*(result+hexindex)=*(param+i);
		++hexindex;
		}
	}
	*(result+11)=*(param+length-1);
	return result;
}

mac48_t atohex(const char*param){					//xxxxyyyyyyyy
	mac48_t res=0;
	mac48_t first4=0x0L,last8=0x0L;
	printf("input: %s\n",param);
	char*last8bytes=(char*)malloc(8*sizeof(char));		//yyyyyyyy
	for(int i=0;i<8;i++)
		*(last8bytes+7-i)=*(param+11-i);
	sscanf(last8bytes,"%8x",&last8);
	printf("last8bytes: %s; last8: %x\n",last8bytes,last8);
	char*first4bytes=(char*)malloc(4*sizeof(char));		//xxxx
	for(int i=0;i<4;i++)
		*(first4bytes+i)=*(param+i);
	sscanf(first4bytes,"%8x",&first4);
	printf("first4bytes: %s; first4: %x\n",first4bytes,first4);
	first4*=0x100000000L;					//xxxx00000000
	res=(first4+last8);					//xxxxyyyyyyyy

	free(first4bytes);
	free(last8bytes);
	return res;
}

void printdbg(char*str){
	printf("\n\t>>> %s\n",str);
}

void printHelp(){
	printf("Usage: ./mac2ipc XX-XX-XX-XX-XX-XX YY-YY-YY-YY-YY-YY\n or XXXX.XXXX.XXXX ./mac2ipc YYYY.YYYY.YYYY, \n where X and Y - hex num from 0 to F.\n Instead of '-' you may type '.' or ':'.\n Warning: if in some oktet is 1 number among 2, write 0 before it: XX.0X.XX");
}

char*mac48toa(mac48_t mac, char type){
	char*result;
	char*buf=(char*)malloc(12*sizeof(char));
	int len=0;
	int oksize=0;
	if(type=='m')
		oksize=macoksize;
	else if (type=='i')
		oksize=ipoksize;
	else
		return "MTOA_BAD_TYPE";

	len=(oksize==2)?17:14;
	result=(char*)malloc(len*sizeof(char));

	/*for(int i=0;i<len;i++){

	}*/
	free(buf);
	free(result);
	return result;
}
