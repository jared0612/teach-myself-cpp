/*************************************************************************
	> File Name: euler-2.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 03 Apr 2022 07:30:54 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;
void fib();
bool isEven(int);
int ans = 0;

int main() {
    //求得每个数，然后判断是不是偶数
    fib();
    cout << ans << endl;
    return 0;
}
bool isEven(int n) {
    if (n % 2 == 0) return true;
    return false;
}
void fib() {
    int a1 = 1;
    int a2 = 2;
    int tmp = a2;
    while(a2 <= 4000000) {
        if (isEven(a2)) ans+=a2;
        tmp = a2;
        a2 += a1;
        a1 = tmp;
    }

}

/*/练习
#include<iostream>
using namespace std;

int num[4000000];
int main() {
    int ans = 0;
    int num[0] = 1, num[1] = 2;
    for (int i = 2; 1; i++) {
        if(num[i - 1] % 2 == 0) 
            ans += num[i];
        num[i] = num[i - 1] + num[i - 2];
    }
    cout << ans << endl;
    return 0;
}
