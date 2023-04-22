/*
: 유도 클래스에서의 복사 대입 연산자
- 기초 클래스의 복사 대입연산자에 대한 책임이 없으므로, 따로 지정 해줘야 한다. (그래야 기초클래스의 복사연산자가 호출되어서 private 멤버 변수등도 알맞게 초기화 된다.)

유도 클래스에서 복사대입연산자가 오버로딩되어있다면, 기초 클래스의 복사대입연산자가 호출되지 않으므로
기초클래스의 복사대입연산자를 호출해야하는 의무가 있다. 

*/

#include <iostream>
using namespace std;

class First{
private:
    int num1, num2;

public:
    First(int n1= 0, int n2 = 0) :num1(n1), num2(n2)
    {

    }
    void ShowData() {cout << num1 <<", " << num2 << endl;}
    First &operator=(const First &ref)
    {
        cout << "First &operator=()" << endl;
        num1 = ref.num1;
        num2 = ref.num2;
        return *this;
    }
};

class Second : public First
{
private:
    int num3;
    int num4;

public:
    Second(int n1, int n2, int n3, int n4) : First(n1, n2) , num3(n3) , num4(n4)
    {

    }
    void ShowData()
    {
        First::ShowData();
        cout << num3 << " ," << num4 << endl;
    }

    
    Second &operator=(const Second &ref)
    {
        cout << "Second &operator=()" <<endl;
        num3 = ref.num3;
        num4 = ref.num4;
        return *this;
    }
    
    


};

int main()
{
    
    Second ssrc(1,2,3,4);
    
    ssrc.ShowData();
    Second scpy(0,0,0,0);
    scpy = ssrc;
    scpy.ShowData();

    //Second에 복사대입연산자 오버로딩을 안해두면 First 클래스의 복사대입연산자가 호출되고 
    //정상적으로 값이 대입되어있다. 
    /*

    //Second 복사대입연산자를 오버로딩할 때는 기초 클래스의 복사대입연산자도 호출해서 사용해야 한다. 
    Second &operator=(const Second &ref)
    {
        cout << "Second &operator=()" <<endl;
        First::operator=(ref);
        num3 = ref.num3;
        num4 = ref.num4;
        return *this;
    }
    */
}