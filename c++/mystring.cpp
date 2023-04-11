#include<iostream>
using namespace std;

class MyString{
public:
    MyString() : _data(nullptr), _length(0), _capacity(0){}
    MyString(unsigned long capacity){
        _data = (char*)malloc(capacity);
        if(_data) {
            _length = 0;
            _capacity = capacity;
        }
    }

    MyString(const MyString& s){
        
    }
    ~MyString(){
        if(this)
            delete[] _data;
    }

private:
    char* _data;
    unsigned long _length;
    unsigned long _capacity;


};
int main() {
    MyString s = "123";
    MyString s2 = "cxp";
    cout << s << endl;
    s += "456";
    cout << s << endl;
    s[1] = '9';
    cout << s << endl;
    s[16] = '9';
    cout << s << endl;
    cout << s + s2 << endl;
    cout << "s = " << s << endl;
    cout << "s = " << s2 << endl;

    return 0;
}