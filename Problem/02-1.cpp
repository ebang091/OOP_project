/*
[참조자 기반의 Call-by Reference 구현]
1.
    참조자를 매개변수로 받아서 받은 정수형을 
    1증가시키는 함수와  부호를 바꾸는 함수를 구현하라. 

2.
    SwapPointer(ptr1, ptr2);를 호출하면 두 포인터가 가리키는 값이 
    서로 바뀌도록 구현하라.

    <알게된 것>
    참조자 기반의 호출. Call-by-Reference: 주소값이 참조의 도구로 사용된다.
    
*/
#include <stdio.h>

void adder(int &num)
{
    num++;
}

void signer(int &num)
{
    num *= -1;
}

void SwapPointer(int *ptr1, int *ptr2)
{
    int temp  = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}

int main()
{
    int i = 1;
    int j = 2;

    adder(i);
    printf("%d\n", i);
    signer(j);
    printf("%d\n",j);

    int num1 = 5;
    int *ptr1 = &num1;
    int num2 = 10;
    int *ptr2 = &num2;

    printf("%d %d\n", *ptr1, *ptr2);
    SwapPointer(ptr1, ptr2);
    printf("%d %d\n", *ptr1, *ptr2);
    


}