#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc,char*argv[]){
long l=0;
char ch[48];
scanf("%s",&ch);
printf("U entered: >%s<",ch);

l=atoi(ch,16);

printf("L: >%d<\n",l);
return 0;}
