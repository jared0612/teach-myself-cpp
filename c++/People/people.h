#ifndef _PEOPLE_H_
#define _PEOPLE_H_
#include "people.h"
class People{
public:
    static People* create();//类方法要在类外定义
    static void release(People *);
    void printInfo()const;
    static int count;//类属性

private:
    People(string name, int age, double weight, double height):_name(name), age(age), 
           weight(weight), height(height){}
    ~People(){}

private:
    string  _name;
    int age;
    double weight;
    double height;
    const char *country = "china";//常量属性

};
#endif
