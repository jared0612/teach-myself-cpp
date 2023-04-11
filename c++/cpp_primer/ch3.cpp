/*************************************************************************
	> File Name: ch3.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 03 Mar 2023 12:18:19 PM CST
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;

// int main() {
//     string s1;
//     string s2(s1);
//     string s3 = s1;
//     string s4(10, 'a');
//     string s5 = "hello ";
//     string s6("world");
//     string s7 = s5 + s6;

//     cout << "s1  = "<< s1 << endl;
//     cout << "s2  = "<< s2 << endl;
//     cout << "s3  = "<< s3 << endl;
//     cout << "s4  = "<< s4 << endl;
//     cout << "s5  = "<< s5 << endl;
//     cout << "s6  = "<< s6 << endl;
//     cout << "s7  = "<< s7 << endl;
//     return 0;
// }

int main() {
    string s1;
    cin >> s1;
    cout << "s1 = " << s1 << endl;
    string s2;
    getline(cin, s2);
    cout << "s2 = " << s2 << endl;
    cout << "s1 is empty?\n" << (s1.empty()? "yes" : "no") << endl;
    cout << "The size of s1 is: " << s1.size() << endl;
    cout << "The size of s2 is: " << s2.size() << endl;
    
    string s3 = s1 + s2;
    cout << "s3 = " << s3 << endl;

    cout << "s2 = s1?: " << (s1 == s2 ? "yes" : "no")<< endl;
    cout << "s2 != s1?: " << (s1 != s2 ? "yes" : "no")<< endl;
    cout << "s1 < s2?: " << (s1 < s2 ? "yes" : "no")<< endl;
    cout << "s1 <= s2?: " << (s1 <= s2 ? "yes" : "no")<< endl;
    cout << "s1 > s2?: " << (s1 > s2 ? "yes" : "no")<< endl;
    cout << "s1 >= s2?: " << (s1 >= s2 ? "yes" : "no")<< endl;

    string ss = "hello world!";
    cout << "ss = " << ss << endl;
    for (auto &it : ss) {
        it = 'x';
    }
    cout << "after changement ss  = " << ss << endl;

    return 0;
}
