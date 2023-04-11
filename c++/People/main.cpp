#include<iostream>
#include<string>
#include "people.h"

using namespace std;

int main() {
    //People p;
    cout << People::count << endl;
    People* p1 = People::create();//说明是一个静态函数
    cout << People::count << endl;
    (*p1).printInfo();
    //delete p1;
    People::release(p1);
    cout << People::count << endl;
    
    return 0;
}
