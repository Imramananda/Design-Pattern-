#include <iostream>
#include <memory>
#include <string>
using namespace std;
class Employee
{
public:
    virtual void getSalary() = 0;
    virtual void work() = 0;
};
class Developer : public Employee
{
public:
    void getSalary() override
    {
        cout << "Dev salary is 100000 " << endl;
    }
    void work() override
    {
        cout << "Developer do devlopment " << endl;
    }
};
class Tester : public Employee
{
public:
    void getSalary() override
    {
        cout << "Tester salary is 50000 " << endl;
    }
    void work() override
    {
        cout << "Tester do tester " << endl;
    }
};
class Factory
{
public:
    unique_ptr<Employee> getEmplyoyee(const string &s)
    {
        cout << "Get Employee function call " << endl;
        if (s == "DEV")
        {
            cout << "Get Developer " << endl;
            return make_unique<Developer>();
        }
        if (s == "TESTER")
        {
            cout << "Get Tester " << endl;
            return make_unique<Tester>();
        }
        return nullptr;
    }
};

int main()
{
    cout << " Main function " << endl;
    Factory obj;
    unique_ptr<Employee> emp1 = obj.getEmplyoyee("DEV");
    emp1->getSalary();
    emp1->work();
    unique_ptr<Employee> emp2 = obj.getEmplyoyee("TESTER");
    emp2->getSalary();
    emp2->work();
    return 0;
}
