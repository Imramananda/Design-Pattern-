#include <iostream>
#include <string>
#include <memory>

using namespace std;

class Laptop
{
public:
    void setRam(const int &r)
    {
        RAM = r;
        cout << "RAM is " << RAM << " GB " << endl;
    }
    void setBrand(const string &r)
    {
        brand = r;
        cout << "Brand is " << brand << "  " << endl;
    }
    void setCore(const int &c)
    {
        numCore = c;
        cout << "Number of core is " << numCore << "  " << endl;
    }
    void display()
    {
        cout << "Ram core and brand done " << endl;
    }

private:
    int RAM;
    string brand;
    int numCore;
};

class Builder
{
public:
    virtual void buildRAM() = 0;
    virtual void buildBrand() = 0;
    virtual void buildCore() = 0;
};
class DevLaptop : public Builder
{
public:
    void buildRAM() override
    {
        cout << "RAM BUilding 16 GB" << endl;
        lap.setRam(16);
    }
    void buildBrand() override
    {
        cout << "Brand BUilding 16 GB" << endl;
        lap.setBrand("HP");
    }
    void buildCore() override
    {
        cout << "Core BUilding 16 GB" << endl;
        lap.setCore(8);
    }

private:
    Laptop lap;
};

// similar to above we can have gaimgi latop with diff confition
//  class GameLaptop : public Builder
//  {
//      public:
//      void buildRAM()
//      {
//          cout<<"RAM BUilding 16 GB"<<endl;
//          lap.setRam(16);
//      }
//       void buildBrand()
//      {
//          cout<<"Brand BUilding 16 GB"<<endl;
//          lap.setBrand("HP")
//      }
//       void buildCore()
//      {
//          cout<<"Core BUilding 16 GB"<<endl;
//          lap.setCore(8);
//      }
//      private:
//      Laptop lap;
//  };

class Director
{
public:
    void Contruct(Builder& obj)
    {
        obj.buildCore();
        obj.buildRAM();
        obj.buildBrand();
    }
};

int main()
{
    cout << "CLient code starting " << endl;
    Director dir;
    DevLaptop l;
    dir.Contruct(l);
    return 0;
}
