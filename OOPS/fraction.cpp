#include <iostream>
using namespace std;
class Fraction{
    private:
    int numerator;
    int denominator;
    public:
    Fraction(int numerator,int denominator){
        this->numerator=numerator;
        this->denominator=denominator;
    }
    void print(){
        cout<<numerator<<"/"<<denominator<<endl;
    }
    //need only one argument because when we use f1.add address of f1 is automatically passed to the classs

    // Fraction add(Fraction f1,Fraction f2){
    //     int LCM = f1.denominator * f2.denominator ;
    //     int newNumerator = f1.numerator * f2 .denominator + f2.numerator * f2.denominator ;
    //     Fraction ans;
    //     ans.numerator = newNumerator;
    //     ans.denominator = LCM;
    //     return ans;
    // }

    //we will keep function type void and we will store the answer in the same variable f1;
    void simplify(){
        int gcd = 1;
        int j =min(numerator,denominator);
        for(int i=1;i<=j;i++){
            if(numerator%i==0&&denominator%i==0) gcd=i;
        }
        numerator/=gcd;
        denominator/=gcd;
    }
    //passing by constant reference in order to avoid calling copy constructors and changing its value
    const Fraction add(Fraction const &f2){
        int LCM = denominator * f2.denominator;
        int newNumerator = numerator*f2.denominator + f2.numerator*denominator;
        Fraction fnew(newNumerator,LCM);
        fnew.simplify();
        return fnew;
    }
     Fraction operator+(Fraction const &f2){
        int LCM = denominator * f2.denominator;
        int newNumerator = numerator*f2.denominator + f2.numerator*denominator;
        Fraction fnew(newNumerator,LCM);
        fnew.simplify();
        return fnew;
    }
    const Fraction multiply(Fraction const &f2){
        int x = numerator * f2.numerator;
        int y = denominator * f2.denominator;
        Fraction fnew(x,y);
        fnew.simplify();
        return fnew;
    }
    const Fraction operator*(Fraction const &f2){
        int x = numerator * f2.numerator;
        int y = denominator * f2.denominator;
        Fraction fnew(x,y);
        fnew.simplify();
        return fnew;
    }
    const bool operator== (Fraction const &f2){
        return f2.numerator==this->numerator&&f2.denominator==this->denominator;
    }
     Fraction& operator++ (){
        numerator+=denominator;
        simplify();
        return *this;
    }
    Fraction& operator+=(Fraction const& f2){
        numerator = numerator*f2.denominator + f2.numerator*denominator;
        denominator *= f2.denominator;
        simplify();
        return *this;
    }
};
int main(){
    Fraction f1(10,2);
    Fraction f2(5,1);
    cout<<"f1: ";
    f1.print();
    (f1+=f2)+=(f2)+=f1;
    f2.print();
    f1.print();
    // Fraction f1(10,2);
    // Fraction f2(15,4);
    // Fraction f3(12,6);
    // Fraction f4 = (f1+f2)+f1;
    // Fraction f5 = ++(++(++f1));
    // f1.print();
    // f5.print();
    // f4.print();
    // ++f3;
    // Fraction f4 = f1*f2;
    // f4.print();
    // if(f3==f4){
    //     cout<<"Equal"<<endl;
    // }
    // else{
    //     f3.print();
    //     f4.print();
    //     cout<<"NOT Equal"<<endl;
    // }
    return 0;
}