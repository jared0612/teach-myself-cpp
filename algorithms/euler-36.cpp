/*************************************************************************
	> File Name: euler-36.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 03 Apr 2022 11:10:57 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;
bool isHuiwen(int n,int x) {
	int tmp = n, rn = 0;
	while(tmp) {
		rn = rn * x + tmp % x;
		tmp /= x;
		}
	return rn == n;
}
int ans;
int main() {
	for (int i = 1; i < 1000000; ++i) {
		if (isHuiwen(i, 2) && isHuiwen(i, 10)){
			ans += i;
		}
	}
	cout << ans << endl;

	return 0;
}

