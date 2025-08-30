#include <iostream>
#include <memory>
#include <vector>
#include <list>

using namespace std;

class Resource
{
public:
    Resource() : value(0) {}

    void reset()
    {
        cout << "Reset the resouce" << endl;
        value = 0;
    }
    void setResourceValue(int d)
    {
        cout << "Set the resource" << endl;
        value = d;
    }

    int getResourceValue()
    {
        cout << "Set the resource" << value << endl;
        return value;
    }

private:
    int value;
};

class ObjectPool
{
public:
    ObjectPool(ObjectPool &obj) = delete;
    ObjectPool &operator=(ObjectPool &obj) = delete;
    static ObjectPool *getInstance()
    {
        cout << "ObjejctPull Instance " << endl;
        static ObjectPool instance;
        return &instance;
    }
    Resource *getResource()
    {
        if (resources.empty())
        {
            cout << "Create resource " << endl;
            return new Resource;
        }
        else
        {
            cout << "Reusing from list" << endl;
            Resource *resource = resources.front();
            resources.pop_front();
            return resource;
        }
    }
    void returnResource(Resource *resource)
    {
        cout << "Reset the values " << endl;
        resource->reset();
        resources.push_back(resource);
    }

private:
    ObjectPool() {};
    list<Resource *> resources;
};

int main()
{
    cout << "Main function exxecute" << endl;
    ObjectPool *obj = ObjectPool::getInstance();

    Resource *one;
    Resource *two;

    one = obj->getResource();
    one->setResourceValue(100);
    cout << "Print " << one->getResourceValue() << endl;

    two = obj->getResource();
    two->setResourceValue(200);
    cout << "Print " << two->getResourceValue() << endl;

    cout << "Returning " << endl;
    obj->returnResource(one);

    Resource *three;
    three = obj->getResource();
    three->setResourceValue(300);
    cout << "Print " << three->getResourceValue() << endl;

    return 0;
}