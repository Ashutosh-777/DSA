#include<iostream>
using namespace std;
class Vehicle{
    private:
    int numTyres;
    protected:
    int maxSpeed;
    public:
    int color;
    Vehicle(){
        cout<<"Default Constructor of Vehicle is called"<<endl;
    }
    Vehicle(int z){
        maxSpeed =z;
        cout<<"Vehicle --> parametrised Constructor"<<endl;
    }
    ~Vehicle(){
        cout<<"Destructor of Vehicle"<<endl;
    }
};
class Car: private Vehicle{
    public:
    int numGears;
    Car():Vehicle(2) {
        cout<<"Default Constructor of Car is called"<<endl;
    }
    ~Car(){
        cout<<"Destructor of Car"<<endl;
    }
};
int main(){
    //Vehicle v;
    Car c;
    c.numGears =1;
}