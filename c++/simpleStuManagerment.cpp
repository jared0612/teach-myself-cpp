/*************************************************************************
	> File Name: studentmanager.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 28 Feb 2023 12:43:12 PM CST
 ************************************************************************/


#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Student{
public:
    string name;
    int age;
    string gender;
    string course;
    double score;
};

// 定义一个学生管理系统类
class StudentSystem{
public:
    // 添加学生
    void addStudent(Student stu){
        students.push_back(stu);
    }
    // 修改学生信息
    void modifyStudent(Student stu){
        for(int i=0; i<students.size(); i++){
            if(stu.name == students[i].name){
                students[i] = stu;
            }
        }
    }
    // 删除学生
    void deleteStudent(string name){
        for(int i=0; i<students.size(); i++){
            if(name == students[i].name){
                students.erase(students.begin()+i);
            }
        }
    }
    // 查询学生
    void queryStudent(string name){
        for(int i=0; i<students.size(); i++){
            if(name == students[i].name){
                cout << "Name:" << students[i].name << endl;
                cout << "Age:" << students[i].age << endl;
                cout << "Gender:" << students[i].gender << endl;
                cout << "Course:" << students[i].course << endl;
                cout << "Score:" << students[i].score << endl;
            }
        }
    }

private:
    vector<Student> students;
};

int main(){
    StudentSystem system;
    Student stu1, stu2;
    stu1.name = "Tom";
    stu1.age = 18;
    stu1.gender = "male";
    stu1.course = "C++";
    stu1.score = 90;
    system.addStudent(stu1);

    stu2.name = "Mary";
    stu2.age = 20;
    stu2.gender = "female";
    stu2.course = "Java";
    stu2.score = 95;
    system.addStudent(stu2);

    system.queryStudent("Tom");
    system.deleteStudent("Tom");
    system.queryStudent("Tom");

    return 0;
}

