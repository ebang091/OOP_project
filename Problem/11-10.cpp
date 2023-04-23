/*
임시 객체로의 자동 형 변환과 형 변환 연산자 (Conversion Operator)

임시 객체의 생성을 통해 대입연산이 진행되는 예제
-> A형 객체가 와야할 위치에 B형 객체(데이터)가 있을 경우, B형을 받아 A형을 생성하는 
생성자 호출을 통해서 A형 임시객체를 생성한다 .

반대로 함수호출의 대상이 A형 객체가 아니라 B형 데이터일 때도, 형변환이 될 수 있다.
(operator int 참고)

*/
#include <iostream>
using namespace std;

class Number
{
private: 
    int num;
public:
    Number(const int n = 0) : num(n)
    {
        cout << "Number(int n = 0)" << endl;
    }
    Number &operator=(const Number &ref)
    {
        cout << "operator=()" << endl;
        num = ref.num;
        return *this;
    }

    operator int()
    {
        return num;
    }
    void ShowNumber(){cout << num << endl;}

};

int main(void)
{
    Number num; 
    num  = 30; //이렇게 해도 호출되는 이유? 
    /*
    생성자로 30을 넣은 임시객체가 만들어 진후 복사대입연산자가 호출된다.

    num = Number(30);  //임시객체의 생성
    num.operator=(Number(30)); //임시객체를 대상으로 하는 대입 연산자의 호출
    */
    num.ShowNumber();

    Number num2 = num + 20;
    num2.ShowNumber();
    return 0;
}