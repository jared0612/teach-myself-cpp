/*************************************************************************
	> File Name: euler-6.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 03 Apr 2022 11:29:19 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int sumOfpow = 0, powOfsum = 0; 
int main() {
	for (int i = 1; i <=100; ++i) {
		sumOfpow = i * i;
		powOfsum += i;
	}
//	powOfsum = ((1+100) * 100 / 2) * ((1+100) * 100 / 2);
	cout << "(pow -sum) :" << powOfsum * powOfsum - sumOfpow << endl;
	return 0;
}
