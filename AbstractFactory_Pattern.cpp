#include <iostream>
#include <string>
#include <memory>
using namespace std;

class IButton
{
public:
    virtual void buttonPress() = 0;
};

class ITextBox
{
public:
    virtual void editTextBox() = 0;
};

class WinButton : public IButton
{
public:
    void buttonPress() override
    {
        cout << "Windows buttton pressed " << endl;
    }
};

class MacButton : public IButton
{
public:
    void buttonPress() override
    {
        cout << "Mac buttton pressed " << endl;
    }
};

class WinTextBox : public ITextBox
{
public:
    void editTextBox() override
    {
        cout << "Windows text box in edit " << endl;
    }
};

class MacTextBox : public ITextBox
{
public:
    void editTextBox() override
    {
        cout << "Mac text box in edit " << endl;
    }
};

class Ifactory
{
public:
    virtual unique_ptr<IButton> createButton() = 0;
    virtual unique_ptr<ITextBox> createTextBox() = 0;
};

class WindowsFactory : public Ifactory
{
public:
    unique_ptr<IButton> createButton() override
    {
        cout << "Creating WIndow Factory " << endl;
        return make_unique<WinButton>();
    }
    unique_ptr<ITextBox> createTextBox() override
    {
        cout << "Creating WIndow Factory " << endl;
        return make_unique<WinTextBox>();
    }
};
class MacFactory : public Ifactory
{
public:
    unique_ptr<IButton> createButton() override
    {
        cout << "Creating WIN Factory " << endl;
        return make_unique<MacButton>();
    }
    unique_ptr<ITextBox> createTextBox() override
    {
        cout << "Creating MAC Factory " << endl;
        return make_unique<MacTextBox>();
    }
};

class AbstarctFactory
{
public:
    static unique_ptr<Ifactory> createFactory(const string &osType)
    {
        cout << "Abstarct Factory for ";
        if (osType == "WIN")
        {
            cout << "Wnn " << endl;
            return make_unique<WindowsFactory>();
        }
        else if (osType == "MAC")
        {
            cout << "MAC " << endl;
            return make_unique<MacFactory>();
        }
        return nullptr;
    }
};

int main()
{
    string osType;
    cout << "Enter the OS Type " << endl;
    cin >> osType;
    // unique_ptr<Ifactory> macfactory = AbstarctFactory::createFactory("MAC");
    // unique_ptr<Ifactory> winfactory = AbstarctFactory::createFactory("WIN");
    unique_ptr<Ifactory> factory = AbstarctFactory::createFactory(osType);
    unique_ptr<IButton> button = factory->createButton();
    button->buttonPress();
    // unique_ptr<IButton> button = macfactory->createButton();
    // button->buttonPress();
    // unique_ptr<ITextBox> text = macfactory->createTextBox();
    // text->editTextBox();
    // unique_ptr<IButton> buttonw = winfactory->createButton();
    // buttonw->buttonPress();
    // unique_ptr<ITextBox> textw = winfactory->createTextBox();
    // textw->editTextBox();
    return 0;
}
