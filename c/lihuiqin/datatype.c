/*************************************************************************
	> File Name: datatype.c
	> Author: 
	> Mail: 
	> Created Time: Sat 01 Apr 2023 03:07:25 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
static sta = 1;
func() {
    static sta = 12;
    sta++;
    printf("sta in %d\n", &sta);
}
int main() {
    auto i;
    int j;

    static int k;

    printf("sta = %d in %d\n", sta, &sta);
    func();
    printf("sta = %d in %d\n", sta, &sta);
    printf("i = %d\n", i);
    printf("j = %d\n", j);
    printf("k = %d\n", k);
    return 0;
}
