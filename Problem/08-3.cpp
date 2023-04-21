/*
[포인터]
C++ 컴파일러는 포인터의 연산 가능성 여부를 판단 시 포인터의 자료형을 기준으로 판단하지, 객체의 자료형으로 판단하지 않는다.
포인터가 가리키는 객체가 유도 클래스인지 기초 클래스인지 모르니까, 잘못해서 기초클래스 객체에서 유도클래스 멤버함수를 호출할까봐
오류를 띄운다. 

[가상함수]
 - 포인터가 가리키는 형의 함수가 호출된다면, 오버라이딩의 의미가 없다. 실제 객체가 갖고 있는 오버라이딩 된 함수를 호출할 수 없다!
 - First 클래스의 MyFunc을 가상함수로 선언하자. 
    -> 오버라이딩하는 다른 유도클래스의 함수들도 모두 가상함수가 된다 .

*/
#include <iostream>
using namespace std;


class Base
{
    public:
        void BaseFunc() {cout << "Base Function." << endl;}
};

class Derived : public Base
{
    public : 
        void DerivedFunc() { cout << "Derived Function" << endl;}
};


class First
{
    public : 
        void FirstFunc() {cout << "FirstFunc" << endl;}
        void MyFunc() { cout << "My first Func"<<endl;}
};

class Second : public First
{
    public : 
        void SecondFunc() { cout << "SecondFunc" << endl;}
        void MyFunc() { cout << "My Second Func"<<endl;}
};

class Third : public Second
{
    public : 
        void ThidFunc() {cout << "ThirdFunc" << endl;}
        void MyFunc() { cout << "My Third Func"<<endl;}
};


int main()
{
   { Base *bptr = new Derived();
    //bptr->DerivedFunc(); -> 포인터는 Base, 객체자체는 Derived인데 Derived 함수가 호출이 안된다!
   }
   {
        Third *tptr= new Third();
        Second *sptr = new Second();
        First *fptr =  new Second();

        tptr->ThidFunc();
        sptr->FirstFunc();
        sptr->SecondFunc();
        fptr->FirstFunc();

        cout << endl<<endl;
        tptr->MyFunc();
        sptr->MyFunc();
        fptr->MyFunc();
        //fptr->SecondFunc();  -> 불가능!
   }
}