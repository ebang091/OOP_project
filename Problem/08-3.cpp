/*
[포인터]
C++ 컴파일러는 포인터의 연산 가능성 여부를 판단 시 포인터의 자료형을 기준으로 판단하지, 객체의 자료형으로 판단하지 않는다.
포인터가 가리키는 객체가 유도 클래스인지 기초 클래스인지 모르니까, 잘못해서 기초클래스 객체에서 유도클래스 멤버함수를 호출할까봐
오류를 띄운다. 

[가상함수]
 - 포인터가 가리키는 형의 함수가 호출된다면, 오버라이딩의 의미가 없다. 실제 객체가 갖고 있는 오버라이딩 된 함수를 호출할 수 없다!
 - First 클래스의 MyFunc을 가상함수로 선언하자. 
    -> 오버라이딩하는 다른 유도클래스의 함수들도 모두 가상함수가 된다 .

- 가상함수의 경우엔 함수가 호출되었을 때 포인터에 해당하는 함수가 아니라, 실제 객체의 함수를 호출한다!!
: 이러한 문제 해결로 인해 08-2의 문제를 해결했다. 


- [가상 소멸자]
08-4에 내용이 있다.
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
        virtual void MyFunc() { cout << "My first Func"<<endl;}
        virtual void test() {cout << "First TEST" << endl;}
};

class Second : public First
{
    public : 
        void SecondFunc() { cout << "SecondFunc" << endl;}
        virtual void MyFunc() { cout << "My Second Func"<<endl;}
        virtual void test() {cout << "Second TEST" << endl;}
};

class Third : public Second
{
    public : 
        void ThidFunc() {cout << "ThirdFunc" << endl;}
        virtual void MyFunc() { cout << "My Third Func"<<endl;}
};


int main()
{
   
   {
    
     Base *bptr = new Derived();
    //bptr->DerivedFunc(); -> 포인터는 Base, 객체자체는 Derived인데 Derived 함수가 호출이 안된다!
   }
   {
        Third *tptr= new Third();
        Second *sptr = new Second();
        First *fptr =  new Second();

        //포인터의 클래스형에서 유도클래스에 해당하는 함수는 호출이 불가하다.
        tptr->ThidFunc();//Third
        sptr->FirstFunc();//First
        sptr->SecondFunc();//second
        fptr->FirstFunc();//First

        //오버라이딩 된 경우, 포인터형에 해당하는 함수가 호출 된다. (포인터형클래스 이상에서 가장 하위로 오버라이딩된)
        //단 가상함수인 경우엔 객체에 해당하는 함수가 호출된다.
        cout << endl<<endl;
        tptr->MyFunc();//Third
        sptr->MyFunc();//Second
        fptr->MyFunc();//원래는 first가 출력되었는데, 가상함수로 바꾸고 나니 second가 출력된다!
        //fptr->SecondFunc();  -> 불가능!



        cout << endl<<endl;
        tptr->test();//가상함수이고 third에는 오버라이딩안되어있어서 Second 호출
        sptr->test();//객체가 Second이므로 Second 
        fptr->test();//객체가 Second이므로 Second 
        //fptr->SecondFunc();  -> 불가능!
   }
}