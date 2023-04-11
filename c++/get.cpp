/*************************************************************************
	> File Name: get.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat 01 Apr 2023 08:58:48 PM CST
 ************************************************************************/

#include<iostream>
#include<array>
#include<tuple>

using namespace std;
int main() {
    array<int, 3> myarray = {10, 20, 30};
    tuple<int, int, int> mytuple(40, 20, 30);

    auto myelement = get<2>(myarray);
    get<2>(myarray) = get<0>(myarray);
    get<0>(myarray) = myelement;

    cout << "first in myarray is; " << get<0>(myarray) << endl;
    cout << "first in mytuple is; " << get<0>(mytuple) << endl;
    return 0;
}
