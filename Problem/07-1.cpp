/*
상속의 이해

*/
class Base {
    private: 
        int num1;
    protected: 
        int num2;
    public:
        int num3;
};

class Derived1 : public Base
{
    //접근 불가  :
        //int num1;
    //protected:
        //int num2;
    //public://
        ///int num3;
};

class Derived2 : protected Base
{
    //접근 불가  :
        //int num1;
    //protected:
        //int num2;
    //protected://
        ///int num3;
};

class Derived3 : private Base
{
    //접근 불가  :
        //int num1;
    //private:
        //int num2;
    //private://
        ///int num3;
};