#include <bits/stdc++.h>
using namespace std;
class Teacher{
    public: 
    string name;
    int age;
    Teacher(){
        cout<<"Teacher - constructor \n";
    }
    void print(){
        cout<<"Teacher class \n";
    }
};
class  Student{
    public:
    Student(){
        cout<<"Student - constructor \n";
    }
    void print(){
        cout<<"Student class\n";
    }
};
class Ta : public Student, public Teacher{
    public:
    void print(){
        cout<<"TA class \n";
    }
};
int main(){
    Ta x;
    x.print();
    x.Student:: print();
    x.Teacher:: print();
 return 0;
}