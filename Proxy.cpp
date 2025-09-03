#include <iostream>
#include <memory>
#include <string>

using namespace std;

// Subject Interface
class Image
{
public:
    virtual void display() = 0;
    virtual ~Image() { cout << "Image destructor " << endl; }
};

// Real Subject
class RealImage : public Image
{
    string fileName;

public:
    RealImage(const string &fname) : fileName(fname)
    {
        loadDisk();
    }
    void display() override
    {
        cout << "Displaying : " << fileName << endl;
    }

private:
    void loadDisk()
    {
        cout << "Loading the image from Disk" << fileName << endl;
    }
};

// Proxy
class ProxyImage : public Image
{
    string fileName;
    unique_ptr<RealImage> realImage; // leazy Initialization
public:
    ProxyImage(const string &fNamr) : fileName(fNamr)
    {
        cout << "Proxy ctor " << endl;
    }
    void display() override
    {
        cout << "Display ProxyImage " << endl;
        if (!realImage)
        {
            realImage = make_unique<RealImage>(fileName);
        }
        realImage->display();
    }
};

// client
int main()
{
    unique_ptr<Image> img1 = make_unique<ProxyImage>("Rama.png");
    unique_ptr<Image> img2 = make_unique<ProxyImage>("Jyoti.png");

    // image will be loaded only when display is called
    cout << "First call " << endl;
    img1->display(); // load from Disk

    cout << "Second time call " << endl;
    img1->display(); // load from Disk

    cout << "First time call " << endl;
    img2->display(); // load from Disk

    return 0;
}
