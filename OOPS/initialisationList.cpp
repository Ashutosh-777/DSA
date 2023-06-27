#include <bits/stdc++.h>
using namespace std;
class Student{
    public:
    int age;
    const int rollNumber;
    int &x;
    Student(int rollNumber,int age) : rollNumber(rollNumber) , age(age) ,x(this->age){
        
    }
    void display(){
        cout<<"Age: "<<age<<"\nRollNumber: "<<rollNumber<<endl;
    }
};
int main(){
 Student s1(8009,21);
 s1.display();
 return 0;
}