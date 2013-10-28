#include "hmain.hpp"

/**************************************************/
/*******	Inner_addr & MAC=Outer_Addr;	*******/
/**************************************************/
/*******	using: mac2ip ip.addr mac.addr	*******/
/**************************************************/

int main(int args,char*argv[]){
	if(args<2){
		cout<<"MAC & IP required!"<<endl;
		OutHelp();
		return 1;}
	else if(args<3){
		SplitConvertIp(argv[1]);
		for(int i=0;i<firstParamLen;i++)
			argv[1][i]=toupper(argv[1][i]);
		if(strcmp(argv[1],"HELP/0")){
			OutHelp();
			return 5;}
		cout<<"MAC required!"<<endl;
		return 2;}

	l_mac=inet_addr(argv[1]);
	l_out=inet_addr(argv[2]);
	sin_mac.s_addr=l_mac;
	sin_outIP.s_addr=l_out;

	{
		int *checkMAC=SplitConvertIp(argv[1]);
		int *checkIP=SplitConvertIp(argv[2]);
		for(int i=0;i<4;i++){
			if(checkMAC[i]>255||checkMAC[i]<0){
				cout<<"Incorrect MAC"<<endl;
				return 3;}
			if(checkIP[i]>255||checkIP[i]<0){
				cout<<"Incorrect IP"<<endl;
				return 4;}}
	}

	cout<<"MAC: "<<inet_ntoa(sin_mac)<<endl
	<<"Outer IP: "<<inet_ntoa(sin_outIP)<<endl;
	cout<<"-----------------------------------------"<<endl
		<<"Inner IPs:"<<endl;

	for(long l=0;l<4294967295;l++){
		if((l&l_mac)==l_out){
			noFound=false;
			sin_inIP.s_addr=l;
			cout<<inet_ntoa(sin_inIP)<<endl;}}
	cout<<(noFound?"No Addresses found!":"")<<endl;
	system("pause");
	return 0;}
	
