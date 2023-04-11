/*************************************************************************
	> File Name: unite.c
	> Author: 
	> Mail: 
	> Created Time: Sat 24 Sep 2022 01:38:27 AM CST
 ************************************************************************/

#include<stdio.h>
extern void funcA(int);
void funcB(int n) {
	if (n == 0) return;
	printf("funcB: %d\n", n);
	funcA(n - 1);
}

