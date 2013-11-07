/*
 ============================================================================
 Name        : test_c_cross.c
 Author      : lex
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */


#include "defs.h"

int main(void) {
	//freopen("in.txt","r",stdin);
	char *mac=(char*)malloc(100*sizeof(char));
	char *outip=(char*)malloc(100*sizeof(char));
	long lmac=0,loutip=0;
	puts("Enter MAC");
	scanf("%s",mac);
	puts(mac);
	//puts("Enter outer IP");
	//scanf("%s",&outip);

	printdbg("Unsplitting...");
	char*unsplitted=removeSeparators(mac);
	if(strcmp(unsplitted,"ERROR_WHILE_COUNTING_OKTET_SIZE")!=0)
		printf("Afret splitting: %s\n",unsplitted);
	else{
		printdbg("bad MAC format!");
		return -1;}
	lmac=atohex(unsplitted);
	printf("Result: %12x\n",lmac);
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

char* removeSeparators(char*param){
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
		return  "ERROR_WHILE_COUNTING_OKTET_SIZE";
	
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

long atohex(const char*param){					//xxxxyyyyyyyy
	long res=0;
	long long first4=0x0L,last8=0x0L;
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
	first4*=0x1000000L;					//xxxx00000000
	printf("After out: %13x\n",*(&first4));
	res=(first4+last8);					//xxxxyyyyyyyy
	return res;
}

void printdbg(char*str){
	printf("\n\t>>> %s\n",str);
}
