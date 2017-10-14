#include "rong.h"

int main(int argc,char **argv)
{
	int			listendfd,connfd;
	pid_t		childpid;
	socklen_t	clilen;
	struct sockaddr_in	cliaddr,servaddr;
	listendfd = socket(AF_INET,SOCK_STREAM,0);
	bzero(&servaddr,sizeof(servaddr));
	servaddr.sin_family			=AF_INET;
	servaddr.sin_addr.s_addr	= htonl(INADDR_ANY);
	servaddr.sin_port			= htons(SERV_PORT);

	bind(listendfd,(SA*) &servaddr,sizeof(servaddr));

	listen(listendfd,LISTENQ);

	sleep(30);
	int i=0;
	for( ; ; ){
		
		clilen=sizeof(cliaddr);
		connfd = accept(listendfd,(SA*) &cliaddr,&clilen);
		printf("the number of completely tcp connctor is =%d\n",++i);
		if( (childpid = fork())==0){
			close(listendfd);
			str_echo(connfd);
			exit(0);
		}
		close(connfd);	
	}
}
