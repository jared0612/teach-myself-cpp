/*************************************************************************
	> File Name: euler-11.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 27 May 2022 08:35:15 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

int num[30][30];
int dirx[4] = {-1, 0, 1, 1};
int diry[4] = {1, 1, 1, 0};
int main() {
	for (int i = 5; i < 25; i++) {
		for (int j = 5; j < 25; j++) {
			cin >> num[i][j];
		}
	}
	int ans = 1;
	for (int i = 5; i < 25; i++) {
		for (int j = 5; j < 25; j++) {
			int tmp = num[i][j];
			for(int r = 0; r < 4; r++) {
				for (int l = 1; l < 4; l++){
					int x = i + dirx[r] * l;
					int y = j + diry[x] * l;
					tmp *= num[x][y];   
				}
			}
			ans = max(ans, tmp);
		}
	}
	cout << ans << endl;
	return 0;
}

