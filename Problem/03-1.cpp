#include <iostream>

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
        std::cout << "(" << ypos << "," << xpos << "\n";
    }
};

int main(void)
{
    


}