#include <iostream>

using namespace std;

class DataProcessor
{
public:
    void process()
    {
        readData();
        processData();
        saveData();
    }

protected:
    virtual void readData() = 0;
    virtual void processData() = 0;
    virtual void saveData()
    {
        cout << "Data is saved from Base" << endl;
    }
};

class ProcessJson : public DataProcessor{
    public :
    void readData() override
    {
            cout << "Read data from Json " << endl;
}
void processData() override
{
    cout << " Process data from json " << endl;
}
}
;

class ProcessFromDB : public DataProcessor
{
public:
    void readData() override
    {
        cout << "Read data from DB " << endl;
    }
    void processData() override
    {
        cout << " Process data from DB " << endl;
    }
    void saveData() override
    {
        cout << "Save data to DB " << endl;
    }
};

int main()
{
    cout << "Main execution " << endl;
    DataProcessor *db = new ProcessFromDB;
    DataProcessor *json = new ProcessJson;
    db->process();
    json->process();
    delete db;
    delete json;
    return 0;
}