/*************************************************************************
	> File Name: euler-8.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 03 Apr 2022 11:27:41 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;


long long ans;
int main() {
	string n;
	cin >> n;
	for(auto it1 = n.begin(), it2 = n.begin() + 13; it2 != n.end(); ++it1, ++it2) {
		long long multi = 1;
		if ((*it2) == '0') continue;
		for (auto it  = it1; it != it2; ++it) {
			multi *= (*it) - 48;
		}
		ans = max(ans, multi);
	}
	cout << ans << endl;
	return 0;
}

