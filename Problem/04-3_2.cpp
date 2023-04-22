/*
명함을 의미하는 NameCard 클래스를 정의해보자. 이 클래스에는 다음 정보가 저장되어잇다.
- 성명
- 회사 이름
- 전화 번호
- 직급

단 직급 정보를 제외한 나머지는 문자열의 형태로 저장하되,
길이에 딱 맞는 메모리 공간을 할당 받는 형태로 정의한다.
직급 정보는 int형 멤버변수를 선언하여 저장하되 아래 enum 선언을 활용한다. 
enum {CLERK ,SENIOR, ASSIST, MANAGER}

아래 main함수와 예시 출력을 참조하여 NameCard 클래스를 완성해보자 .

*/
#include <iostream>
#include <cstring>
namespace COMP_POS
{
    enum{
        CLERK,
        SENIOR,
        ASSIST,
        MANAGER
    };

    void ShowPositionInfo(int pos)
    {
        switch(pos)
        {
            case(CLERK):
                std::cout << "사원" <<std::endl;
                break;
            case(SENIOR):
                std::cout << "주임" <<std::endl;
                break;
            case(ASSIST):
                std::cout << "대리" <<std::endl;
                break;
            case(MANAGER):
                std::cout << "과장" <<std::endl;
                break;
        }
    }
};

class NameCard{
private:
    char  *name;
    char *company;
    char  *phone;
    int position;

public:
    NameCard(char name[], char company[], char phone[], int position)
    {
        int len = strlen(name) + 1; 
        this->name = new char[len];
        strcpy(this->name, name);
        len = strlen(company) + 1;
        this->company = new char[len];
        strcpy(this->company, company);
        len  = strlen(phone) + 1;
        this->phone = new char[len];
        strcpy(this->phone, phone);
        this->position = position;
    }
    ~NameCard(){
        delete name;
        delete company;
        delete  phone;
    }
    void ShowNameCardInfo()
    {
        std::cout <<"이름: "  << name <<std::endl;
        std::cout <<"회사: "  << company <<std::endl;
        std::cout <<"전화번호: "  << company <<std::endl;
        std::cout << "직급: ";
        COMP_POS::ShowPositionInfo(position);
        std::cout << std::endl;
    }


};

int main()
{
    /*
    생겼던 오류: this->name과 name을 반드시 구분해주어야 한다. 
    */
    NameCard manClerk("Lee", "ABCEng", "010-1111-2222", COMP_POS::CLERK);
    NameCard manSENIOR("Hong", "OrangeEng", "010-3333-4444", COMP_POS::SENIOR);
    NameCard manAssist("Kim", "SoGoodComp", "010-5555-6666", COMP_POS::ASSIST);
    manClerk.ShowNameCardInfo();
    manSENIOR.ShowNameCardInfo();
    manAssist.ShowNameCardInfo();   
}