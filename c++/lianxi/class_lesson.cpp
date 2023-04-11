#include<iostream>
#include<string>
using namespace std;

class People {
    char name[101];//100
    int n;         //8
    double average;//8
    double fee;    //8
};

int main() {
    string s;
    cout << " size of string:" << sizeof(s) << endl;
    cout << " size of People:" << sizeof(People) << endl;

    return 0;
}