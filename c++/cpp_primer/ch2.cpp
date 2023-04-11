/*************************************************************************
	> File Name: b.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 02 Mar 2023 12:38:44 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
extern int n;
int main () {
    double Double = 3.14;
    decltype(Double + 1) dd;
    int a = 12;
    int &b = a;
    int &c = a;
    int *e = &a;
    int *&r = e;
    int  &d = c;
    typedef char *pstring;
    pstring p;//p是一个指针,指向char
    const pstring pp = p; //称const pstring为T，泽T是pp的变量类型，我们发现T为指向char的一个常量指针，那么pp就是一个指向char的常量指针。
    const pstring *ppp = &pp;//首先知道ppp是一个指针，指向一个指向char的常量指针
    double aa = 3.14;
    const double &ra = aa;
    const double bb = 3.14;
    return 0;

}
