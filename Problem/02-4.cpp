#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
/*
    문제 1.
    strlen
    strcat
    strcpy
    strcmp
    위 표준함수를 호출하는 예제를 만들되, C++의 헤더를 선언해서 만들어보자.
    참고로 함수들은 <string.h>에 선언되어 있다.

    문제2. 다음 세 함수를 이용해서 0이상 100미만의 난수를 총 5개 생성하는 예제를 만들어라.
    c++의 헤더를 선언해서 작성하되 C언어의 경우 time 함수는 <time.h> 에 선언되어 있고 
    rand함수와 srand함수는 <stdlib.h> 에 선언되어있다.


    <알아야할 것>
    C에서 .h 헤더파일은 h를 떼고 c를 붙인 이름의 헤더파일로 c++에서 불러와서 사용할 수 있다.
    c++의 문법에 맞게 오버로딩된 함수들이 있으므로 c++에 맞는 헤더파일을 불러와서 사용하는 것이 더 좋다.

*/
using namespace std;
int main()
{
    char str[10] = "hello";
    char *str2 = "world";
    char *str3 = new char[10];

    cout << strlen(str) << endl;
    strcpy(str3, str);
    cout << str3 << "\n";
    cout << strcmp(str, str3) << endl;
    strcat(str, str2);
    cout << str << "\n";
    cout << strcmp(str, str2) <<endl;

/////////////////////////////////////////
int num;
    srand((unsigned int) time(NULL));
    for(int i = 0; i < 5; i++)
    {
        num = rand() % 100 ;
        
        cout << num << endl;
    }

    
}