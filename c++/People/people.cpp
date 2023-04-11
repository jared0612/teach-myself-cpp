#include "people.h"
int People::count = 0;

People* People::create() {
    count++;
    return (People *) new People("lihua",21,175,55);
}

void People::release(People *p) {
    --People::count;
    delete p;
}

void People::printInfo()  const{
    cout << "--------------------------" << endl;
    cout << this->_name << ":" << this->age << " years old | " << 
         this->height << "kg &" << this->weight << " cm in " << this->country << endl;
    cout << "--------------------------" << endl;
}
