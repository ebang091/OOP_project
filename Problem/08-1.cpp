/*
객체 포인터의 참조관계
*/

#include <iostream>
#include <cstring>
using namespace std;

class Person
{
    public : 
        void Sleep() {cout << "Sleep"<<endl;} 
};

class Student: public Person
{
    public:
        void Study() {cout << "Study" << endl;}
};

class PartTimeStudent : public Student
{
    public : 
        void Work() { cout << "Work" << endl;}
};

int main()
{
    {
        //포인터는 해당하는 클래스의 유도 클래스에 해당하는 객체까지 가리킬 수 있다.
        Person * ptr1 = new Student();
        Person *ptr2 = new PartTimeStudent();
        Student *ptr3 = new PartTimeStudent();
        ptr1->Sleep();
        ptr2->Sleep();
        ptr3->Study();
        delete ptr1, delete ptr2, delete ptr3;
    }
   
    return 0;
}