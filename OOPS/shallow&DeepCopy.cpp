#include <bits/stdc++.h>
using namespace std;
class Student{
    private:
    int age;
    char *name;
    public:
    Student(int age,char *name){
        this->age = age;
        //shallow copying 
        //in shallow copy only address gets passed on the fubnction and whenever we make change 
        //in he variable change also reflect in the passed variable in order to avoid this 
        //we can use deep copy wihich creates a copy of the variable thus hindering the change 
        //of the value of the variable in the future
        //this->name =name;
        //deep copy 
        //in this we copy the value of the variable and assign it to the this->name variable 
        //so that when we change the variable in future in the main function it does not reflect in the student classs
        //this->name is a pointer variable which w e willuse tio create an empty array and later we will copy the namke variable uin this array 
        this->name = new char[strlen(name)+1];
        //we added to the length of the char array to ensure copying of null character
        strcpy(this->name,name);
    }
    void display(){
        cout<<"Name: "<<name<<'\n'<<"Age: "<<age<<'\n';
    }
};
int main(){
    char name[] = "abcd";
    Student s1(20,name);
    s1.display();
    name[3]='e';
    Student s2(24,name);
    s2.display();
    s1.display();
 return 0;
}