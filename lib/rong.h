#ifndef _rong_h
#define _rong_h


#include    <stdio.h>
#include    <stdlib.h>
#include    <string.h>
#include    <unistd.h>
#include    <errno.h>
#include	<sys/types.h>
#include 	<sys/socket.h>

#include 	<netinet/in.h>
#define min(a,b) ((a) < (b) ? (a) : (b))
#define max(a,b) ((a) > (b) ? (a) : (b))

#define LISTENQ		1024
#define MAXLINE     4096


#define	SA	struct	sockaddr
#define SERV_PORT	20211
void	str_echo(int);

void 	str_cli(FILE*,int);

void	Writen(int ,void *,size_t);
ssize_t	readline(int,void*,size_t);
ssize_t Readline(int,void*,size_t);

char*	Fgets(char*,int,FILE*);
void 	Fputs(const char *,FILE *);


void    err_dump(const char *,...);
void    err_msg(const char *,...);
void    err_quit(const char *,...);
void    err_ret(const char *,...);
void    err_sys(const char *,...);


#endif
