/*************************************************************************
	> File Name: 1-prime.c
	> Author: 
	> Mail: 
	> Created Time: Wed 15 Dec 2021 05:08:29 PM CST
    > 学习素数筛的使用方法，以及如何进行优化。
 ************************************************************************/

#include<stdio.h>

#define MAX_N 10000000
int mark[MAX_N + 1];

int prime(int n) {
    for (int i = 2; i <= n; i++) {
        if (mark[i] == 0) {
            for (int j = i; i * j <= n; j++) { //优化原本是j从2开始，为了避免重复，使用从i开始就行
                mark[i * j] = 1;
            }
        }
    }
}

int main() {
    int n = 100000000;
    prime(n);//标记数组，数组下标就是素数。
    int count = 0;
//    for (int i = 2; i<= n; i++) {
//        if (mark[i] == 0) {
//            printf("%d\n", i);
//            count++;
//        }
//    }
//    printf("%d\n", count);
    return 0;
}
