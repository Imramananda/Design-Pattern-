#include <iostream>
#include <vector>
using namespace std;
class Observer
{
public:
    virtual void update(int val) = 0;
};

class Subject
{
    int value;
    vector<Observer *> vec;

public:
    void attach(Observer *obs)
    {
        vec.push_back(obs);
    }
    void setValue(int v)
    {
        value = v;
        notify();
    }
    void notify()
    {
        for (int i = 0; i < vec.size(); ++i)
        {
            vec[i]->update(value);
        }
    }
};

class DivideObserver : public Observer
{
    int m_div;

public:
    DivideObserver(Subject *model, int div)
    {
        model->attach(this);
        m_div = div;
    }
    void update(int v) override
    {
        cout << v << " div " << m_div << " is " << v / m_div << endl;
    }
};

class ModuloObserver : public Observer
{
    int m_mod;

public:
    ModuloObserver(Subject *model, int div)
    {
        model->attach(this);
        m_mod = div;
    }
    void update(int v) override
    {
        cout << v << " mod " << m_mod << " is " << v % m_mod << endl;
    }
};

int main()
{
    cout << "Main execution " << endl;
    Subject sub;
    DivideObserver d1(&sub, 4);
    DivideObserver d2(&sub, 3);
    ModuloObserver m1(&sub, 4);
    ModuloObserver m2(&sub, 3);
    sub.setValue(15);
    return 0;
}