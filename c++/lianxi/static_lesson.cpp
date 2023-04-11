#include<iostream>
static long money = 100000;
class People{

public:
    People():name("cxp"), age(27){}

private:
    char name[40];
    long age;
    static long money;

};
using namespace std;
int main() {
    People p;
    cout << sizeof(p) << endl;
    return 0;
}