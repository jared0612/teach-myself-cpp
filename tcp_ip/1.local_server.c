/*************************************************************************
	> File Name: 1.local_server.c
	> Author: 
	> Mail: 
	> Created Time: Tue 13 Sep 2022 11:16:36 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<string.h>

int main(int argc, char **argv) {
	if(argc != 2) {
		error(1, 0, "usage: unixstreamserver <local_path>");
	}
	int listenfd, connfd;
	socklen_t clilen;
	struct sockaddr_un cliaddr, servaddr;

	listenfd = socket(AF_LOCAL, SOCK_STREAM, 0);
	if(listenfd < 0) {
		error(1, errno, "socket create  failed");
	}

	char *local_path = argv[1];
	unlink(local_path);
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sun_family = AF_LOCAL;
	strcpy(servaddr.sun_path, local_path);

	if(bind(listenfd, (struct *sockaddr)&servaddr, sizeof(servaddr)) < 0) {
		error(1, errno, "bind failed");
	}

	if (listen(listenfd, LISTENQ) < 0) {
		error(1, errno, "listen failed");
	}

	clilen =  sizeof(cliaddr);
	if((connfd = accept(listenfd, (struct sockaddr*)&cliaddr, &clilen)) < 0) {
		if(errno == EINTR)
			error(1, errno, "accept failed");
		else 
			error(1, errno, "accept failed");
	}
	char buf[MAX_SIZE];

	while(1) {
		bzero(buf, sizeof(buf));
		if(read(connfd, buf, BUFF_SIZE) == 0) {
			printf("client quit");
			break;
		}
		printf("Receive: %s\n", buf);

		char send_line[MAXLINE];
		sprintf(send_line, "Hi,%s", buf);

		int nbytes = sizeof(send_line);

		if(write(connfd, send_line, nbytes) !=nbytes)
			error(1, errno, "write failed!");
	}
	close(connfd);
	close(listenfd);
	exit(0);
}
//绑定本地文件路径，第一需要考虑应用属主对文件应该具有权限
//如果没有
