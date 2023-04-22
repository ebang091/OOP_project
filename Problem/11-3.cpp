/*
이니셜라이저에 따른 복사대입연산자의 호출
*/

#include <iostream>
using namespace std;

class AAA
{
    private:
        int num;

    public : 
        AAA(int n = 0) : num(n)
        {
            cout << "AAA(int n = 0)" << endl;
        }
        AAA(const AAA& ref) : num(ref.num)
        {
            cout << "AAA(const AAA& ref)" << endl;
        }
        AAA &operator=(const AAA& ref)
        {
            num = ref.num;
            cout << "operator=(const AAA& ref)" << endl;
            return *this;
        }
};

class BBB
{
private:
    AAA mem;
public:
    BBB(const AAA& ref) : mem(ref) {}
};

class CCC
{
private:
    AAA mem;
public:
    CCC(const AAA& ref) {mem = ref;}
};

int main()
{

    AAA obj1(11); //AAA(int n = 0) 출력
    BBB obj2(obj1); // AAA(const AAA& ref) 출력 : 이니셜라이저를 이용하면 선언과 동시에 초기화가 된다. 

    CCC obj3(obj1);
    /*
    AAA(int n = 0) 
    operator=(const AAA& ref)  둘 다 출력 
    -> {}내에서 = 연산을 하면 선언, 초기화가 따로 일어난다. 

    */
}