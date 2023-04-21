/*
객체 포인터의 참조관계
*/

#include <iostream>
#include <cstring>
using namespace std;

class Person
{
    public : 
        void Sleep() {cout << "Sleep"<<endl;} 
};

class Student: public Person
{
    public:
        void Study() {cout << "Study" << endl;}
};

class PartTimeStudent : public Student
{
    public : 
        void Work() { cout << "Work" << endl;}
};

class Employee
{
    private:
        char name[100];
    public:
        Employee(char *name)
        {
            strcpy(this->name, name);
        }
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
        int GetPay()const
        {
            return salary;
        }
        void ShowSalaryInfo() const
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
    void ShowSalaryInfo()
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
    
        int GetPay() const
        {
            return PermanentWorker::GetPay() + (int)(salesResult * bonusRatio);
        }
        void showSalaryInfo() const
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
                // sum+=empList[i]->ShowSalaryInfo(); 
            }   
        }
        void ShowTotalSalary() const
        {
            int sum = 0 ;
            for(int i = 0; i < empNum; i++)
            {
                // sum+=empList[i]->GetPay();
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
    {Person * ptr1 = new Student();
    Person *ptr2 = new PartTimeStudent();
    Student *ptr3 = new PartTimeStudent();
    ptr1->Sleep();
    ptr2->Sleep();
    ptr3->Study();
    delete ptr1, delete ptr2, delete ptr3;
    }
    {
        EmployeeHandler handler;

        handler.AddEmployee(new PermanentWorker("KIM", 1000));
        handler.AddEmployee(new PermanentWorker("LEE", 1500));
        handler.AddEmployee(new PermanentWorker("JUN",2000));

        handler.ShowAllSalaryInfo();
        handler.showTotalSalary();

    }
    return 0;
}