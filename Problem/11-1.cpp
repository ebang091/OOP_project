/*
복사 대입 연산자 
: 오버로딩 해야하는 이유
- 동적할당 하는 경우, 포인터를 가리키는 얕은 복사를 하게 되면 이미 소멸된 주소를 가리키고 있을 수도 있고(잘못된 메모리 접근), 
원래 들고 있던 주소를 놓칠 수도 있고(메모리 누수), 같은 포인터를 두번 해제하려고 할 수 있다. (중복 해제)


11-2
: 유도 클래스에서의 복사 대입 연산자
- 기초 클래스의 복사 대입연산자에 대한 책임이 없으므로, 따로 지정 해줘야 한다. (그래야 기초클래스의 복사연산자가 호출되어서 private 멤버 변수등도 알맞게 초기화 된다.)
*/

#include <iostream>
#include <cstring>
using namespace std;

class Person
{
private:
    char *name;
    int age;
public:
    Person(char *myname, int myage)
    {
        int len = strlen(myname) + 1;
        name= new char [len];
        strcpy(this->name, myname);
        age = myage;

       
    }
    void ShowPersonInfo() const
    {
        cout << "이름: " << name << endl;
        cout << "나이: " << age << endl;
    }
    ~Person()
    {
        cout << "called destructor" << endl;
        
    }
    Person &operator=(const Person& ref)
    {
        delete []name;//메모리 누수를 막기 위한 메모리 해제 연산.
        int len = strlen(ref.name) + 1;
        name = new char[len];
        strcpy(name, ref.name);
        age = ref.age;
        return *this;
    }
};

int main()
{
    Person person1("ebang", 26);
    Person person2("ee", 24);

    person2 = person1;
    person1.ShowPersonInfo();
    person2.ShowPersonInfo(); 
    //출력 후에 소멸자가 한번만 호출되는 문제가 생긴다. (단 컴파일러에 따라 정상이기도.)
    //person2 에서 소멸되고 person1에서 name을 한번 더 소멸하는 문제가 생긴다. 

     /*
        발생할 수 있는 문제점 : 
        - 원래 들고 있던 name을 가리키던 포인터가 복사하는 객체의
        name을 가리키기 때문에 메모리 누수가 난다.

        - name 을 가리키는 포인터가 2개가 되므로, 
        나중에 소멸 시에 중복으로 할당 해제하는 문제가 발생할 수 있다. 
    */
   
   /*
   다음과 같이 복사 생성자를 정의해야 한다. 

   */
  


    return 0;

}