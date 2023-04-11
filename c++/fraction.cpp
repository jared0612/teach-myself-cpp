#include<iostream>
using namespace std;

class Fraction {
public:
    Fraction(int x, int y):_x(x), _y(y) {};

    Fraction& yuefen();
    Fraction operator+(const Fraction &f) {
        return Fraction(this->_x * f._y + this->_y * f._x, this->_y * f._y).yuefen();
    }
    Fraction operator*(const Fraction &f) {
        return Fraction(this->_x * f._x, this->_y * f._y).yuefen();
    }
    Fraction operator-() {
        this->yuefen();
        return Fraction(-this->_x, this->_y);
    }
    Fraction& operator+=(const Fraction& f) {
        *this = *this + f;
        return *this;
    }
    Fraction& operator*=(const Fraction& f) {
        *this = *this * f;
        return *this;
    }
    bool operator==(const Fraction& f) {
        return this->_x * f._y == this->_y * f._x;
    }
    bool operator<(const Fraction& f) {
        return this->_y * f._x > this->_x * f._y;
    }
    bool operator>(const Fraction& f) {
        return this->_y * f._x < this->_x * f._y;
    }

    friend ostream& operator<<(ostream&, const Fraction&);
    

private:
    int _x, _y;

};
Fraction& Fraction::yuefen(){
    int n = 1;
    int x = this->_x;
    for (int i = 1; i <= x; ++i) {
        if (x % i == 0 && this->_y % i == 0) {
            n = i;
        }
    }
    this->_x  = x / n;
    this->_y  = this->_y / n;
    return *this;
}
ostream& operator<<(ostream& os, const Fraction& f) {
        os << f._x << "/" << f._y;
        return os;
    }

//要求需要约分
int main() {
    Fraction f1(100000, 23);
    Fraction f2(100000, 24);
    //Fraction f2(1, 4);
    cout << f1 + f2 << endl;
    cout << f1 * f2 << endl;
    cout << -f1 << endl;
    //f1 += f2;
    //f1 *= f2;
    if (f1 == f2) {
        cout << "equalin\n";
    } else if(f1 < f2) {
        cout << "smaller\n";
    } else {
        cout << "bigger\n";
    }
    return 0;
}
