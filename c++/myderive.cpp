#include<iostream>
using namespace std;
class Animal{
public:
    void walk();
    void run();
    void jump();
    void say();

private:
    char* title;
    int age;
    float height;
    float weight;
};

class People : public Animal {
private:
    char* name;
    char* skin;
    char* gender;
    char* country;
};

class Teacher : public People{
private:
    char* level;
    char* subject;
    int tech_year;

public:
    void teach(){
        cout << this->name << "techer something"<< endl;
    }
};

int main() {

    return 0;
}