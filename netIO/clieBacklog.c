#include "rong.h"
#include <fcntl.h>
#define MAXBACKLOG 1499 
int  main(int argc,char **argv)
{
		int 		sockfd[MAXBACKLOG+1];
		struct	sockaddr_in servaddr;

		if(argc !=2)
				err_quit("usage: cliecho<IPaddress>");

		for(int i=0;i<MAXBACKLOG;i++){

				sockfd[i]= socket(AF_INET,SOCK_STREAM,0);
				bzero(&servaddr,sizeof(servaddr));
				servaddr.sin_family = AF_INET;
				servaddr.sin_port = htons(SERV_PORT);
				inet_pton(AF_INET,argv[1],&servaddr.sin_addr);
				fcntl(sockfd[i], F_SETFL, O_NONBLOCK);	
				connect(sockfd[i],(SA *) &servaddr,sizeof(servaddr));
		}

		printf("try to make %d connects\n",MAXBACKLOG);
		str_cli(stdin,sockfd[0]);
		exit(0);

}
