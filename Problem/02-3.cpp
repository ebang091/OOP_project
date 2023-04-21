#include <iostream>

typedef struct __Point{
    int xpos;
    int ypos;
}Point;

Point &PntAdder(const Point &p1, const Point &p2)
{
    Point *point = new Point;
    point->xpos = p1.xpos + p2.xpos;
    point->ypos = p1.ypos + p2.ypos;
    return (*point);
}

int main()
{
  /*
  임의의 두 점을 선언하여, 위 함수를 이용한 덧셈연산을 진행하는 main 함수를 정의해보자. 
  단, 구조체 Point 관련 변수의 선언은 무조건 new 연산자를 이용해서 진행해야 하며 ,
할당된 메모리 공간의 소멸도 철저해야 한다. 참고로 이 문제의 해결을 위해서는 다음 두 질문에 답을 할 수 있어 야 한다.
    • 동적할당 한 변수를 함수의 참조형 매개변수의 인자로 어떻게 전달해야 하는가?
    • 함수 내에 선언된 변수를 참조형으로 반환하려면 해당 변수는 어떻게 선언해야 하는가?
  */
    int x[3] = {3, 2, 1};
    int y[3] = {1, 2, 3};
    Point *points = new Point[3];
    for(int i = 0; i < 3 ; i++)
    {
        points[i].xpos = x[i];
        points[i].ypos = y[i];
    }
    Point &ret = PntAdder(points[0], points[1]); // (4, 4)
    std::cout << ret.xpos << " " << ret.ypos << std::endl;

    ret.xpos = 1;
    ret.ypos = 3;
    ret = PntAdder(ret, points[2]);
    std::cout << ret.xpos << " " << ret.ypos << std::endl;


    delete points;
    delete &ret;
    
}