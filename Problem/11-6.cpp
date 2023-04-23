/*
포인터 연산자 오버로딩
*와 ->
둘다 피연산자가 하나인 단항 연산자의 형태로 오버로딩 된다.
*/

#include <iostream>
using namespace std;

class Number
{
    private:
        int num;
    public:
        Number(int n) : num(n) { }
        void ShowData() {cout << num << endl;}

        Number *(operator->)()
        {
            return this;
        }

        Number &operator*()
        {
            return *this;
        }
};

int main(void)
{
    Number num(20);
    num.ShowData();

    (*num) = 30; // (num.operator*()) = 30;
    num->ShowData();//(num.operator->()).ShowData();  -> 연산자가 반환하는 건 주소이니, 주소 -> ShowData()로 해석한다.
    (*num).ShowData();//(num.operator*()).ShowData();
    return 0;
}