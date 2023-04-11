#include<iostream>

using namespace std;

bool isHuiwen(int n) {
    int bak = n, rn = 0;

    while(bak) {
        rn  =  (bak % 10) + rn * 10;
        bak /= 10;
    }
    return rn == n;

}
int main() {
    int ans = 0;
    for (int i = 999; i >= 500; --i) {
        for (int j = 999; j >= 500; --j) {
            if(isHuiwen(i * j)) {
                ans = max(ans, i * j);
                }
        }
    }
    cout << ans << endl;
    return 0;
}
/*练习

#include<iostream>
#include<algorithm>
using namespace std;
int isHw(int x) {
    int tmp = x, new = 0;
    while(tmp) {
        new = new * 10 + tmp % 10;
        tmp /= 10;
    }
    return new == x;
}

int main() {

    int target = 0;
    for (int first = 100; first < 1000; first++) {
        for (int second = 100; second < 1000; second++) {
            if (isHw(first * second))
                target = max(target, first * second);
        }
    }
    cout << target << endl;
    return 0;
}

