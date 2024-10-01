class Student{
    public:
    int rollNumber;
    string name="default ";
    private:
    int age;
    public:
    //default constructors
    Student(){
        cout<<"Default Constructor Called '\n'";
    }
    //parametrized constructors
    Student(string name){
        this->name = name;
        cout<<"Default Constructor Called '\n'";
    }
    Student(int age){
        this->age = age;
        cout<<"Default Constructor Called '\n'";
    }
    Student(int rollNumber,int age){
        this->rollNumber =rollNumber;
        cout<<"Default Constructor Called '\n'";
        this->age =age;
    }
    void display(){
        cout<<"NAME: "<<name<<"AGE: "<<age<<" ROLL NUMBER : "<<rollNumber<<endl;
    }
    void setAge(int age){
        if(age<=0)
        return;
        this->age = age;
    }
    int getAge(){
        return age;
    }
    ~Student(){

        cout<<"Destructor called \n ";
    }
};