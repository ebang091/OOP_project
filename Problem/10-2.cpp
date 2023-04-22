/*
교환법칙이 성립하는 오버로딩
*/

#include <iostream>
using namespace std;

class Point
{
private:
    int xpos;
    int ypos;

public:
    Point(int x = 0, int y = 0): xpos(x), ypos(y)
    {

    }
    void ShowPosition()
    {
        cout << "[" << xpos << ", " << ypos <<  "]" <<endl;
    }
    Point operator*(int times)
    {
        Point pos(xpos * times, ypos * times);
        return pos;
    }
    friend Point operator*(int times, Point &ref); //friend 선언을 하면 선언당한 친구는 나에게 접근을 바로 할 수 있다.
};

Point operator*(int times, Point &ref)//교환법칙을 위한 것.
{
    Point p(ref*times);
    return p;

}


int main()
{
    Point pos(1,2);
    (pos * 3).ShowPosition();
    (3*pos).ShowPosition();

}