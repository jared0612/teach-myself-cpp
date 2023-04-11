#include<stdio.h>
#include<stdlib.h>
static int a = 12;
void print_static1() {
    printf("1:%d\n", a);
}
void print_static2() {
    printf("2:%d\n", a);
}

int main() {
    
    printf("origin:%d",a);
    for(int i = 1; i < 3; i++) {
        a++;
    }
    printf("after:%d",a);
    print_static1();
    print_static2();
    return 0;
}


