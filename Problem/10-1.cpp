/*
오버로딩
commit log 
study : 10-1 - 전위연산자와 후위연산자, const 반환형에 대한 설명


++pos;

    -> 묵시적 형변환이 일어난다.
    -  pos.operator++(); -> 멤버함수로 오버로딩 된 경우
        Point::operator++(pos) : 매개변수 받는 형태로 연산자가 오버로딩된 경우


    -   operator++(pos); -> 전역함수로 오버로딩 된 경우

반환형에서의 const 선언과 const 객체
*/

class Point
{
    private:
        int xpos;
        int ypos;

    public:
        Point(int x, int y) : xpos(x), ypos(y)
        {

        }
    const Point Point::operator++(int);
};
const Point Point::operator++(int)//const Point : 함수의 반환형으로 반환되는 임시객체를 const로 선언하겠다.
// 이걸 대상으로 값을 변경시키는 함수의 호출을 허용하지 않겠다. 
//더미 인자로 후위연산자를 구분.
{
    const Point retobj(xpos, ypos);
    xpos += 1;
    ypos+= 1;
    return retobj;
}

int main()
{
    Point p1(1,3);
    Point p2(1,4);
    p1++;
}