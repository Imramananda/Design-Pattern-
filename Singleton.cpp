#include <iostream>
using namespace std;
class Singleton
{
    Singleton()
    {
        cout << "Privet constructor " << endl;
    }
    ~Singleton()
    {
        cout << "Privet Destructor " << endl;
    }

public:
    static Singleton &getInstance()
    {
        static Singleton obj; // function local static variable it insure for thread safe
        return obj;
    }
    void shoeInstanc()
    {
        cout << "Single instance : " << this << endl;
    }
    Singleton(const Singleton &) = delete;
    Singleton &operator=(const Singleton &) = delete;
};

int main()
{
    Singleton& obj = Singleton::getInstance();
    Singleton& obj2 = Singleton::getInstance();
    obj.shoeInstanc();
    obj2.shoeInstanc();
    if(&obj == &obj2)
    cout<<"Both r same "<<endl;
    else
    cout<<"Both r not same "<<endl;
    return 0;
}