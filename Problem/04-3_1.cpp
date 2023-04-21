/*
생성자와 소멸자
<생성자>
- 객체 생성시 딱 한번 호출된다.
- 생성자도 함수의 일종이니 오버로딩이 가능하다.
- 생성자도 함수의 일종이니 매개변수에 '디폴트 값'을 설정할 수 있다.
- (private 생성자를 통해 생성방법을 제한하는 경우도 간혹 있다. )

<객체의 생성과정>
1. 메모리 공간의 할당
2. 이니셜라이저를 이용한 멤버변수의 초기화
3. 생성자의 몸체 부분 실행

<멤버 이니셜라이저>
- 멤버변수로 선언된 객체의 생성자 호출에 활용된다. 
- 객체가 아닌 멤버의 초기화에도 사용된다. 
- 이니셜라이저를 사용하면 선언과 동시에 초기화가 이루어지는 형태로 바이너리 코드가 생성된다. 
- const 멤버변수도 이니셜라이저를 이용해 초기화가 가능하다. 
- (만약 참조자를 멤버변수로 갖고 있다면, 이니셜라이저를 이용해 초기화가 가능하다. )

*/
//다음 Point 클래스를 기반으로 원을 의미하는 Circle 클래스를 정의해보자. 
/*
Circle 객체는 중심좌표와 반지름의 길이 정보를 저장한다.
Circle 클래스를 기반으로한 Ring 클래스도 정의한다.

*/
#include <iostream>
class Point
{
private :
        int xpos, ypos;

public:
    Point(int x, int y)
    :xpos(x) , ypos(y)
    {

    }

    void ShowPointInfo() const{
        std::cout << "["<< xpos << " , " << ypos <<"]\n";
    };
};

class Circle{
private:
    Point Center;
    int radius;
public :
    Circle(int xpos, int ypos, int radius)
    :Center(xpos, ypos), radius(radius)
    {

    }
    int getRadius()
    {
        return this->radius;
    }
    void ShowInfo()
    {
        std::cout << "radius : " << radius<< std::endl;
        Center.ShowPointInfo();
    }

};
class Ring
{
private:
    Circle innerCircle;
    Circle outerCircle;

public:
    Ring(int ix, int iy, int inr, int ox, int oy, int outr)
    :innerCircle(ix, iy, inr), outerCircle(ox, oy, outr)
    {
        
        if(inr >= outr)
        {
            "wrong Ring.\n";
            return ;
        }
        
    }
    void ShowRingInfo()
    {
        std::cout << "Inner Circle Info...\n";
        innerCircle.ShowInfo();
        std::cout << "Outer Circle Info...\n";
        outerCircle.ShowInfo();
    }
};

int main()
{
    Ring ring(1,1,4,2,2,9);
    ring.ShowRingInfo();
    return 0;
}
