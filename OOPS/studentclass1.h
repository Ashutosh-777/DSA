class Student{
    public:
    int rollNumber;
    int age;
    static int totalStudents;
    Student(){
        totalStudents++;
    }
    //static functions can only use static variables 
    static int getTotalStudents(){
        return totalStudents;
    }
};
int Student:: totalStudents = 0;