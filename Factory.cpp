#include <iostream>
#include <memory>

using namespace std;

class Shape
{
public:
    virtual void draw() = 0;
    virtual ~Shape() = default;
};

class Circle : public Shape
{
public:
    void draw() override
    {
        cout << "Circle" << endl;
    }
};

class Square : public Shape
{
public:
    void draw() override
    {
        cout << "Square" << endl;
    }
};

class ShapeFactory
{
public:
    unique_ptr<Shape> createShape(const string &type)
    {
        if (type == "Circle")
            return make_unique<Circle>();
        if (type == "Square")
            return make_unique<Square>();
        return nullptr;
    }
};

int main()
{
    ShapeFactory obj;
    unique_ptr<Shape> obj1 = obj.createShape("Circle");
    obj1->draw();

    unique_ptr<Shape> obj2 = obj.createShape("Square");
    obj2->draw();

    // Add at the end of main():
    cout << "Press Enter to continue...";
    cin.get();
    return 0;
}