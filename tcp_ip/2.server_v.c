/*************************************************************************
	> File Name: 2.server_v.c
	> Author: 
	> Mail: 
	> Created Time: Tue 20 Sep 2022 03:15:43 PM CST
 ************************************************************************/

#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<netdb.h>
#include<sys/ioctl.h>
#include<sys/poll.h>

int main(int arg, char **argv[]) {
	if (argc != 2) {
		error(1, 0, "Usage tcpclient <IPaddress>");
	}

	int socket_fd;
	socket_fd = socket(AF_INET, SOCK_STREAM, 0);

	struct sockaddr_in server_addr;
	bzero(&server_addr, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(SERV_PORT);
	inet_pton(AF_INET, argv[1], &server_addr.sin_addr);

	socklen_t server_len = sizeof(server_addr);
	int connect_rt = connect(socket_fd, (struct sockaddr*) &server_addr, server_len);
	if (connect_rt < 0) {
		error(1, errno, "connect failed");
	}

	char buff[128];
	struct iovec iov[2];
	char *send_one = "hello";
	iov[0].iov_base = send_one;
	iov[0].iov_len = sizeof(send_one);
	iov[1].iov_base = buff;
	while(fgets(buff, sizeof(buff), stdin) != NULL) {
		iov[1].iov_len = strlen(buff);
		int n = htonl(iov[1].iov_len);
		if (writev(socket_fd, iov, 2) < 0) {
			error(1, errno, "writev failed!");
		}
	}



	return 0;
} 

