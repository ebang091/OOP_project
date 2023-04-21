/*
[가상 소멸자]
: 기초 클래스의 포인터가 유도 클래스 객체를 들고있을 때, 소멸자가 기초클래스 소멸자만 호출되는 문제. 
상속을 하면 소멸자는 가상 소멸자로 선언하여 동적할당되었을 때도(포인터로 들고 있을 때도 ) 소멸자가 유도클래스까지 
잘 호출될 수 있도록 한다.!

commit log
study: 08-4 problem - First 클래스 포인터가 유도클래스 객체 Second를 동적할당하여 갖고 있을 때, First 소멸자만 호출이 되어서 실제로는 Second 클래스의 strTwo가 해제가 안되고 메모리 누수가 난다.
*/
#include <iostream>
#include <cstring>

using namespace std;
class First
{
    private:
        char * strOne;
    public:
        First(char *str)
        {
            strOne = new char[strlen(str) + 1];
            strcpy(this->strOne, str);
            cout << "First : " << str <<endl;
        }
        ~First()
        {
            cout << "~First()" <<endl;
            delete []strOne;
        }
};

class Second: public First
{
    private: 
        char *strTwo;

    public : 
        Second(char *str1, char *str2):First(str1)
        {
            strTwo = new char[strlen(str2) + 1];
            strcpy(strTwo, str2);
            cout << "Second : " << str1 << " " << str2<<endl;
        }
        ~Second()
        {
            cout << "~Second()"<< endl;
            delete []strTwo;
        }
};

int main()
{
    {First *f = new First("hi i'm first");
    Second *s  = new Second("hi i'm first", "hi i'm second");

    delete f;
    delete s;
    }

    {
        First *f = new Second("HI I'm FIRST", "HI I'M SECOND");
        delete f;
        //소멸자가 First에 대해서만 호출되는 문제 발생!

    }
    
    
}