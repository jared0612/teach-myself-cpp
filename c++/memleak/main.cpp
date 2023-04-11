#include<iostream>
#include<string>
#include "memleak.h"
using namespace std;

int main () {
    int *a = new int{123};
    double *b  = new double{3};
    int  *c = new int[100];
    //double *bv  = new double{3};
    class A{};
    cout << sizeof(string) << endl;
    return 0;
}