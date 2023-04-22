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
    void Init(int x, int y)
    {
        xpos = x;
        ypos = y;
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
    void Init(int xpos, int ypos, int radius)
    {
        Center.Init(xpos, ypos);
        this->radius = radius;
    }
    int getRadius()
    {
        return this->radius;
    }
    void setRadius(int r)
    {
        radius = r;
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
    void Init(int ix, int iy, int inr, int ox, int oy, int outr)
    {
        
        if(inr >= outr)
        {
            "wrong Ring.\n";
            return ;
        }
        innerCircle.Init(ix, iy, inr);
        outerCircle.Init(ox, oy, outr);
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
    Ring ring;
    ring.Init(1,1,4,2,2,9);
    ring.ShowRingInfo();
    return 0;
}