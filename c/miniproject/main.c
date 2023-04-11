/*************************************************************************
	> File Name: main.c
	> Author: 
	> Mail: 
	> Created Time: Sat 24 Sep 2022 01:21:12 AM CST
 ************************************************************************/

#include<stdio.h>
/*
void funcB(int n) {
	if (n == 0) return;
	printf("funcB: %d\n", n);
	funcA(n - 1);
}
*/
extern void funcB(int);

void funcA(int n) {
	if (n == 0) return ;
	printf("funcA: %d\n", n);
	funcB(n - 1);
	return ;
}

int main() {
	funcA(5);
	return 0;
}

