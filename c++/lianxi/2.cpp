/*************************************************************************
	> File Name: 2.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 21 Aug 2022 10:29:10 AM CST
 ************************************************************************/

#include<iostream>
#include<string>
#include<vector>
#include<deque>
#include<map>
#include<unordered_map>
#include<hash_map>
#include<stack>


using namespace std;
class People{
	string name;
	int age;

	double weight;
	double height;

	void say(string world);
	void run();
};
class A {
	public:
	char c[10];
	int aa;
};
class B{virtual void display(){}};
class C : public B{virtual void mydispaly(){}};
int main() {
	People p;
	A a;	
	B b;
	cout << "a size is " << sizeof(a) << endl;
	cout << "address is " << &A.c << endl;
	//cout << "a size is " << &a.aa << endl;
	cout << sizeof(People) << endl;
	cout << sizeof(B) << endl;
	cout << sizeof(C) << endl;
	//cout << sizeof(Vector) << endl;
	return 0;

}

