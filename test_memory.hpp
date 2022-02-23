#include <iostream>
#include <memory>
#include <mutex>

using namespace std;

class TestMutex
{
public:
    TestMutex()
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
    }

private:
    int64_t value_ {0};
    mutable std::mutex mutex_;
};

void TestMemory()
{
    TestMutex test_mutex;
    test_mutex.setValue(1);
    std::cout << test_mutex.getValue() << std::endl;
}

