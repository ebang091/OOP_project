/*
[복사 생성자]
Simple sim1(15, 20);
Simple sim2 = sim1; //Simple sim2(sim1);

- explicit 키워드로 위의 묵시적 형변환을 막을 수 있음. 
<문제>
- 깊은 복사를 위한 복사 생성자의 정의. -> 04-3_2.cpp를 복사생성자를 도입하자!
*/

class Simple
{
private:
    int num1;
    int num2;

public:
    Simple(int num1, int num2)
    :num1(num1), num2(num2)
    {

    };
    /*
    Simple(const Simple &copy)//copy는 바꿀리 없으므로 const로 받는다.
    :num1(copy.num1), num2(copy.num2)
    {

    };

    */
    explicit Simple(const Simple &copy)//copy는 바꿀리 없으므로 const로 받는다.
    {   
            //empty!
    }
    //explicit 키워드로 묵시적인 형변환을 막는다. 
    //Simple sim2 = sim1; 코드를 Simple sim2(sim1); 꼴로 묵시적 형변환이 일어나면서 복사생성자가 호출되는데,
    // explicit 키워드를 통해 복사생성자가 묵시적으로 호출되는 것을 막을 수 있다. 
    //explicit 키워드는 코드의 명확성을 위해 자주 사용한다. 
    ~Simple()
    {

    };
};

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
    NameCard(const NameCard& copy)
    {
        if(this != &copy)
        {

            //깊은 복사
            int len = strlen(copy.name) + 1; 
            this->name = new char[len];
            strcpy(this->name, copy.name);
            len = strlen(copy.company) + 1;
            this->company = new char[len];
            strcpy(this->company, copy.company);
            len  = strlen(copy.phone) + 1;
            this->phone = new char[len];
            strcpy(this->phone, copy.phone);
            //깊은 복사 끝
            this->position = position;
        }
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

    //Simple sim1(15, 20);
    //Simple sim2 = sim1; //Simple sim2(sim1); 과 같은 코드이다. 
    
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