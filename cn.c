
#include<stdio.h> 
#include<stdlib.h> 
#include<sys/socket.h> 
#include<sys/types.h> 
#include<netinet/in.h> 
#include<unistd.h>
#include<string.h>Intmain 
(intargc,charconst*argv[]){ 
intsockfd,rval;
struct 
sockaddr_inserv_addr;ch 
ar 
msgs[50],msgr[50];if(arg 
c<3) {
printf("\nusage:%sIPAddress 
port#\n");exit(1);
}
system("clear");sockfd=socket(AF_INET, 
SOCK_STREAM,0);if(sockfd==-1) {
perror("sock_CRE:");exit(1);
}
else 
printf("\nsocketcreated\n");serv_addr.sin_family=AF_INET;//defineserviceaddr 
essserv_addr.sin_port=htons(atoi(argv[2]));serv_addr.sin_addr.s_addr=inet_add 
r(argv[1]);
rval=connect(sockfd,(structsockaddr
*)&serv_addr,sizeof(serv_addr));if(rval==-1) { 
perror("connect_E
R:");exit(1);
}
else
printf("\nEnterthemessage:\t");scanf("%s",msgs);
rval=send(sockfd,(char *)msgs,sizeof(msgs),0); 
rval=recv(sockfd,(char *)msgr,sizeof(msgr),0); 
printf("\nServer Response:\t%s",msgr); 
close(sockfd);
}
