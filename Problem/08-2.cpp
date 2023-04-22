/*
다형성과 가상 함수
commit log
study: 08-2 fix - [가상함수]08-3에 기반하여 가상함수를 도입후, 컨트롤러에서 포인터형과 다른 유도클래스의 함수를 호출할 수 있도록 수정
study: 08-2 fix - [추상클래스][순수가상함수]Employee 클래스는 객체가 생성될 필요가 없는 기반 클래스이므로, 순수 가상함수를 도입하여 추상 클래스로 만들어 활용한다.
    (겪은 에러 : const를 실수로 안붙여서 제대로 오버라이딩 안되었다.)

*/

#include <iostream>
#include <cstring>
using namespace std;

class Employee
{
    private:
        char name[100];
    public:
        Employee(char *name)
        {
            strcpy(this->name, name);
        }
        virtual int GetPay() const = 0;
        virtual void ShowSalaryInfo() const = 0;

        void ShowYourName() const
        {
            cout << "name : " << name << endl;
        }
};

class PermanentWorker : public Employee
{
    private:
        int salary;
    public : 
        PermanentWorker(char *name, int money)
        :Employee(name), salary(money)
        {}
        virtual int GetPay()const
        {
            return salary;
        }
        virtual void ShowSalaryInfo() const
        {
            ShowYourName();
            cout << "salary: "<<GetPay()<<endl<<endl;
        }
};

class TemporaryWorker : public Employee
{
private:
    int workTime;
    int payPerHour;
public:
    TemporaryWorker(char *name, int pay)
    :Employee(name), workTime(0), payPerHour(pay)
    {}

    void AddWorkTime(int time)
    {
        workTime += time;
    }
    int GetPay() const
    {
        return workTime * payPerHour;
    }
    void ShowSalaryInfo() const
    {
        ShowYourName();
        cout <<"salary:"<< GetPay() << endl<<endl;
    }

};

class SalesWorker : public PermanentWorker
{
    private:
        int salesResult; //월 판매 실적
        double bonusRatio; //상여금 비율
    public:
        SalesWorker(char *name, int pay, double bonus)
        :PermanentWorker(name, pay), salesResult(0), bonusRatio(bonus)
        {}
    
        virtual int GetPay() const
        {
            return PermanentWorker::GetPay() + (int)(salesResult * bonusRatio);
        }
        void AddSalesResult(int result)
        {
            salesResult += result;
        }
        virtual void showSalaryInfo() const
        {
            ShowYourName();
            cout << "salary: " << GetPay() << endl<<endl;
        }
};

class EmployeeHandler
{
    private:
        Employee *empList[50];
        int empNum;
    public:
        EmployeeHandler() : empNum(0)
        { }
        void AddEmployee(Employee *emp)
        {
            empList[empNum++] = emp;
        }
        void ShowAllSalaryInfo() const
        {
            for(int i = 0; i < empNum; i++)
            {
                empList[i]->ShowSalaryInfo(); 
            }   
        }
        void ShowTotalSalary() const
        {
            int sum = 0 ;
            for(int i = 0; i < empNum; i++)
            {
                sum+=empList[i]->GetPay();
            }
            cout << "salary sum:"<<sum<<endl;
        }
        ~EmployeeHandler()
        {
            for(int i  = 0 ; i < empNum; i++)
                delete empList[i];
        }
};



int main()
 {
      {  //컨트롤러인 EmployeeHandler의 유연함
        //포인터로 갖고 있을 때의 문제점 : 포인터형에 해당하는 클래스의 함수만 호출이 가능하다.
        EmployeeHandler handler;

        handler.AddEmployee(new PermanentWorker("KIM", 1000));
        handler.AddEmployee(new PermanentWorker("LEE", 1500));
        handler.AddEmployee(new PermanentWorker("JUN",2000));

        // handler.ShowAllSalaryInfo();
        //handler.showTotalSalary(); -> 문제가 있음.


        //임시직등록
        TemporaryWorker *alba = new TemporaryWorker("Jung", 700);
        alba->AddWorkTime(5); //일한 시간 등록
        handler.AddEmployee(alba);

        //영업직 등록
        SalesWorker *seller = new SalesWorker("Hong", 1000, 0.1);
        seller->AddSalesResult(7000);
        seller->showSalaryInfo();

        //이번 달에 지불해야 할 급여의 정보
        handler.ShowAllSalaryInfo();

        //이번달에 지불할 급여 총량
        handler.ShowTotalSalary();
    }
    {

    }
}
