/*************************************************************************
	> File Name: raii.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 01 Sep 2022 06:43:23 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
class Foo {
public:

	Foo(){
		cout << "gouzao" << endl;
	}
	~Foo(){
		cout << "xigou" << endl;
	}
	void show() {
		cout << "this foo" << endl;
	}
};

template<class T> 
class SmartPtr {
	T* point;//由于是智能指针所以属性就是一个指针
public:
	SmartPtr(T* point = nullptr):point(point){}
	~SmartPtr() {
		if(point) {
			delete point;
		}
	} 
	T& operator*() {
		return *point;//返回引用；
	}
	T* operator->() {
		return point;//返回指针指向的内容；
	}
	//禁止拷贝和赋值
	SmartPtr(SmartPtr<T>&) = delete;
	SmartPtr& operator=(SmartPtr<T>&) = delete;
}; 


void print(int i) {
	cout << "function print\n";
}

class B {
	int b;
public:
	virtual void showB();
};
class C{
	int c;
public:
	virtual void showC();
};
class D:public B, public C{
	int d;
public:
	virtual void showD();
};
void (*fptr)(int) = print;
//仍然有内存对齐的要求。这里是以大类型为基准
void DerivedSizeof() {
	cout << "B size = " << sizeof(B) << endl;
	cout << "C size = " << sizeof(C) << endl;
	cout << "D size = " << sizeof(D) << endl;
}

int main() {
	SmartPtr<class Foo> ptr(new Foo());
	cout << "=========================" << endl;
	ptr->show();
	fptr(1);
	//重载一个*和->操作；
	Foo& pptr = *ptr;
	pptr.show();
	cout << "=========================" << endl;
	DerivedSizeof();
	return 0;



}