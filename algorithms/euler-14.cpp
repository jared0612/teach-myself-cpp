/*************************************************************************
	> File Name: euler-14.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 27 May 2022 08:47:52 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
//递归的方法进行求解
int func(long long x) {
	if (x == 1) return 1;
	if (x == 2) return 2;
	if (x % 2 == 0) return func(x / 2) + 1;
	else return func(3 * x + 1) + 1;	
}


//改进使用记忆数组+递归
int cnt[1000005];
int func1(long long x) {
	if (x == 1) return 1;

	int t = 0;
	if (x < 1000000 && cnt[x] != 0){
		t = cnt[x];
	}
	if (x % 2 == 0) {
		t = func1(x / 2) + 1;
	}else {
		t = func(3 * x + 1) + 1;	
	}
	if (x < 1000000) {
		cnt[x] = t;
	}
	return t;
}
long long  ans;
int len;
int main() {
	for (long long n = 1; n < 1000000; n++) {
		if (func(n) > len) {
			len = func(n);
			ans = n;
		}
	}
	cout << ans << endl;
	return 0;
}

