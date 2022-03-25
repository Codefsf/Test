#include <iostream>

void TestSegmentfault()
{
    int* a = new int(1);

    std::cout << "a = " << *a << std::endl;

    int* b = a;

    while (true)
    {
        int c = a - b;
        std::cout << "a = " << *a << " " << c << std::endl;
    }
}