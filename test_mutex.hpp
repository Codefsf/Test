#include <iostream>
#include <mutex>
#include <thread>
#include <memory>

using namespace std;

class DataObject
{
public:
    DataObject(const std::string& name)
    {
        content_ = new std::string(name);
    }

    ~DataObject()
    {
        std::lock_guard<std::mutex> lock(mutex_);
        delete content_;
        content_ = nullptr;
    }

    void setValue(std::string value)
    {
        std::lock_guard<std::mutex> lock(mutex_);
        *content_ = value;
        cout << "setValue:" << value << endl;
    }

private:
    mutable std::mutex  mutex_;
    std::string *content_ {nullptr};
};

void TestMutex()
{
    for(int i = 0; i < 100; i++)
    {
        DataObject *data_object = new DataObject("task-1");

    std::thread t1([&data_object]() {
        for (int i = 0; i < 5; ++i)
        {
            cout << "Task " << i << endl;
            std::this_thread::sleep_for(std::chrono::microseconds(1));
        }

        delete data_object;
        data_object = nullptr;
    });

    std::thread t2([&data_object]() {
        for (int i = 0; i < 10; ++i)
        {
            if (data_object != nullptr)
            {
                data_object->setValue(std::to_string(i));
            }

            std::this_thread::sleep_for(std::chrono::microseconds(1));
        }
    });

    t1.join();
    t2.join();
    }
    
}