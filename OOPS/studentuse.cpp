#include <iostream>
using namespace std;
#include "studentclass.h"
int main(){
    // Student s1;
    // Student* s2 = new Student;
    // s1.setAge(21);
    // s1.rollNumber=1;
    // (*s2).setAge(25);
    // s2->rollNumber = 2;
    // cout<<"Student S1: "<<endl;
    // s1.display();
    // cout<<"Student S2: "<<endl;
    // s2->display();

    //AFTER CONSTRUCTORS
    Student s1(20);//age
    Student s2(21,21019);
    Student s3("Ashutosh ");
    Student *s4 = new Student;
    Student *s5 = new Student(20);
    Student *s6 = new Student(1,-25);
    //COPY CONSTRUCTORS 
    Student s7(s3);
    Student s8(*s6);
    Student *s15(&s3);
    s15->display();
    cout<<"Hello"<<endl;
    Student *s9 = new Student(*s6);
    Student *s10 = new Student(s3);
    s3.display();
    s7.display();
    s10->display();
    s6->display();
    s8.display();
    s9->display();
    //COPY ASSIGNMENT OPERATORS
    Student s11 = s3;
    Student s12 = *s6;
    Student *s13 = &s3;
    //s13  throws error because of type mismatch you
    Student *s14= s6;
    cout<<"\n \n \n ";
    s3.display();
    s11.display();
    //s13->display();
    s6->display();
    s12.display();
    s14->display();
    cout<<"\n \n \n ";
    //Destructor automatically called for static variable 
    //need to call separately for dynamically created;
    delete s4;
     delete s5;
     delete s6;
     delete s9;
     delete s10;
     delete s14;
     cout<<"hi";


    return 0;
}