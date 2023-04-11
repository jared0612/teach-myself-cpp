#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main() {
    int n = 123321;

    string s = to_string(n);
    reverse(s.begin(), s.end());

    int r_n = atoi(s.c_str());

    cout << (r_n == n ? "YES" : "NO") << endl;


    return 0;
}