#include <iostream>
/*
  [구조체에 대한 new & delete 연산]
  구조체 복습

  [new & delete]
*/
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

class Simple
{
    public:
      Simple()
      {
        std::cout << "hi~\n";
      }
};

int main()
{
  {
    //new 와  malloc의 차이점
    std::cout << "case 1 : ";
    Simple *sp1 = new Simple;

    std::cout << "case 2 : ";
    Simple *sp2 = (Simple *)malloc(sizeof(Simple)*1);

    std::cout << std::endl << "end of main" << std::endl;
    delete sp1;
    delete sp2;
    /*
    출력결과를 보면 new할 때는 생성자가 호출되는 반면 malloc시에는 출력문이 없다 .
    */
  }
  {
      //포인터를 사용하지 않아도 힙에 접근할 수 있다
      int *ptr = new int;
      int &ref = *ptr;
      ref = 20;
      std::cout << *ptr << std::endl;

  }



  {/*
  임의의 두 점을 선언하여, 위 함수를 이용한 덧셈연산을 진행하는 main 함수를 정의해보자. 
  단, 구조체 Point 관련 변수의 선언은 무조건 new 연산자를 이용해서 진행해야 하며 ,
할당된 메모리 공간의 소멸도 철저해야 한다. 참고로 이 문제의 해결을 위해서는 다음 두 질문에 답을 할 수 있어 야 한다.
    • 동적할당 한 변수를 함수의 참조형 매개변수의 인자로 어떻게 전달해야 하는가?
    [매개변수의 인자를 참조형으로 선언하면 된다. ]
    • 함수 내에 선언된 변수를 참조형으로 반환하려면 해당 변수는 어떻게 선언해야 하는가?
    [지역변수로 만들면 바로 소멸되기 때문에, 동적할당해서 반환하되 참조형으로 반환하도록 한다.]
  */
    int x[3] = {3, 2, 1};
    int y[3] = {1, 2, 3};
    Point *points = new Point[3];
    //Point배열을 선언

    //Point의 좌표를 선언 : 위에 선언해둔 x, y 배열 사용
    for(int i = 0; i < 3 ; i++)
    {
        points[i].xpos = x[i];
        points[i].ypos = y[i];
    }
    //함수 수행
    Point &ret = PntAdder(points[0], points[1]); // (3,1) + (2,2)
    std::cout << "xpos : " << ret.xpos << " ypos: " << ret.ypos << std::endl;

    ret.xpos = 1;
    ret.ypos = 3;
    ret = PntAdder(ret, points[2]); // (1,3) + (1,3)
    std::cout << "xpos : " << ret.xpos << " ypos: " << ret.ypos << std::endl;


    delete []points;
    delete &ret;
  }

    
    
}