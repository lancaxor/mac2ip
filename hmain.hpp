#define _AFXDLL 0
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string.h>
//#include <WinSock2.h>

#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

using namespace std;

struct in_addr sin_mac,sin_inIP,sin_outIP;

long l_mac,l_out;

bool noFound=true;

int firstParamLen=0;

int* SplitConvertIp(char*ip){
	string str=string(ip);
	firstParamLen=str.length();
	int prevDot=0;
	int nextDot=str.find('.');
	int*res=new int[4];
	for(int i=0;i<4;i++){
		res[i]=atoi(str.substr(prevDot,nextDot).c_str());
		prevDot=nextDot+1;
		nextDot=str.find('.')<0?str.length():str.find('.',prevDot);
	}
	return res;
}

void OutHelp(){
	cout<<"Ussage: mac2ip [subnet IP] [MAC]"<<endl
		<<"Params format: xxx.xxx.xxx.xxx"<<endl
		<<"xxx -- number from 0 to 255"<<endl
		<<"join!"<<endl;}
