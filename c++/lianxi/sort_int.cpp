#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    vector<int> n =  {1,2,3,4,7,8,5,3199,6};

    sort(n.begin(), n.end(),greater<int>());

    for (auto it : n) {
        cout << it << "|";
    }
    cout << endl;

    return 0;
}