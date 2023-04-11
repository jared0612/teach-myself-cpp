#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

class CBook{
public:
    CBook(string name, int price) : _name(name), _price(price) {}
    string name() const{return this->_name; }
    int  price() const{return this->_price; }
    virtual string Des() const = 0;

private:
    string _name;
    int _price;
};

class Ccomputer : public CBook {
public:
    Ccomputer(string name, int price, string ltype) : CBook(name,price), _mytype(ltype) {}
    string Des() const{return this->_mytype;}
private:
    string _mytype;
};

class Chistory : public CBook {
public:
    Chistory(string name, int price, string date) : CBook(name,price), _date(date) {}
    string Des() {return this->_date;}
private:
    string _date;
};

class CLib{
public:
    void addBook(CBook *book) {
        _book.push_back(book);
    }
    void listBook() {
        for (auto it :  _book) {
            cout << it->name() << " " << it->price() << " " << it->Des() << endl;
        }
        cout << endl;
    }
    void listBookOrderedByPrice() {
        sort(_book.begin(), _book.end(), [](CBook *a, CBook *b){return a->price() > b->price();});
        listBook();
    }
private:
    vector<CBook*> _book;

};

int main() {
    CLib lib;
    cout << "=================================================" << endl;
    lib.addBook(new Ccomputer("《c++ plus》", 180, "c++编程基础"));//构造对象，填充调用构造函数里面的参数。
    lib.addBook(new Ccomputer("《Python plus》", 50, "python编程基础"));
    lib.addBook(new Ccomputer("《keora history》", 10, "2011-5-5"));
    lib.addBook(new Ccomputer("《时间简史》", 20, "2020-5-12"));
    lib.listBook();
    cout << "=================================================" << endl;
    lib.listBookOrderedByPrice();

    return 0;
}