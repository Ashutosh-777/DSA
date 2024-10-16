#include <bits/stdc++.h>
using namespace std;
class Student{
    public:
    string name;
    double* cgpa;
    Student(string name,double cgpa){
        this->name = name;
        this->cgpa = new double;
        *(this->cgpa) = cgpa;
    }
    void getInfo(){
        cout<<"Name: "<<name<<endl;
        cout<<"CGPA: "<<*cgpa<<endl;
    }
};
int main(){
    Student s1("Ashutosh",8.07);
    s1.getInfo();
    Student s2(s1);
    s2.name = "Ghosty69";
    *(s2.cgpa) = 9.8;
    s2.getInfo();
    s1.getInfo();
 return 0;
}