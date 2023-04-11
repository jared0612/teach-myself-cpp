#include<stdlib.h>
#include<stdio.h>
#define STR(s) #s
#define WORD_LO(xxx) ((xxx) & 255)
#define WORD_HI(xxx) ((xxx) >> 8)
void fn1();
void fn2();

int main() {
    atexit(fn1);
    atexit(fn2);
    printf("main exit...\n");
    printf("%s\n", STR(sss));
    short a = 0x011;
    printf("HI8 is: %d\n",WORD_HI(a));
    printf("LO8 is: %d\n",WORD_LO(a));

    return 0;
}

void fn1(){
    printf("call fn1...\n");
}

void fn2(){
    printf("call fn2...\n");
}
