/*************************************************************************
	> File Name: addsum.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 23 Feb 2023 12:34:50 PM CST
 ************************************************************************/
//有一些方法
//1、使用暴力求解，双循环来解决
//2、通过空间换时间来进行
//3、通过双指针一次遍历
#include<iostream>
#include<vector>
#include<map>
using namespace std;

void func(vector<int> &, int);
int main() {
    vector<int> v = {2,6, 11, 15};
    int target = 9;
    func(v, target);
    return 0;
}


void func(vector<int> &v, int target) {
    map<int, int> m;
    for (int i = 0; i < v.size(); i++) {
        m[v[i]] = 1;
    }
    for (int i = 0; i < v.size(); i++) {
        if (m[target - v[i]] == 1) cout << "[ " << v[i] << "," << target - v[i] << "]\n";
    }

}
