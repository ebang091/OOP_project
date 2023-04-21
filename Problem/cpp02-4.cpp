#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

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