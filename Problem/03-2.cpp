#include <iostream>

/*[클래스의 정의]
클래스를 구성하는 변수 = 멤버 변수
클래스를 구성하는 함수 = 멤버함수 

계산기 기능의 Calculator 클래스를 정의해 보자. 
기본적으로 지니는 기능은 덧셈, 뺄셈, 곱셈 그리고 나눗셈이며
연산을 할 때마다 어떠한 연산을 몇번 수행했는지 기록되어야 한다.
아래의 main 함수와 실행 예에 부합하는 Calculator 클래스를 정의하자.


*/

class Calculator
{
    private:
        int opCountAdd;
        int opCountSub;
        int opCountMul;
        int opCountDiv;
    public:
        void Init();
        float Add(float a, float b);
        float Min(float a, float b);
        float Div(float a, float b);
        float Mul(float a, float b);
        void ShowOpCount();
};

void Calculator::Init()
{
    opCountAdd = 0;
    opCountSub = 0;
    opCountMul = 0;
    opCountDiv = 0;
}
float Calculator::Add(float a, float b)
{
    opCountAdd++;
    return a + b;
}

float Calculator::Min(float a, float b)
{
    opCountSub++;
    return a - b;
}

float Calculator::Div(float a, float b)
{
    if(b == 0)
    {
        std::cout << "cannot divide by zero.\n";
        return -1;
    }
    opCountDiv++;
    return a/ b;

}
float Calculator::Mul(float a, float b)
{
    opCountMul++;
    return a * b;
}

void Calculator::ShowOpCount()
{
    std::cout << "덧셈: "<< opCountAdd << " 뺄셈:" << opCountSub << " 곱셈:" << opCountMul <<" 나눗셈:" << opCountDiv << std::endl;
}

int main()
{
    Calculator cal;

    cal.Init();
    std::cout << "3.2 + 2.4 = " << cal.Add(3.2, 2.4) << std::endl;
    std::cout << "3.2 / 1/7 = " << cal.Div(3.5, 1.7) << std::endl;
    std::cout << "2.2 - 1.5 = " << cal.Min(2.2, 1.5) << std::endl;
    std::cout << "4.9 / 1.2 = " << cal.Div(4.9, 1.2) << std::endl;

    cal.ShowOpCount();
    return 0;

    /*
        실행 예
        3.2 + 2.4 = 5.6
        3.5 / 1.7 = 2.05882
        2.2 - 1.5 = 0.7
        4.9 / 1.4 = 4.08333
        덧셈: 1 뺄셈:1 곱셈:0 나눗셈:2
    */
}