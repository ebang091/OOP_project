/*

const int num = 12;
이를 가리키는 포인터와 이 포인터를 참조하는 참조자를 선언 후,
둘을 이용해 num 값을 출력해보자.

<알게 된 것>
- 함수의 매개변수 형태는 참조자인데, 함수를 호출 당시에 인자로 넣을 때는 기본 자료형이라면? 
        
        void callbyreference(int &ref){ ...}
        int val = 2;
        callbyreference(val); -> ref라는 참조자가 생긴다.


 

*/


#include <iostream>

int &RefFunction1(int &ref)
{
    ref += 1;
    return ref;
}

int RefFunction2(int &ref)
{
    ref += 1;
    return ref;
}

int main()
{
    {

        std::cout << "test 1\n ";
        int num1 = 1;
        int &num2 = RefFunction1(num1);
        

        /*
            int &ref = num1;
            num2 = ref; 
            와 동일한 동작. (단 ref는 RefFunction1 함수 내에서 임시로 생겼다가 사라진다. )
        */
        num1++;
        num2++;//이 때 num1의 값도 증가한다.!
        std::cout << num1<<"\n";
        std::cout << num2<<"\n";
    }
    {
        std::cout << " \n\ntest 2\n";
        int num1 = 1;
        int num2 = RefFunction1(num1);//참조자를 반환해도 int로 받으면 반환 참조자는 의미가 없어진다.

        /*
        int &ref = num1;
        int num2 = ref; 와 같은 동작이 일어난 것이다. 
        */

        

        num1++;
        num2+=100;
        std::cout << num1<<"\n";
        std::cout << num2<<"\n";
    }
    {
        std::cout << "\n\ntest 3\n ";
        int num = 1;
        int *numPtr = &num;
        int &numRef = *numPtr;
        std::cout << *numPtr << " " << numRef << "\n";
        
        
        // 아래 함수와 변수 자료형의 차이점
        int num1 = 10;
        
        int num2 = RefFunction1(num1);
        int &num3 = RefFunction1(num1);

        int num4 = RefFunction2(num1);
        //int &num2 = RefFunction2(num1);//(아예 안됨)
    }
    {

    //- const 참조자의 특징
    const int num = 1;
    //int &ref = num; //불가능
    const int &ref = num;//가능

    }
    {
        //- 잘못된 참조의 반환

        /*
        int& RefReturn(int num)
        {
            num += 1;
            return num;
        }
        */
        //-> 정수형을 받고서 참조자로 반환하면, 함수내 지역변수의 참조자를 반환하게 되므로
        //반환하자마자 소멸되므로 문제가 된다.
    }

}
/*
answer : 4 . 4

*/