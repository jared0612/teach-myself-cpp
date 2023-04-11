#include<iostream>
using namespace std;

int main() {
    int ans = 0;
    for (int i = 1; i < 1000; i++) {
        if (i % 3 == 0 || i % 5 == 0 ) {
            ans += i;
        }
    }
    cout << ans << endl;
    int t3 = (3 + 999) * 333 / 2;
    int t5 = (5 + 995) * 199 / 2;
    int t15 = (15 + 990) * 66 / 2;
    ans = t3 + t5 - t15;

    cout << ans << endl;
    return 0;
}
//复习练习
/*
#include<iostream>
using namespace std;

int ans = 0;
int main() {
    for (int i = 1, i <= 1000; i++) {
        if (i % 3 == 0 && i % 5 == 0) {
            ans += i;
        }
    }
    cout << ans << endl;
}
//第二种方法是利用等差数列进行求解，直接编写公式的代码就行。
//注意需要减掉公倍数；

//暴力解法：计算机枚举方法
//数学解法：依靠算法优化求解过程，减少计算资源的浪费，提高计算效率。
*/