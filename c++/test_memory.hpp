#include <iostream>
#include <memory>
#include <mutex>
#include <thread>
#include <chrono>

using namespace std;

class TestMutex
{
public:
    TestMutex(const std::string& name) : 
        name_(name)
    {
        cout << "TestMutex()" << endl;
    }
    
    ~TestMutex()
    {
        cout << "~TestMutex()" << endl;
    }

    int64_t getValue() const
    {
        std::lock_guard<std::mutex> lock(mutex_);
        return value_;
    }

    void setValue(int64_t value)
    {
        std::lock_guard<std::mutex> lock(mutex_);
        value_ = value;
        cout << name_ << " = " << "setValue:" << std::to_string(value) << endl;
    }

private:
    std::string     name_ {nullptr};
    int64_t         value_ {0};
    mutable std::mutex mutex_;
};

void TestMemory()
{
    // TestMutex test_mutex("task-1");

    // std::thread t1([&test_mutex]() {
    //     for (int i = 0; i < 100; ++i)
    //     {
    //         test_mutex.setValue(i);

    //         std::this_thread::sleep_for(std::chrono::milliseconds(100));
    //     }
    // });

    // std::thread t2([&test_mutex]() {
    //     for (int i = 0; i < 100; ++i)
    //     {
    //         test_mutex.setValue(i);

    //         std::this_thread::sleep_for(std::chrono::milliseconds(100));
    //     }
    // });

    // t1.join();
    // t2.join();
}

