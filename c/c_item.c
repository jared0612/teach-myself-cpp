/*************************************************************************
	> File Name: c_item.c
	> Author: 
	> Mail: 
	> Created Time: Sat 24 Sep 2022 01:01:17 AM CST
 ************************************************************************/

#include<stdio.h>
void output(int ,char**, char**);

void output(int argc, char *argv[], char *env[]) {
	printf("%d\n", argc);
	for (int i = 0; i < argc; i++) {
		printf("argv[%d]:%s\n", i, argv[i]);
	}
	for (int i = 0; env[i]; i++) {
		printf("env[%d]:%s\n", i, env[i]);
	}
}
int main(int argc, char **argv, char **env) {
	output(argc, argv, env);
	return 0;//返回给操作系统，代表成功运行。
}
//env是环境变量；
