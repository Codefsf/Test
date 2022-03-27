#include <iostream>
#include <memory>
#include <mutex>
#include <string>

using namespace std;

class SharedObject
{
public:
    SharedObject(const std::string& name) : name_(name)
    {
        std::cout << "SharedObject()" << std::endl;
    }

    ~SharedObject()
    {
        std::cout << "~SharedObject()" << std::endl;
    }

    void setValue(const std::string& value)
    {
        std::lock_guard<std::mutex> lock(mutex_);
        value_ = value;
        std::cout << name_ << " = " << "setValue:" << value << std::endl;
    }

    std::string getValue() const
    {
        std::lock_guard<std::mutex> lock(mutex_);
        return value_;
    }

    void addCount()
    {
        std::cout << "addCount()" << std::to_string(++count_) << std::endl;
    }

private:
    std::string name_;
    std::string value_;
    int count_{0};
    mutable std::mutex mutex_;
};


void TestSharedPtr()
{
    std::shared_ptr<SharedObject> shared_object(new SharedObject("task-1"));

    std::thread t1([&shared_object]() {
        for (int i = 0; i < 50; ++i)
        {
            shared_object->addCount();
            std::this_thread::sleep_for(std::chrono::microseconds(1));
        }
    });

    std::thread t2([&shared_object]() {
        for (int i = 0; i < 50; ++i)
        {
            shared_object->addCount();
            std::this_thread::sleep_for(std::chrono::microseconds(1));
        }
    });

    t1.join();
    t2.join();
}