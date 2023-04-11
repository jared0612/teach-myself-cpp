#include<iostream>
//#define myprint(int) print(__FILE__, __LINE__)
using namespace std;

void print(int n) {
    cout << n << endl;
    cout << __FILE__<< endl;
    cout << __LINE__ << endl;   
}
int main() {
    print(3);
    return 0;
}
