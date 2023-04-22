/*
복사 생성자가 호출되는 시점 
- 기존에 생성된 객체를 이용해서 새로운 객체를 초기화하는 경우
- Call - value - by 방식의 함수호출 과정에서 객체를 인자로 전달하는 경우
- 객체를 반환하되, 참조형으로 반환하지 않는 경우
*/

#include <iostream>

class Temporary
{
private: 
        int num;
public:
    Temporary(int n) : num(n)
    {
        std::cout << "create obj : " << num << std::endl;
    }
    ~Temporary()
    {
        std::cout << "destroy obj : " << num << std::endl;
    }
    void ShowTempInfo()
    {
        std::cout << "My num is " << num << std::endl;
    }


}; 
int main(){

    Temporary(100);
    std::cout << "*****************after make!\n" << std::endl;

    Temporary(200).ShowTempInfo();//임시객체가 만들어져서 반환되고 그걸로 멤버함수를 호출할 수 있다.
    std::cout << "*****************after make!\n" << std::endl;

    const Temporary &ref = Temporary(300);//참조자로 받은 후 계속 접근할 가능성이 있기 때문에 가장 마지막에 소멸된다. 
    //(위의 경우와 소멸자 호출 시점이 다르다.)
    std::cout << "*****************after make!\n" << std::endl;


}

