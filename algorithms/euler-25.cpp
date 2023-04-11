#include<iostream>
using namespace std;
void big_add(int  *n1, int  *n2) {
    n2[0] = n1[0];
    for(int i = 1; i <= n2[0]; i++) {
        n2[i] += n1[i];
        if (n2[i] > 9) {
            n2[i + 1]++;
            n2[i] -= 10;
            if (i == n2[0]) {
                n2[0]++;
            }
        }
    }
}
//使用数组，第零位存储的是大整数的位数，因为仅仅是位数所以不需要进行倒序存储。
int main() {
    int num[2][1005] = {{1,1}, {1,1}}, a = 0, b = 1;
    for (int i = 3; 1; i++) {
        big_add(num[a], num[b]);
        if(num[b][0] == 1000) {
            cout << i << endl;
            break;
        }
    }
    return 0;
}