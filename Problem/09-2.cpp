/*
다중 상속에 대한 이해

다중상속으로만 해결가능한 문제는 없을 뿐더러 다중상속은 득보다 실이 많다는 의견도 존재하기에,
이해를 하고 넘어가는 정도로 할 것이다. 


- 다중상속의 모호성
: 다중상속의 대상 클래스들 중에 동일한 이름의 멤버가 존재하는 경우, 어떻게 접근할 것인가?
: 다중상속되는 대상 클래스가 서로 같은 클래스를 상속하고 있다면(다이아몬드 상속), 기초 클래스의 생성자가 여러번 호출될 수 있다.
(굳이 사용하려면 ::을 이용해서 지정해서 사용할 수 있지만, 보통은 그 중 한 함수혹은 변수만 필요한 상황일 것이다.)
이럴 때 가상상속을 사용한다.

- 가상상속

*/

#include <iostream>
using namespace std;
class Base
{
public:
    Base(){ cout << "Base Constructor" << endl;}
    void SimpleFunc() { cout << "BaseOne" << endl;}

};

class MiddleDerivedOne: virtual public Base
{
public: 
    MiddleDerivedOne() : Base()
    {
        cout<< "MiddleDerivedOne Constuctor" << endl;
    }
    void MiddleFunctionOne()
    {
        SimpleFunc();
        cout<< "MiddleDrivedOne" << endl;
    }
};

class MiddleDerivedTwo : virtual public Base
{
public: 
    MiddleDerivedTwo() : Base()
    {
        cout << "MiddleDerivedTwo constructor" << endl;
    }
    void MiddleFunctionTwo()
    {
        SimpleFunc();
        cout << "MiddleDerivedTwo" << endl;
    }
};

class LastDerived : public  MiddleDerivedOne, public MiddleDerivedTwo
{
public:
    LastDerived(): MiddleDerivedOne(), MiddleDerivedTwo()
    {
        cout << "LastDerived constructor" << endl;
    }
    void complexFunction()
    {
        MiddleFunctionOne();
        MiddleFunctionTwo();
        SimpleFunc();      
    }
};

int main()
{
    LastDerived f;
    f.complexFunction();
}
