/*************************************************************************
	> File Name: learntcp.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 13 Sep 2022 07:23:49 AM CST
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<netinet/in.h>

using namespace std;

typedef unsigned short int sa_family_t;
struct sockaddr{
	sa_family_t sa_family;
	char addr[14];
};

int make_socket(uint16_t port) {
	int sock;
	struct sockaddr_in name;

	sock = socket(PF_INET, SOCK_STREAM, 0);//最后的参数一般写成0
	if(sock < 0) {
		perror("socket");
		exit(EXIT_FAILURE);
	}
	//创建连接后，进行套接字的绑定
	name.sin_family = AF_INET;
	name.sin_port = htons(port);
	name.sin_addr.s_addr = htonl(INADDR_ANY);
	if(bind(sock, (struct sockaddr*) &name, sizeof(name)) < 0) {
		perror("bind");
		exit(EXIT_FAILURE);
	}
	return sock;
}
int main() {

	return 0;
}

