#include <iostream>
/*
struct Point{
    int xpos;
    int ypos;
};
를 기반으로 다음함수를 정의하고자 한다. 
void MovePos(int x, int y); // 점의 좌표 이동
void AddPoint(const Point &pos); //점의 좌표 증가
void ShowPosition(); // 현재 x, y 좌표정보 출력

그리고 아래 main문에 작성된대로 실행하도록, 함수를 정의하라.


*/
struct Point{
    int xpos;
    int ypos;

    void MovePos(int x, int y)
    {
        xpos += x;
        ypos += y;
    }

    void AddPoint(Point point)
    {
        xpos += point.xpos;
        ypos += point.ypos;
    }

    void ShowPosition(){
        std::cout << "(" << xpos << "," << ypos << ")\n";
    }
};

int main(void)
{
    Point pos1 = {12, 4};
    Point pos2 = {20, 30};

    pos1.MovePos(-7, 10);
    pos1.ShowPosition();//(5, 14) 출력

    pos1.AddPoint(pos2);
    pos1.ShowPosition(); //(25, 44) 출력

    return 0;
}