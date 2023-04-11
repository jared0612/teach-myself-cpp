#include<iostream>
#include<queue>
#include<stack>
using namespace std;
class A{public: virtual void cc(){cout << "付类方法\n";}};
class B : public A {
    public:void cc() {cout << "子类方法、\n";}
};
int main() { 
    stack<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    cout << q.size() << endl;
    while(!q.empty()) {
        cout << q.top() << "|" << q.size() << endl;
        q.pop();
    }
    cout << "Hello world!" << endl;
    int pointer = 12;
    int& rptr = pointer;
    int* ptr = &rptr;
    cout << "ptr = " << *ptr << endl;
    A* p;
    p = new B();
    p->cc();

    return 0;
}
