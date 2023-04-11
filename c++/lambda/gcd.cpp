/*************************************************************************
	> File Name: gcd.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 29 Mar 2023 03:17:50 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

template<unsigned int x, unsigned int y>
struct GreatestCommonDivisor {
    static const unsigned int result = GreatestCommonDivisor<y, x % y>::result;
};

template<unsigned int x> 
struct GreatestCommonDivisor<x, 0> {
    static const unsigned int result = x;
};

int main() {
    cout << "The GCD of 40 and 10 is: " << GreatestCommonDivisor<40u, 10u>::result << endl;
    cout << "The GCD of 366 and 60 is: " << GreatestCommonDivisor<366u, 60u>::result << endl;
    return 0;
}
