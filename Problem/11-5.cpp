/*
new, delete 연산자
new 연산자는 메모리를 할당하여 주소를 (void *)형으로 반환하면, 
컴파일러가 생성자를 호출해서 메모리 공간을 대상으로 초기화를 진행한다.
그 다음, 완성된 객체의 주소값을 포인터 형 변환에 맞는 형 변환을 한 다음 반환한다.

-> new 연산자가 반환하는 값은 operator new가 반환하는 것이 아니라, 컴파일러에 의해 적절히 형 변환이 된 값이다. 

- delete, new 연산자는 별도로 지정을 안해주어도 static함수로 간주된다.


new 의 오버로딩
void *operator new (size_t size) { . . . }
void *operator new[] (size_t size) { . . . }
    -> Point *arr = new Point[4]; 
        -> 컴파일러는 4개의 Point 객체를 만드는 데 필요한 바이트 수를 계산해서 인자로 전달하면서 함수를 호출한다.
*/

#include <iostream>
#include <cstdlib>

using namespace std;

class Point
{
    private :
        int xpos, ypos;
    public:
        Point(int x =0, int y = 0) : xpos(x), ypos(y) { }
        friend ostream &operator<<(ostream &os, const Point &pos);

        void *operator new(size_t size)
        {
            cout << "operator new : " << size << endl;
            void *adr = new char[size];// 바이트 단위의 size값을 입력받기 때문에 1바이트 자료형 char형으로 할당한다.
            return adr;
        }
        void *operator new[](size_t size)
        {
            cout <<"operator new[] : " << size << endl;
            void * adr = new char[size];
            return adr;
        }

        void operator delete(void * adr)
        {
            cout << "operator delete ()" << endl;
            delete []((char *)adr);//void * 형 대상 delete 연산이 허용안된다면, char *형 변환 후 사용한다.
        }

        void operator delete[](void *adr)
        {
            cout << "operator delete [] " << endl;
            delete []((char *)adr);
        }
};

ostream &operator<<(ostream &os, const Point &pos)
{
    os << '[' << pos.xpos << ", "<<pos.ypos << "]" <<endl;
    return os;
}

int main(void)
{
    Point *ptr = new Point(3,4);
    cout << *ptr;
    delete ptr;

    Point *adr = new Point[3];
    delete []adr;
    return 0;
}
