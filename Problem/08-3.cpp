/*
가상함수
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
}

int main()
{
    Base *bptr = new Derived();
    //bptr->DerivedFunc(); -> 포인터는 Base, 객체자체는 Derived인데 Derived 함수가 호출이 안된다!
}